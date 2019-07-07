/***********************************************************************
* Program:
*    Checkpoint 02a, Structs  
*    Brother Dudley, CS165
* Author:
*    Sandro Tamborindegui
* Summary: 
*    .  Take me a bit longer to figure out the structs function
* ***********************************************************************/

#include <iostream>
#include <string>
using namespace std;

/**********************************************************************
* Function struct Student(user)
***********************************************************************/
struct Student 
{
   string firstName;
   string lastName;
   int id;
};

/**********************************************************************
* Ask user to enter his//her information
***********************************************************************/
void displayStudent(Student student) 
{
   cout << student.id
      << " - "
      << student.firstName
      << " "
      << student.lastName
      << endl;
}

/**********************************************************************
 * Main - display the results for the user
 ***********************************************************************/
int main()
{
   // Get user enter his/her information
   Student user;
   cout << "Please enter your first name: ";
   cin >> user.firstName;
   cout << "Please enter your last name: ";
   cin >> user.lastName;
   cout << "Please enter your id number: ";
   cin >> user.id;
   cout << endl;
   
   // Display User Information
   cout << "Your information:" << endl;
   displayStudent(user);

   return 0;
}
