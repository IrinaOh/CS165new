







#include "circle.h"


  
Circle :: Circle()
{
   radius = 0.0;
}


float Circle :: getRadius() const
{
   return radius;
}

void Circle :: setRadius(float radius)
{
   this -> radius = radius;
}

void Circle :: promptForCircle()
{
   promptForPoint();
   std::cout << "Enter radius: ";
   std::cin >> radius;
}

void Circle :: display() const
{
   std::cout << "(" << getX() << ", " << getY() << ")"
             << " - Radius: " << radius << "\n";
}





























