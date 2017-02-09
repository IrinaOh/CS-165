/***********************************************************************
* Program:
* Checkpoint 03a, Exceptions
* Brother Falin, CS165
* Author:
* Anderson Erichsen Fagundes  
* Summary: 
*  
************************************************************************/
#include <iostream>
#include <string>
using namespace std;


void prompt(int& number);
void exceptionalFunction(int& number);

/**********************************************************************
 * Main will call the other functions
 ***********************************************************************/
int main()
{
   int number;
   prompt(number);
   exceptionalFunction(number);
       
   return 0;
}

/**********************************************************************
 * This function will prompt for a number
 ***********************************************************************/
void prompt(int& number)
{
   cout << "Enter a number: ";
   cin >> number;
}

/**********************************************************************
 * This function will handle exceptions
 ***********************************************************************/
void exceptionalFunction(int& number) 
{
   try
   {
      if (number < 0)
      {
         throw "Error: The number cannot be negative.";
      }
      else if (number > 100)
      {
         throw "Error: The number cannot be greater than 100.";
      }
      else if (number % 2 > 0)
      {
         throw "Error: The number cannot be odd.";
      }
      cout << "The number is " << number << '.' << endl;
   }
   catch (const char * message)
   {
      cout << message << endl;
   }
}

