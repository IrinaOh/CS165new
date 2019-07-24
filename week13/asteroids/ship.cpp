#include "ship.h"

//Put your ship methods here

void Ship::applyThrust(bool isForward)
{
	float thrust = (isForward) ? THRUST_AMOUNT : -THRUST_AMOUNT;
	
	Velocity velSpeed = this->getVelocity();
	velSpeed.setDx(this->getAngle().getXDir() * thrust);
	velSpeed.setDy(this->getAngle().getYDir() * thrust);
	this->setVelocity(velSpeed);
}

void Ship::applyRotation(bool isRight)
{
	if (isRight)
	{
		applyRotation(-ROTATE_AMOUNT);
	}
	else
	{
		applyRotation(ROTATE_AMOUNT);
	}
}


void Ship::applyRotation(int rotation)
{
	angle.setAngle(rotation + angle.getAngle());
}



