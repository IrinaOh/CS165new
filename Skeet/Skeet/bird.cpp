#include "bird.h"

int Bird::hit() { return 0; };

Bird::Bird()
{
   setVelSpeed(4);
   setLife(1);
   setHitPoint(1);
   setID(1);
}

standardBird::standardBird()
{
   setVelSpeed(4);
   setLife(1);
   setHitPoint(1);
   setID(1);
}

void standardBird::draw()
{
   drawCircle(getPoint(), 15);
}

/*
toughBird::toughBird()
{
   setVelSpeed(3);
   setLife(3);
   setHitPoint(1);
   setID(2);
}

void toughBird::draw()
{
   drawToughBird(getPoint(), 15, getLife());
}

sacredBird::sacredBird()
{
   setVelSpeed(4);
   setLife(1);
   setHitPoint(-10);
   setID(3);
}

void sacredBird::draw()
{
   drawSacredBird(getPoint(), 15);
}
 */
