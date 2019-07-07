/***********************************************************************
* Program:
*    Checkpoint 01b, review   
*    Brother Dudley, CS165
* Author:
*    Sandro Tamborindegui
* Summary:
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>
using namespace std;

/**********************************************************************
* Get Size
***********************************************************************/
int getSize() 
{
   int size = 0;
   cout << "Enter the size of the list: ";
   cin >> size;

   return size;
}

/**********************************************************************
* Get List
***********************************************************************/
void getList(int count, int (&passedArray)[20]) 
{
   for (int i = 0; i < count; i++) 
   {
      cout << "Enter number for index " << i << ": ";
      cin >> passedArray[i];
   }
   cout << endl;
}

/**********************************************************************
* Display Multiples divisible by 3
***********************************************************************/
void displayMultiples(int arraySize, int arr[20]) 
{
   cout << "The following are divisible by 3:" << endl;
   for (int i = 0; i < arraySize; i++) 
   {
      if (arr[i] % 3 == 0) 
      {
         cout << arr[i] << endl;
      }
   }
}

/**********************************************************************
* main call all functions
***********************************************************************/
int main() 
{
   const int size = getSize();
   int arr[20];
   getList(size, arr);
   displayMultiples(size, arr);

   return 0;
}
