/***********************************************************************
* Program:
*    Checkpoint 08a, Inheritance
*    Brother Dudley, CS165
* Author:
*   Sandro T
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>

// For this assignment, for simplicity, you may put all of your classes
// in this file.

// TODO: Define your Book class here
class Book
{
private:
   std::string title;
   std::string author;
   int publicationYear;

public:
   void promptBookInfo()
   {
      std::cout << "Title: ";
      getline(std::cin, title);
      std::cout << "Author: ";
      getline(std::cin, author);
      std::cout << "Publication Year: ";
      std::cin >> publicationYear;
      std::cin.ignore(1);
   }

   void displayBookInfo() const
   {
      std::cout << title << " (" << publicationYear << ") by " << author << std::endl;
   }
};

// TODO: Define your TextBook class here
class TextBook : public Book
{
private:
   std::string subject;

public:
   void promptSubject()
   {
      std::cout << "Subject: ";
      getline(std::cin, subject);
   }

   void displaySubject() const
   {
      std::cout << "Subject: " << subject << std::endl;
   }
};

// TODO: Add your PictureBook class here
class PictureBook : public Book
{
private:
   std::string illustrator;

public:
   void promptIllustrator()
   {
      std::cout << "Illustrator: ";
      getline(std::cin, illustrator);
   }

   void displayIllustrator()
   {
      std::cout << "Illustrated by " << illustrator << std::endl;
   }
};

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   // Declare a Book object here and call its methods
   Book book;

   book.promptBookInfo();
   std::cout << std::endl;

   book.displayBookInfo();
   std::cout << std::endl;

   // Declare a TextBook object here and call its methods
   TextBook textBook;

   textBook.promptBookInfo();
   textBook.promptSubject();
   std::cout << std::endl;

   textBook.displayBookInfo();
   textBook.displaySubject();
   std::cout << std::endl;

   // Declare a PictureBook object here and call its methods
   PictureBook pictureBook;

   pictureBook.promptBookInfo();
   pictureBook.promptIllustrator();
   std::cout << std::endl;

   pictureBook.displayBookInfo();
   pictureBook.displayIllustrator();

   return 0;
}
