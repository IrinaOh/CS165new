/***************************************************************
* File: customer.h
* Purpose: definition of the Customer class
***************************************************************/
// File: customer.h

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "address.h"

class Customer
{
public:
	//getters
	Address getAddress() const { return this->address; }
	std::string getName() const { return this->name; }

	//Setters
	void setAddress(Address address) { this->address = address; }
	void setName(std::string name) { this->name = name; }

	//constructors
	Customer()
	{
		setName("unspecified");
		setAddress(Address());
	}
	Customer(std::string name, Address address)
	{
		setName(name);
		setAddress(address);
	}

	//Public Member Funciton
	void display();

private:
	std::string name;
	Address address;
};

// put your Customer class here

#endif
