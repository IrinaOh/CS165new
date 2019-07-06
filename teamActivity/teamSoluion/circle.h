



#ifndef CIRCLE_H
#define CIRCLE_H


#include "point.h"



class Circle : public Point
{
   private:
   float radius;
   
   public:
   Circle();

   float getRadius() const;
   void setRadius(float);

   void promptForCircle();
   void display() const;
};



#endif


































