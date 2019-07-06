#ifndef VELOCITY_H
#define VELOCITY_H

#include <iostream>
#include <math.h>

class Velocity
{
private:
   float dX;
   float dY;
   float angle;
   float speed;

public:
   Velocity();
   Velocity(float x, float y);
   Velocity(float x, float y, float ang, float spd)
   {
      this->dX = x;
      this->dY = y;
   this->angle = ang; this->speed = spd;
   }
   ~Velocity();

   float getDx()
   {
      return dX;
   }
   float getDy()
   {
      return dY;
   }
   void setDx(float x)
   {
      this->dX = x;
   }
   void setDy(float y)
   {
      this->dY = y;
   }
   void setDCoord(float x, float y)
   {
      this->dX = y;
      this->dY = y;
   }

   float getAngle() const
   {
      return angle;
   }
   void setAngle(float ang)
   {
      this->angle = ang;
   }

   float getSpeed() const
   {
      return speed;
   }
   void setSpeed(float spd)
   {
      this->speed = spd;
   }

   void setVelocity(float x, float y, float ang, float spd)
   {
      this->dX = x;
      this->dY = y;
      this->angle = ang;
      this->speed = spd;
   }

   void calcAngle();
};

#endif
