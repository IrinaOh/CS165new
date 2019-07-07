/***********************************************************************
* Program:
*    Checkpoint 03a, Exceptions
*    Brother Dudley, CS165
* Author:
*    Sandro Tamborindegui
* Summary:
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/
#include <iostream>
#include <string>
#include <sstream> // used for stringstream

/**********************************************************************
* Function Prompt, prompts the user for a number
***********************************************************************/
int prompt() throw (std::string)
{
   int num = -1;
   std::cout << "Enter a number: ";
   std::cin >> num;

   if (num < 0)
      throw std::string("The number cannot be negative.");

   if (num > 100)
      throw std::string("The number cannot be greater than 100.");

   if (num % 2 != 0)
      throw std::string("The number cannot be odd.");

   return num;

}

/**********************************************************************
 * Function main, call the function prompt ad display the results
 ***********************************************************************/
int main()
{
   int num = 0;
   try
   {
      num = prompt();
      std::cout << "The number is " << num << "." << std::endl;
   }
   catch (std::string err)
   {
      std::cout << "Error: " << err << std::endl;
   }

   return 0;
}
