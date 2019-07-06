/*******************
 * smartphone.cpp
 *******************/
#include <iostream>
#include "phone.h"
#include "smartphone.h"

// TODO: Put your SmartPhone methods here
void SmartPhone::prompt()
{
   promptNumber();
   std::cout << "Email: ";
   std::cin >> email;
   std::cin.ignore(1);
}

void SmartPhone::display() const
{
   Phone::display();
   std::cout << email << std::endl;
}
