/***********************************************************************
 * Program:
 *    Checkpoint 02a, C++ Basics
 *    Brother Falin, CS165
 * Author:
 *    Anderson Erichsen Fagundes
 * Summary:
 *    Summaries are not necessary for checkpoint assignments.
 * ***********************************************************************/
#include <iostream>
#include <string>
using namespace std;


/***********************************************
 * USER
 * To store names and college id 
 ***********************************************/
struct User
{
   string firstName;  // Use string class to store the first name
   string lastName;   // Use string class to get the city
   int id;            // Student ID usually contain only integers
};

// fill the User structure
void prompt(User & input);
// display the contents of the user on the screen
void display(const User & output);
   
/**********************************************************************
 * This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   User user;       // declare the variable
   prompt(user);    // since it is pass-by-reference, user changes
   display(user);   // since it is a const, user cannot change

   return 0;
}

/**********************************************************************
 * Prompt
 * Prompt the user for a names and id
 ***********************************************************************/
void prompt(User & input)
{
   cout << "Please enter your first name: ";
   getline(cin, input.firstName);
   cout << "Please enter your last name: ";
   getline(cin, input.lastName);
   cout << "Please enter your id number: ";
   cin >> input.id;
}

/**********************************************************************
 * DISPLAY
 * Display the contents of the user
 ***********************************************************************/
void display(const User & output)
{
   cout << endl;
   cout << "Your information:\n";
   cout << output.id << " - " << output.firstName << " "
        << output.lastName << endl;
}











