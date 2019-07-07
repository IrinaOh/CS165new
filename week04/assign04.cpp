/**************************************************************
 * File: assign04.cpp
 * Author: Sandro Tamborindegui
 * Purpose: Contains the main function to test the Product class.
 ***************************************************************/

#include <iostream>
#include <string>
//using namespace std;

#include "product.h"

void displayOptions();
int getDisplayChoice();

int main()
{
   //Limit decimals
   std::cout.setf(std::ios::fixed);
   std::cout.setf(std::ios::showpoint);
   std::cout.precision(2);

   // Declare your Product object here
   Product product;

   // Call your prompt function here
   product.prompt();


   std::cout << std::endl;
   std::cout << "Choose from the following options:\n";
   std::cout << "1 - Advertising profile\n";
   std::cout << "2 - Inventory line item\n";
   std::cout << "3 - Receipt\n";
   std::cout << std::endl;
   std::cout << "Enter the option that you would like displayed: ";



   int choice;
   std::cin >> choice;

   std::cout << std::endl;

   if (choice == 1)
   {
      // Call your display advertising profile function here
      product.displayAdvertisingProfile();
   }
   else if (choice == 2)
   {
      // Call your display inventory line item function here
      product.displayInventoryLineItem();
   }
   else
   {
      // Call your display receipt function here
      product.displayReceipt();
   }

   return 0;
}
