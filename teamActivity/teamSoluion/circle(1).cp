







#include "circle.h"


  
Circle :: Circle()
{
   radius = 0.0;
}


float Circle :: getRadius() const
{
   return radius;
}

float Circle :: getX() const
{
   return point.getX();
}

float Circle :: getY() const
{
   return point.getY();
}



void Circle :: setRadius(float radius)
{
   this -> radius = radius;
}

void Circle :: setX(float x)
{
   point.setX(x);
}

void Circle :: setY(float y)
{
   point.setY(y);
}



void Circle :: promptForCircle()
{
   point.promptForPoint();
   std::cout << "Enter radius: ";
   std::cin >> radius;
}

void Circle :: display() const
{
   std::cout << "(" << point.getX() << ", " << point.getY() << ")"
             << " - Radius: " << radius << "\n";
}





























