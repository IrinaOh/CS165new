/***********************************************************************
* Program:
*    Assignment 02, Digital Forensics        
*    Brother Dudley, CS165
* Author:
*    Sandro Tamborindegui
* Summary: 
*    This code will look into ACME Widget Corp, to help determinate 
*    which files was breached how many files could be committed.
*    This program will read all logs by prompt the user to enter the file 
*    location start and end date of after list all files accessed and who was
*    the user that access these files
*
*    Estimated:   5.0 hrs   
*    Actual:     48.0 hrs
*      I am struggling with strings and struct to understand it 
*        The developer's forum help me a lot
************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
//using namespace std;

/**********************************************************************
* Struct Access Record
***********************************************************************/
struct AccessRecord
{
   std::string userName;
   std::string fileName;
   long timeStamp;
};

/**********************************************************************
* Struct Date Range
***********************************************************************/
struct DateRange
{
   long startDate;
   long endDate;
};

/**********************************************************************
* Prompt the user for the file location
***********************************************************************/
std::string promptFilePath()
{
   std::string path;
   std::cout << "Enter the access record file: ";
   std::cin >> path;
   return path;
}

/**********************************************************************
* Prompt the user for enter the start and end time
***********************************************************************/
DateRange promptTimes()
{
   DateRange dr;
   std::cout << "Enter the start time: ";
   std::cin >> dr.startDate;
   std::cout << "Enter the end time: ";
   std::cin >> dr.endDate;
   return dr;
}

/**********************************************************************
* Display the records that match the criteria 
***********************************************************************/
void displayAccessRecords(const AccessRecord (&ar)[500])
{
   const int LINE_LENGTH = 19;
   std::cout << "The following records match your criteria:" << std::endl;
   std::cout << std::endl;
   std::cout << "      Timestamp" << " " << "               File";
   std::cout << " " << "               User" << std::endl;
   std::cout << "--------------- ------------------- -------------------" << 
      std::endl;
   
   for (int i = 0; i < 500; i++)
   {
      if (ar[i].timeStamp > 0 && ar[i].fileName.size() >
         0 && ar[i].userName.size() > 0)
      {
         std::cout << "     " << ar[i].timeStamp << " ";
         for (int j = 0; j < (LINE_LENGTH - ar[i].fileName.size()); j++)
         {
            std::cout << " ";
         }
         std::cout << ar[i].fileName << " ";
         for (int j = 0; j < (LINE_LENGTH - ar[i].userName.size()); j++)
         {
            std::cout << " ";
         }
         std::cout << ar[i].userName << std::endl;
      }
   }
   std::cout << "End of records" << std::endl;
}

/**********************************************************************
 * Main
 * Will call all functions and display the results for the user
 ***********************************************************************/
int main()
{
   AccessRecord allAccessRecords[500];
   
   std::string filePath = promptFilePath();
   std::cout << std::endl;
   
   std::ifstream inputFileStream;
   inputFileStream.open(filePath.c_str());
   std::string word;
   int i = 0;
   
   while (inputFileStream >> word)
   {
      allAccessRecords[i].fileName = word;
      inputFileStream >> allAccessRecords[i].userName;
      inputFileStream >> allAccessRecords[i].timeStamp;
      i++;
   }

   DateRange range = promptTimes();
   std::cout << std::endl;
   
   AccessRecord matchedRecords[500];
   int count = 0;
   for (int i = 0; i < 500; i++)
   {
      if (allAccessRecords[i].timeStamp >= range.startDate 
         && allAccessRecords[i].timeStamp <= range.endDate)
      {
         matchedRecords[count] = allAccessRecords[i];
         count++;
      }
   }
   displayAccessRecords(matchedRecords);


   return 0;
}
