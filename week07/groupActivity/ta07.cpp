#include <iostream>
using namespace std;

// Core requirements
float getValueFromPointer(float *thePointer);
float *getMinValue(float *a, float *b);

// Stretch goals
void swapElements(float *theArray[], int a, int b);
void sortArray(float *theArray[]);

int main()
{

   // Core Requirement 1
   int arraySize;
   cout << "Enter the array size: ";
   cin >> arraySize;

   // Allocate your array(s) here
   float *array = new float[arraySize];
   float **arrayA = new float *[arraySize];

   // Fill your array with float values
   for (int i = 0; i < arraySize; i++)
   {
      cout << "Enter a float value: ";
      cin >> array[i];

      arrayA[i] = array + i;
   }

   // Core Requirement 2
   for (int i = 0; i < arraySize; i++)
   {
      float value = getValueFromPointer(array + i);
      cout << "The value of the element " << i << " is: ";
      cout << value << endl;

      float valueA = getValueFromPointer(arrayA[i]);
      cout << "The value of the element " << i << " is: ";
      cout << valueA << endl;
   }

   // Core Requirement 3
   // Print the smaller of the first and last elements of the array
   float *pointerToMin = getMinValue(array, array + arraySize - 1);
   cout << *pointerToMin;

   swapElements(arrayA, 0, arraySize - 1);
   for (int i = 0; i < arraySize; i++)
   {
      float value = getValueFromPointer(array + i);
      cout << "The value of the element " << i << " is: ";
      cout << value << endl;

      float valueA = getValueFromPointer(arrayA[i]);
      cout << "The value of the element " << i << " is: ";
      cout << valueA << endl;
   }

   // Clean up your array(s) here
   delete[] array;
   delete[] arrayA;

   return 0;
}
float getValueFromPointer(float *thePointer)
{
   return *thePointer;
}

float *getMinValue(float *a, float *b)
{
   if (*a < *b)
   {
      return b;
   }
   else
   {
      return a;
   }
}

void swapElements(float *theArray[], int a, int b)
{
   float *tempA = theArray[a];
   theArray[a] = theArray[b];
   theArray[b] = tempA;
}
