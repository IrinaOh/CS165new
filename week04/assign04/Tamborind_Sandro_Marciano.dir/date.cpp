/********************************************************************
* File: date.cpp                                                               
* Purpose: Holds the implementation of the Date class methods. 
********************************************************************/
#include "date.h"

#include<string>
#include<iostream>


/**********************************************************************
* Method: Set
***********************************************************************/
void Date::set(eMonth month, int day, int year)
{
   this->month = month;
   this->day = day;
   this->year = year;
}

/**********************************************************************
* Method: Display American
***********************************************************************/
void Date::displayAmerican()
{
   std::cout << int(month) << "/" << day << "/" << year << std::endl;
}

/**********************************************************************
* Method: Display European
***********************************************************************/
void Date::displayEuropean()
{
   std::cout << day << "/" << int(month) << "/" << year << std::endl;
}

/**********************************************************************
* Method: Display ISO
***********************************************************************/
void Date::displayISO()
{
   std::cout << year << "-" << month << "-" << day << std::endl;
}
