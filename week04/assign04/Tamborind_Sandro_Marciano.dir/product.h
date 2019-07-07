/***************************************************************
 * File: product.h
 * Author: Sandro Tamborindegui
 * Purpose: Define class product
 ***************************************************************/
#ifndef PRODUCT_H
#define PRODUCT_H

#include<string>

// put your class definition here
// CODE REVIEW: Comments are more important in header files than in implementation files, since they
//   describe the contract (API) the clients must adhere to. Every class should have a descriptive
//   comment, and all non-obvious functions should have one as well. This will be docked points
//   on future assignments (and especially on the projects).
class Product{
public:
   //Setters
   void prompt();
   //getters
// CODE REVIEW: (Consider) the display* and get* methods should all be const.
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
