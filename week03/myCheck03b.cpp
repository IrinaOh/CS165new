/***********************************************************************
* Program:
*    Checkpoint 03b, Errors.
*    Brother Dudley, CS165
* Author:
*    Sandro Tamborindegui
* Summary:
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>
//#include <sstream> // used for stringstream

/**********************************************************************
* Function: Prompt will prompt the user for a number
***********************************************************************/
int prompt() throw (std::string)
{
   int num = -1;
   bool passed = false;

   while (!passed) 
   {

      std::cout << "Enter a number: ";
      std::cin >> num;

      if (std::cin.fail())
      {
         std::cin.clear();
         std::cin.ignore(256, '\n');
         std::cout << "Invalid input." << std::endl;
         passed = false;
      }
      else
         passed = true;
   }

   return num;
}

/**********************************************************************
 * Function: main will call the function prompt and display it to 
 *   the user
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
