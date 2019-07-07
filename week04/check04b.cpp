/*********************************************************************
* File: check04b.cpp                                                           
* Purpose: contains the main method to exercise the Date class. 
*********************************************************************/

#include "date.h"

#include <iostream>

int main()
{
   // prompt the user for month, day, year
   int monthInt = -1, day = -1, year = -1;
   std::cout << "Month: ";
   std::cin >> monthInt;
   eMonth month = eMonth(monthInt);

   std::cout << "Day: ";
   std::cin >> day;
   std::cout << "Year: ";
   std::cin >> year;
   // create a Date object
   Date date;
   // set method for the object
   date.set(month, day, year);
   // call each display functions
   std::cout << std::endl;
   date.displayAmerican();
   date.displayEuropean();
   date.displayISO();

   return 0;
}
