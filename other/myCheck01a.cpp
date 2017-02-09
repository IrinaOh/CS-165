/***********************************************************************
* Program:
* Checkpoint 01a, C++ Basics
* Brother Falin, CS165
* Author:
* Anderson Erichsen Fagundes  
* Summary: 
*  
************************************************************************/
#include <iostream>
using namespace std;

void text();
void promptFirstName(char name[]);
void promptAge(int & age);
void displayText(char name[], int age);

/**********************************************************************
 * Main will call the other functions
 ***********************************************************************/
int main()
{
   text();
   char name[256];
   promptFirstName(name);
   int age;
   cin.clear();
   cin.ignore(80, '\n');
   promptAge(age);
   displayText(name, age);
   return 0;
}

/**********************************************************************
 * This function will display "Hello CS 165 World!"
 ***********************************************************************/
void text()
{
   cout << "Hello CS 165 World!\n";
}

/**********************************************************************
 * This function will prompt for the first name of the user
 ***********************************************************************/
void promptFirstName(char name[])
{
   cout << "Please enter your first name: ";
   cin >> name;
}

/**********************************************************************
 * This function will prompt for the age of the user
 ***********************************************************************/
void promptAge(int & age)
{
   cout << "Please enter your age: ";
   cin >> age;
   cout << '\n';
}

/**********************************************************************
 * This function will call the name and age and diplay it back
 * to the user
 ***********************************************************************/
void displayText(char name[], int age)
{
   cout << "Hello " << name << ", you are " << age << " years old.\n";
}
