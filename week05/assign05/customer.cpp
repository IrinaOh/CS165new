// File: customer.cpp

#include "customer.h"

#include <string>
#include <iostream>

/**********************************************************************
* FUNCTION: Display
* PURPOSE: Displays the name, and address in a mailing format
***********************************************************************/
void Customer::display()
{
	std::cout << this->name << std::endl;
	this->address.display();
}
