#ifndef GAME_H
#define GAME_H

#include <vector>

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "ship.h"
#include "rocks.h"
#include "bullet.h"

#define CLOSE_ENOUGH 15
#define AMOUNT_OF_LIVES 3

class Game
{
private:
	Point topLeft;
	Point bottomRight;
	std::vector<Rock*> asteroids;
	std::vector<Bullet*> bullets;
	Ship* ship;
	int score;
	int lives;
	bool newWave;
	bool Thrust;

	float getClosestDistance(const FlyingObject& obj1, const FlyingObject& obj2) const;

	
	void advanceBullets();
	void advanceAsteroids();
	void advanceShip();

	
	void drawBullets();
	void drawAsteroids();
	void drawShip();
	void drawScore();
	void drawLives();


	void cleanUpZombies();
	void cleanUpShip();
	void cleanUpBullets(bool deleteAll);
	void cleanUpRocks(bool deleteAll);


	void handleCollisions();
	void handleBulletCollisions();
	void handleShipCollisions();

	
	void initializeRocks();
	void initializeVariables();

public:
	Game(Point tl, Point br); 

	void handleInput(const Interface& ui);
	void advance();
	void draw(const Interface & ui);
	void reset();


};


#endif /* GAME_H */
