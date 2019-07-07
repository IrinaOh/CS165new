/***********************************************************************
* Program:
*    Assignment 03, Digital Forensics with Corrupt Files.
*    Brother Dudley, CS165
* Author:
*    Sandro Tamborindegui
* Summary:
*    This program will read all logs by prompt the user to enter the file 
*    location start and end date. After list all files accessed, and who was
*    the user that access these files.
*    This program will ignore any corrupted log, and will return all valid
*    entries
*
*    Estimated:  6.0 hrs
*    Actual:     9.0 hrs
*      Create the parseLine/File functions and incorporate all the 
*      suggestions from Assignment 2.
************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

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
*Struct Date Range
***********************************************************************/
struct DateRange
{
   long startDate;
   long endDate;
};

/**********************************************************************
* Prompt the user for the file location
***********************************************************************/
   //from the forum discussion board example
void getPromptFilePath(char promptFilePath[])
{
   if (promptFilePath == NULL) //check for invalid 
   {
      std::cout << "Invalid access record file." ;
      return;
   } 
}

std::string promptFilePath()   //prompt for file path
{
   std::string path;
   std::cout << "Enter the access record file: ";
   std::cin >> path;
   return path;
}

/**********************************************************************
*  Prompt the user for enter the start and end time
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
void displayAccessRecords(const AccessRecord(&ar)[500])
{
   const int LINE_LENGTH = 19;
   std::cout << "The following records match your criteria:" << std::endl;
   std::cout << std::endl;
   std::cout << "      Timestamp" << " " << "               File";
   std::cout << " " << "               User" << std::endl;
   std::cout << "--------------- ------------------- -------------------" 
             << std::endl;
   
   for (int i = 0; i < 500 ; i++)
   {
      if (ar[i].timeStamp > 0 && ar[i].fileName.size() > 0 
         && ar[i].userName.size() > 0)
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
* Accepts a line (a string) and populates a struct for the AccessRecord
***********************************************************************/
AccessRecord parseLine (std::string line) throw (std::string)
{
   AccessRecord ar;
   std::stringstream ss;
   ss.str(line);
   ss >> ar.fileName;
   
   if (ss.fail())
      throw std::string("no filename on line"); 
   ss >> ar.userName;
   
   if (ss.fail())
      throw std::string("no username on line");
   ss >> ar.timeStamp;
   
   if (ss.fail())
      throw std::string("Timestamp is invalid/not found");
      
   if (ar.timeStamp < 1000000000)
      throw std::string("Timestamp is not long enough");
      
   if (ar.timeStamp > 10000000000)
      throw std::string("Timestamp is too long");
      
   return ar;
}

/**********************************************************************
* Parses the file one line at a time and check for errors
***********************************************************************/
void parseFile(std::string fileName, AccessRecord(&ar)[500])
{
   std::ifstream inputFileStream;
   
   inputFileStream.open(fileName.c_str());
   std::string line;
   
   int i = 0;
   
   while (getline(inputFileStream, line))
   {
      try
      {
         ar[i] = parseLine(line);
         i++;
      }
      //catch any errors, display the message
      catch (std::string err)
      {
         std::cout << "Error parsing line: " << line << std::endl;
      }
   }
}

/**********************************************************************
*  Main
 * Will call all functions and display the results for the user
***********************************************************************/
int main()
{
   AccessRecord allAccessRecords[500];
   
   std::string filePath = promptFilePath();
   parseFile(filePath, allAccessRecords);
   std::cout << std::endl;
   
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
