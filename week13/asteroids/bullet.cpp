#include "bullet.h"


#include <cmath>
#include <iostream>

const float  B_PI = 3.14159265358979323846;

using namespace std;


//Put your bullets method here

void Bullet::fire(Point point, Angle angle)
{
	this->setPoint(point);

	Velocity velSpeed;
	velSpeed.setDx(BULLET_SPEED * angle.getXDir());
	velSpeed.setDy(BULLET_SPEED * angle.getYDir());
	setVelocity(velSpeed);
}

void Bullet::fire(Point point, Angle angle, Velocity velocity)
{
	this->setPoint(point);

	Velocity velSpeed;
	
	velSpeed.setDx(BULLET_SPEED * angle.getXDir());
	velSpeed.setDy(BULLET_SPEED * angle.getYDir());
	
	velSpeed.setDx(velocity.getDx());
	velSpeed.setDy(velocity.getDy());
	setVelocity(velSpeed);
}

void Bullet::advance()
{
	bulletAdv--;
	if (bulletAdv == 0)
	{
		this->kill();
	}

	FlyingObject::advance();
}

int Bullet::getBulletAdv()
{
	return bulletAdv;
}

