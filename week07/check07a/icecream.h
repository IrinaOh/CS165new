/****************************
 * File: icecream.h
 ****************************/
#ifndef ICECREAM_H
#define ICECREAM_H

#include <string>

class IceCream                               // Ice Cream diagram
{
private:
   std::string flavor;                       //-flavor; string
   float price;                              //-price: float

public:
   
   //need to add static variable salesTax.
   static float salesTax;
   
   IceCream();
   IceCream(std::string flavor, float price); //+IceCream(flavor, price)

   float getTotalPrice() const;               //+getTotalPrice(): float
   void prompt();                             //+prompt(): void
   void display() const;                      //+display(): void
};


#endif
