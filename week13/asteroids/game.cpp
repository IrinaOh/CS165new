#include "game.h"
#include "flyingObject.h"

//These are needed for the getClosestDistance function...
#include <limits>
#include <algorithm>

using namespace std;


Game::Game(Point tl, Point br) : topLeft(tl), bottomRight(br)
{ 
	initializeVariables();
	
	initializeRocks();
	
	ship = new Ship(Point());
}


void Game::initializeRocks()
{
	int i = 0;
	while (i < 5)
	{
		Point p = Point(random(-200, 200), random(-200, 200));
		//cout << "Point " << i << " : " << p << endl;
		if ((p.getX() < -25 || p.getX() < 25) && (p.getY() < -25 || p.getY() > 25))
		{
			asteroids.push_back(new BigRock(p));
			i++;
		}
	}
}

void Game::initializeVariables()
{
	score = 0;
	lives = AMOUNT_OF_LIVES;
	newWave = false;
}

//you will find this function helpful...

/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/
float Game :: getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const {
   // find the maximum distance traveled
   float dMax = max(abs(obj1.getVelocity().getDx()), abs(obj1.getVelocity().getDy()));
   dMax = max(dMax, abs(obj2.getVelocity().getDx()));
   dMax = max(dMax, abs(obj2.getVelocity().getDy()));
   dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.
   
   float distMin = std::numeric_limits<float>::max();
   for (float i = 0.0; i <= dMax; i++)
   {
      Point point1(obj1.getPoint().getX() + (obj1.getVelocity().getDx() * i / dMax),
                     obj1.getPoint().getY() + (obj1.getVelocity().getDy() * i / dMax));
      Point point2(obj2.getPoint().getX() + (obj2.getVelocity().getDx() * i / dMax),
                     obj2.getPoint().getY() + (obj2.getVelocity().getDy() * i / dMax));
      
      float xDiff = point1.getX() - point2.getX();
      float yDiff = point1.getY() - point2.getY();
      
      float distSquared = (xDiff * xDiff) +(yDiff * yDiff);
      
      distMin = min(distMin, distSquared);
   }
   
   return sqrt(distMin);
}

void Game::advance()
{
	if (!ship->isAlive() && !newWave)
	{
		ship->reset(Point());
		lives--;
	}
	else if (ship->isAlive() && lives > 0 && !newWave)
	{
		advanceAsteroids();
		advanceBullets();
		advanceShip();

		cleanUpZombies();
		handleCollisions();
	}

	if (asteroids.size() <= 0)
		newWave = true;

}

void Game::advanceBullets()
{
	for (vector<Bullet*> ::iterator it = bullets.begin(); it != bullets.end(); it++)
	{
		(*it)->advance();
	}
}

void Game::advanceAsteroids()
{
	for (vector<Rock*> ::iterator it = asteroids.begin(); it != asteroids.end(); it++)
	{
		(*it)->advance();
	}
}


void Game::advanceShip()
{
	ship->advance();
}

//Clean Up Zombies
void Game::cleanUpZombies()
{
	cleanUpShip();
	cleanUpBullets(false);
	cleanUpRocks(false);
}

//Clean Up Ship
void Game::cleanUpShip()
{
	if (ship != NULL && !ship->isAlive())
	{
		ship = NULL;
	}
}


//Clean Up Bullets
void Game::cleanUpBullets(bool deleteAll)
{
   vector<Bullet*>::iterator bulletIt = bullets.begin();
   while (bulletIt != bullets.end())
	{
		Bullet* bullet = *bulletIt;

		if (!bullet->isAlive() || deleteAll)
		{
			delete (*bulletIt);
			bulletIt = bullets.erase(bulletIt);
		}
		else
		{
			bulletIt++;
		}
	}
}

//Clean Up rocks
void Game::cleanUpRocks(bool deleteAll)
{
	vector<Rock*>::iterator rockIt = asteroids.begin();
	while (rockIt != asteroids.end())
	{
		Rock * rock = *rockIt;

		if (!rock->isAlive() || deleteAll)
		{
			delete (*rockIt);
			rockIt = asteroids.erase(rockIt);
		}
		else
		{
			rockIt++;
		}
	}
}

