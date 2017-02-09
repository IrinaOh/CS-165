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
struct Scripture
{
   string bookname;
   string chapter; 
   int verse;      
};

// fill the User structure
void prompt(Scripture & input);
// display the contents of the user on the screen
void display(const Scripture & output);
   
/**********************************************************************
 * This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   Scripture scripture;       // declare the variable
   prompt(scripture);    // since it is pass-by-reference, user changes
   display(scripture);   // since it is a const, user cannot change

   return 0;
}

/**********************************************************************
 * Prompt
 * Prompt the user for a names and id
 ***********************************************************************/
void prompt(Scripture & input)
{
   
}

/**********************************************************************
 * DISPLAY
 * Display the contents of the user
 ***********************************************************************/
void display(const Scripture & output)
{
   cout << endl;
   cout << "Your information:\n";
   // cout << output.id << " - " << output.firstName << " "
   //    << output.lastName << endl;
}











