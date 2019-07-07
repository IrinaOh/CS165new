/**********************************************************************
 * File: ta03.cpp
 * Author: Br. Burton
 *
 * Description: Use this file as a starting point for Team Activity 03.
 *    You do not need to "submit" your code, but rather, answer the
 *    questions in the I-Learn assessment.
 **********************************************************************/  
  
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <sstream>
  
/***********************************************************************
 * Struct: Scripture
 * Description: Holds the reference to a scripture (book, chapter, verse
 ***********************************************************************/ 
struct Scripture 
{
  
std::string book;
  
int chapter;
   
int verse;
 
};

 
/***********************************************************************
 * 
 * 
 ***********************************************************************/ 
  std::vector < Scripture > readFile (const std::string & fileName) 
{
  
std::string line;
  

 
Scripture scripture;
  
std::vector < Scripture > ourScriptures;
  
 
std::ifstream fin (fileName.c_str ());
  
try 
  {
    
      //std::ifstream fin(fileName.c_str());           //open the file
      if (fin.fail ())
      
      {
	
throw std::invalid_argument ("Unable to open file ");
      
}
  
}
  
catch (const std::exception & e) 
  {
    
std::cerr << e.what ();
  
}
while (std::getline(fin, line))
{
  std::stringstream ss; 
  ss.str(line);
  std::string book;
  int chapter;
  int verse;
  ss >> book >> chapter >> verse;
  scripture.book = book;
  scripture.chapter = chapter;
  scripture.verse = verse;
  ourScriptures.push_back(scripture);
}

fin.close ();
  
 
return ourScriptures;

}


 
 
/***********************************************************************
 * Function: display
 * Description: Displays the passed scripture.
 ***********************************************************************/ 
  void
display (const Scripture & scripture) 
{
  
std::cout << scripture.book << " ";
  
std::cout << scripture.chapter << ":";
  
std::cout << scripture.verse;

} 
 

/***********************************************************************
 * 
 * 
 ***********************************************************************/ 
  
std::string getFileName () 
{
  
std::string fileName;
  
std::cout << "Enter the access record file: ";
  
std::cin >> fileName;
  
std::cout << std::endl;
  
 
return fileName;

}


 
 
/***********************************************************************
 * Function: main
 * Description: The driver for the program.
 ***********************************************************************/ 
  int
main () 
{
  
    // Insert your code here to prompt for the name of a file
    // and pass it to a readFile function
    std::string fileName = getFileName ();
  
 
std::vector < Scripture > ourScriptures = readFile (fileName);
  
 
for (int i = 0; i < ourScriptures.size (); i++)
    
    {
      
display (ourScriptures[i]);
std::cout << std::endl;
    
} 
 
return 0;

 
}
