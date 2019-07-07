/***********************************************************************
* Program:
*    Checkpoint 10a, Vectors
*    Brother {Burton, Falin, Ercanbrack}, CS165
* Author:
*    your name
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
************************************************************************/

#include <vector>
#include <string>
#include <iostream>

std::vector<int> promptIntVector()
{
   int input = -1;
   std::vector<int> returnVec;

   while (input != 0)
   {
      std::cout << "Enter int: ";
      std::cin >> input;
      if (input != 0)
         returnVec.push_back(input);
   }
   return returnVec;
}

void displayIntVector(std::vector<int> vec)
{
   std::cout << "Your list is:" << std::endl;
   for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
   {
      std::cout << *it << std::endl;
   }
}

std::vector<std::string> promptStringVector()
{
   std::cin.ignore(255, '\n');
   std::string input = "";
   std::vector<std::string> returnVec;

   while (input != "quit")
   {
      std::cout << "Enter string: ";
      getline(std::cin, input);
      if (input != "quit")
         returnVec.push_back(input);
   }
   return returnVec;
}

void displayStringVector(std::vector<std::string> vec)
{
   std::cout << "Your list is:" << std::endl;
   for (std::vector<std::string>::iterator it = vec.begin(); it != vec.end(); it++)
   {
      std::cout << *it << std::endl;
   }
}

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   displayIntVector(promptIntVector());
   std::cout << std::endl;

   displayStringVector(promptStringVector());
   return 0;
}
