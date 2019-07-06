/****************
 * smartphone.h
 ****************/

#ifndef SMARTPHONE_H
#define SMARTPHONE_H

#include <iostream>
#include "phone.h"

// TODO: Put your SmartPhone definition here
class SmartPhone : public Phone
{
private:
   std::string email;

public:
   void prompt();
   void display() const;
};

#endif
