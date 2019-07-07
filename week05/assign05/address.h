/***************************************************************
* File: address.h
* Purpose: Definition of class Addres
***************************************************************/

#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

class Address
{
public:
   //Getters
   std::string getStreet() const { return this->street; };
   std::string getCity() const { return this->city; };
   std::string getState() const { return this->state; };
   std::string getZip() const { return this->zip; };

   //Setters
   void setStreet(std::string street) { this->street = street; };
   void setCity(std::string city) { this->city = city; };
   void setState(std::string state) { this->state = state; };
   void setZip(std::string zip) { this->zip = zip; };

   //Constructors
   Address()
   {
      setStreet("unknown");
      setCity("");
      setState("");
      setZip("00000");
   };

   Address(std::string street, std::string city, std::string state, std::string zip)
   {
      setStreet(street);
      setCity(city);
      setState(state);
      setZip(zip);
   };

   //public member functions
   void display();

private:
   std::string street;
   std::string city;
   std::string state;
   std::string zip;
};

#endif
