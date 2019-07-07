/***********************************************************************
* Program:
*    "Checkpoint 01a, C++Basics"
*    Brother Dudley, CS165
* Author:
*    Sandro Tamborindegui
* Summary:
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/
#include <iostream>
using namespace std;

/**********************************************************************
* Function: main
* Purpose: This is the entry point and driver for the program.
***********************************************************************/

int main()
{
   cout << "Hello CS 165 World!\n";
   // Get users name
   cout << "Please enter your first name: ";
   char name[] = "";
   cin >> name;
   // Get users age
   cout << "Please enter your age: ";
   int age = 0;
   cin >> age;
   // Show users first name and age
   cout << "\nHello " << name << ", you are " << age << " years old.\n";
   
   return 0;
}
