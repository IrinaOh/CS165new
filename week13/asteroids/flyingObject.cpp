#include "flyingObject.h"
#include <iostream>

//Put your FlyingObjects method bodies here

void FlyingObject::advance()
{
	Point p = this->getPoint();

	p.addX(getVelocity().getDx());
	p.addY(getVelocity().getDy());

	if (p.getX() > 200)
		p.setX(-200);
	else if (p.getX() < -200)
		p.setX(200);

	if (p.getY() > 200)
		p.setY(-200);
	else if (p.getY() < -200)
		p.setY(200);

	this->setPoint(p);
	draw();
}
