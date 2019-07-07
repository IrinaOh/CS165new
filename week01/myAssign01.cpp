/***********************************************************************
* Program:
*    Assignment 01, Genetic Genealogy
*    Brother Dudley, CS165
*
* Author: Sandro Tamborindegui
*
* Summary:  Ask the user to input his DNA and compare it with the 
*              possible relatives DNA and display the results
*
*    Estimated:  2.0 hrs
*    Actual:     6.5 hrs
*     I have some difficulties to calculate the similitude of
*       DNA samples besides string coding
************************************************************************/

#include <iostream>
#include <string>
using namespace std;

/**********************************************************************
*  Relative class
***********************************************************************/
class Relative 
{
   public:
      string name;
      string sequence;
      float percentageRelated;
};

/**********************************************************************
*  Get Sequence 
***********************************************************************/
string getSequence() 
{
   string sequence = "";
   cout << "Enter your DNA sequence: ";
   cin >> sequence;
   
   //Check sequence size
   while (sequence.size() != 10) 
   {
      cout << "The Sequence you entered was not ";
      cout << "10 characters long. Please try again: " << endl;
      cin >> sequence;
   }
   return sequence;
}

/**********************************************************************
* get user enter the DNA sequence
***********************************************************************/
string getSequence(string name) 
{
   string sequence = "";
   cout << "Please enter the DNA sequence for " << name << ": ";
   cin >> sequence;
   
   //Check sequence size
   while (sequence.size() != 10) 
   {
      cout << "The Sequence you entered was not ";
      cout << "10 characters long. Please try again: " << endl;
      cin >> sequence;
   }
   return sequence;
}

/**********************************************************************
*  Get user to enter #'s of relatives he wants to check
***********************************************************************/
int getAmountRelatives() 
{
   int amount = 0;
   
   cout << "Enter the number of potential relatives: ";
   cin >> amount;
   cout << endl;
   
   return amount;
}

/**********************************************************************
*  Get user to enter relative's names
***********************************************************************/
void getRelativesNames(int amountRelatives, Relative (&relatives)[50]) 
{
   for (int i = 0; i < amountRelatives; i++) 
   {
      cout << "Please enter the name of relative #" << i + 1 << ": ";
      cin >> relatives[i].name;
   }
   cout << endl;
}

/**********************************************************************
* Get user to enter relative's DNA sequences
***********************************************************************/
void getRelativesSequences(int amountRelatives, Relative (&relatives)[50]) 
{
   for (int i = 0; i < amountRelatives; i++) 
   {
      relatives[i].sequence = getSequence(relatives[i].name);
   }
   cout << endl;
}

/**********************************************************************
* Determine percentage of DNA's coincidence of relatives
***********************************************************************/
float determinePercentage(string s1, string s2) 
{
   float percentage = 0.00;
   int minSize = 0;
   int maxSize = 0;
   int matches = 0;
   if (s1.size() > s2.size()) 
   {
      minSize = s2.size();
      maxSize = s1.size();
   }
   else 
   {
      minSize = s1.size();
      maxSize = s2.size();
   }
   for (int i = 0; i < minSize; i++) 
   {
      if (s1[i] == s2[i]) 
      {
         matches++;
      }
   }
   return matches / (float)maxSize;
}

/**********************************************************************
* Get relatives percentages for each one
***********************************************************************/
void getRelativesPercentages(int amountRelatives
   , string baseSequence, Relative(&relatives)[50]) 
{
   for (int i = 0; i < amountRelatives; i++) 
   {
      relatives[i].percentageRelated = 
         determinePercentage(baseSequence, relatives[i].sequence);
   }
}

/**********************************************************************
* Display relative percentages
***********************************************************************/
void displayRelativesPercentages(int amountRelatives
   , Relative(&relatives)[50]) 
{
   for (int i = 0; i < amountRelatives; i++) 
   {
      cout << "Percent match for " << relatives[i].name << ": ";
      cout << (int)(relatives[i].percentageRelated * 100) << "%" << endl;
   }
}

/**********************************************************************
* Main
* Will call all functions
***********************************************************************/
int main() 
{
   // Get string from user, 10 characters
   string primarySequence = getSequence();
   
   //Get relatives number
   int amountRelatives = getAmountRelatives();
   
   // Get relatives names 
   Relative relatives[50];
   
   getRelativesNames(amountRelatives, relatives);
   
   getRelativesSequences(amountRelatives, relatives);
   
   // Get percentage
   getRelativesPercentages(amountRelatives, primarySequence, relatives);
   
   // Display percentage that match
   displayRelativesPercentages(amountRelatives, relatives);
   
   return 0;
}
