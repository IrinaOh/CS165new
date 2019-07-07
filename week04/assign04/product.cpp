/***************************************************************
 * File: product.cpp
 * Author: Sandro Tamborindegui
 * Purpose: Implement the method for the product class
 ***************************************************************/

#include "product.h"

#include <iostream>
#include <string>
#include <iomanip>

/**********************************************************************
* FUNCTION: prompt
* Purpose: Prompt the user to enter name, description, and weight
***********************************************************************/
void Product::prompt()
{
   std::cout << "Enter name: ";
   getline(std::cin, this->name);
   std::cout << "Enter description: ";
   getline(std::cin, this->description);
   std::cout << "Enter weight: ";
   std::cin >> this->weight;
   promptPrice();
}
/**********************************************************************
* FUNCTION: prompt Price
* Purpose: prompt the user for the price and check for wrong enter
***********************************************************************/
void Product::promptPrice()
{
   float price = -1.0f;
   bool passed = false;
   while (!passed)
   {
      std::cout << "Enter price: ";
      try
      {
         std::cin >> price;
         if (std::cin.fail())
         {
            std::cin.clear();
            std::cin.ignore(256, '\n');
            throw std::string("Price must be a number");
         }

         if (price < 0)
            throw std::string("Price must be positive");

         passed = true;
      }
      catch(std::string err)
      {
         //TODO: log error message...
         
      }
   }
   this->basePrice = price;;
}

/**********************************************************************
* FUNCTION: Get Sales Tax
* Purpose: calculate the sales tax
***********************************************************************/
float Product::getSalesTax()
{
   return 0.06f * this->basePrice;
}

/**********************************************************************
* FUNCTION: Get Shipping Cost
* Purpose: calculate the shipping cost
***********************************************************************/
float Product::getShippingCost()
{
   float shippingCost = 2.0;
   if (this->weight > 5)
      shippingCost += ((weight - 5) * 0.1f);
   
   return shippingCost;

}

/**********************************************************************
* FUNCTION: Get Total Price
* Purpose: display the total cost w/ price+tax+shipping
***********************************************************************/
float Product::getTotalPrice()
{
   return (this->basePrice + getSalesTax() + getShippingCost());
}

/**********************************************************************
* FUNCTION: Display Advertising Profile
* Purpose: Display advertising description
***********************************************************************/
void Product::displayAdvertisingProfile()
{
   std::cout << this->name << " - $" << this->basePrice << std::endl;
   std::cout << "(" << this->description << ")" << std::endl;
}

/**********************************************************************
* FUNCTION: Display Inventory Line Item
* Purpose: Display inventory description 
***********************************************************************/
void Product::displayInventoryLineItem()
{
   std::cout << "$" << this->basePrice << " - " << this->name << " - ";
   
   std::cout.setf(std::ios::fixed);
   std::cout.setf(std::ios::showpoint);
   std::cout.precision(1);
   
   std::cout <<this->weight << " lbs" << std::endl;
   
}

/**********************************************************************
* FUNCTION: Display Receipt
* Purpose: Generate the sales receipt 
***********************************************************************/
void Product::displayReceipt()
{
   std::cout << this->name << std::endl;
   formatReceiptLine("Price", this->basePrice);
   formatReceiptLine("Sales tax", getSalesTax());
   formatReceiptLine("Shipping cost", getShippingCost());
   formatReceiptLine("Total", getTotalPrice());
}

/**********************************************************************
* FUNCTION: Format Receipt Line
* Purpose: Form the receipt layout
***********************************************************************/
void Product::formatReceiptLine(std::string name, float amount)
{
   const int AMOUNT_SPACES = 13;
   std::cout << "  " << name << ": ";
   for (int i = 0; i < AMOUNT_SPACES - name.length(); i++)
      std::cout << " ";
   std::cout << "$   ";
   if (amount < 10)
      std::cout << " ";
   std::cout << amount << std::endl;
}
