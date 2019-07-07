#ifndef CIRCLE_H
#define CIRCLE_H

#include "point.h"

class Circle
{
private:
   Point point;
   int radius;

public:
   int getRadius() { return this->radius; }
   void setRadius(int radius) { this->radius = radius; }
   Point getPoint() { return this->point; }
   void setPoint(Point point) { this->point = point; }

   int getX() { return point.getX(); }
   void setX(int X) { this->point.setX(X); }
   int getY() { return point.getY(); }
   void setY(int Y) { this->point.setY(Y); }

   void promptForCircle();
   void display();
};

#endif // !CIRCLE_H
