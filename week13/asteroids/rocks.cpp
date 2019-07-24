#include "rocks.h"

//Put your Rock methods here

BigRock::BigRock(Point p) : Rock(BIG_ROCK_SPIN, BIG_ROCK_SIZE)
{
	this->setPoint(p);
	this->setAngle(random(0, 360));
	Velocity velSpeed = Velocity();
	velSpeed.setDx(this->getAngle().getXDir() * 1);
	velSpeed.setDy(this->getAngle().getYDir() * 1);
	this->setVelocity(velSpeed);
}

std::vector<Rock*> BigRock::destory()
{
	std::vector<Rock*> rocks;
	
	//First medium
	Velocity velSpeed = this->getVelocity();
	velSpeed.setDy(1);
	rocks.push_back(new MediumRock(velSpeed, this->getPoint()));
	
	//Second Medium
	velSpeed = this->getVelocity();
	velSpeed.setDy(-1);
	rocks.push_back(new MediumRock(velSpeed, this->getPoint()));
	
	//Small Rock
	velSpeed = this->getVelocity();
	velSpeed.setDx(2);
	rocks.push_back(new SmallRock(velSpeed, this->getPoint()));
	return rocks;
}


std::vector<Rock*> MediumRock::destory()
{
	std::vector<Rock*> rocks;
	
//First small
	Velocity velSpeed = this->getVelocity();
	velSpeed.setDx(3);
	rocks.push_back(new SmallRock(velSpeed, this->getPoint()));
	velSpeed = this->getVelocity();
	velSpeed.setDx(-3);
	rocks.push_back(new SmallRock(velSpeed, this->getPoint()));
	return rocks;
}
 

std::vector<Rock*> SmallRock::destory()
{
	return std::vector<Rock*>();
}
