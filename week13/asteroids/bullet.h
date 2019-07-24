#ifndef bullet_h
#define bullet_h

#define BULLET_SPEED 5
#define BULLET_LIFE 40


#include "flyingObject.h"
#include "point.h"
#include "uiDraw.h"

//Put your bullet class here

class Bullet : public FlyingObject
{
public:
	Bullet(Point point) { setVelocity(Velocity()); setPoint(point); bulletAdv = 40; }
	Bullet() { setVelocity(Velocity()); setPoint(Point()); bulletAdv = 40; }

	int getBulletAdv();

	void fire(Point point, Angle angle);
	void fire(Point point, Angle angle, Velocity velocity);
	void advance();

private:
	int bulletAdv;
};

#endif /* bullet_h */
