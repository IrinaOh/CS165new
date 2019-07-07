



#ifndef CIRCLE_H
#define CIRCLE_H


#include "point.h"



class Circle
{
   private:
   float radius;
   Point point;
   
   public:
   Circle();

   float getRadius() const;
   float getX() const;
   float getY() const;

   void setRadius(float);
   void setX(float);
   void setY(float);

   void promptForCircle();
   void display() const;
};



#endif


































