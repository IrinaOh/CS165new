#include "circle.h"

#include <iostream>
#include <string>

void Circle::promptForCircle()
{
   int r;
   this->point.promptForPoint();
   std::cout << "Enter Radius: ";
   std::cin >> r;
   setRadius(r);
}

void Circle::display()
{
   this->point.display();
   std::cout << " - Radius: " << getRadius() << std::endl;
}