void Game::handleCollisions()
{
	handleBulletCollisions();
	handleShipCollisions();
}

// Bullet Collisions
void Game::handleBulletCollisions()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		Bullet * bullet = bullets[i];

		if (bullet->isAlive())
		{
			for (int j = 0; j < asteroids.size(); j++)
			{
				Rock * rock = asteroids[j];
				if (rock->isAlive())
				{
					float rockRange = CLOSE_ENOUGH + rock->getSize();

					if (fabs(getClosestDistance(*bullet, *rock)) < rockRange || bullet->getPoint().isClose(rock->getPoint(), rockRange))
					{
						vector<Rock*> newRocks = rock->destory();
						asteroids.insert(asteroids.end(), newRocks.begin(), newRocks.end());
						score += rock->getScore();
						rock->kill();
						bullet->kill();
					}
				}
			}
		}
	}
}

// ship collisions
void Game::handleShipCollisions()
{
	for (int i = 0; i < asteroids.size(); i++)
	{
		Rock * rock = asteroids[i];
		if (rock->isAlive())
		{
			float rockRange = CLOSE_ENOUGH + rock->getSize();

			if (fabs(getClosestDistance(*ship, *rock)) < rockRange || ship->getPoint().isClose(rock->getPoint(), rockRange))
			{
				vector<Rock*> newRocks = rock->destory();
				asteroids.insert(asteroids.end(), newRocks.begin(), newRocks.end());
				rock->kill();
				ship->kill();
			}
		}
	}
}

void Game::handleInput(const Interface & ui)
{
	if (ship->isAlive() && lives > 0 && !newWave)
	{
		if (ui.isUp())
		{
			ship->applyThrust(true);
		}
		if (ui.isDown())
		{
			ship->applyThrust(false);
		}
		if (ui.isLeft())
		{
			ship->applyRotation(false);
		}

		if (ui.isRight())
		{
			ship->applyRotation(true);
		}

		if (ui.isSpace())
		{
			Bullet * tempBul = new Bullet();
			tempBul->fire(ship->getPoint(), ship->getAngle(), ship->getVelocity());

			bullets.push_back(tempBul);
		}
	}
	else
	{
		if (ui.isSpace())
		{
			this->reset();
		}
	}

}

void Game::draw(const Interface & ui)
{
	drawAsteroids();
	drawShip();
	drawBullets();
	drawScore();
	drawLives();

	if (lives < 1)
	{
		drawText(Point(-50, 25), "You Crashed");
		drawText(Point(-45, -25), "Game Over");
		drawText(Point(-65, -50), "Press Space to Reset.");
	}
	if (newWave)
	{
		drawText(Point(-40, 25), "You Won!");
		drawText(Point(-65, -25), "Press Space to Reset.");
	}


}

void Game::drawBullets()
{
	for (vector<Bullet*> ::iterator it = bullets.begin(); it != bullets.end(); it++)
	{
		(*it)->draw();
	}
}


void Game::drawAsteroids()
{
	for (vector<Rock*> ::iterator it = asteroids.begin(); it != asteroids.end(); it++)
	{
		(*it)->draw();
	}
}

void Game::drawShip()
{
	ship->draw();
}

void Game::drawScore()
{
	Point scoreLocation, scoreTextLocation;
	scoreLocation.setX(topLeft.getX() + 50);
	scoreLocation.setY(topLeft.getY() - 5);
	scoreTextLocation.setX(topLeft.getX() + 5);
	scoreTextLocation.setY(topLeft.getY() - 15);

	drawText(scoreTextLocation, "Score: ");
	drawNumber(scoreLocation, score);
}

void Game::drawLives()
{
	Point scoreLocation, scoreTextLocation;
	scoreLocation.setX(topLeft.getX() + 50);
	scoreLocation.setY(topLeft.getY() - 24);
	scoreTextLocation.setX(topLeft.getX() + 5);
	scoreTextLocation.setY(topLeft.getY() - 30);

	drawText(scoreTextLocation, "Lives: ");
	drawNumber(scoreLocation, lives);
}

void Game::reset()
{
	cleanUpBullets(true);
	cleanUpRocks(true);
	initializeRocks();
	initializeVariables();
	ship->reset(Point());
}
