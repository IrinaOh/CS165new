/***************************************************************
 * File: product.h
 * Author: Sandro Tamborindegui
 * Purpose: Define class product
 ***************************************************************/
#ifndef PRODUCT_H
#define PRODUCT_H

#include<string>

// put your class definition here
class Product{
public:
   //Setters
   void prompt();
   //getters
   float getSalesTax();
   float getShippingCost();
   float getTotalPrice();
   //displayers
   void displayAdvertisingProfile();
   void displayInventoryLineItem();
   void displayReceipt();
private:
   std::string name;
   float basePrice;
   float weight;
   std::string description;
   //private functions
   void formatReceiptLine(std::string name, float amount);
   void promptPrice();
};

#endif
