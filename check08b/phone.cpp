/*********************
 * phone.cpp
 *********************/
#include <iostream>
#include "phone.h"

// TODO: Put your phone class definition here...
void Phone::promptNumber()
{
   std::cout << "Area Code: ";
   std::cin >> areaCode;
   std::cout << "Prefix: ";
   std::cin >> prefix;
   std::cout << "Suffix: ";
   std::cin >> suffix;
   std::cin.ignore(1);
}

void Phone::display() const
{
   std::cout << "(" << areaCode << ")" << prefix << "-" << suffix << std::endl;
}
