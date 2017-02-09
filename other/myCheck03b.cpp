/***********************************************************************
* Program:
* Checkpoint 03b, Exceptions
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


/**********************************************************************
 * Main will call the other functions
 ***********************************************************************/
int main()
{
   int number;
   prompt(number);
   cout << "The number is " << number << '.' << endl;
     
   return 0;
}

/**********************************************************************
 * This function will prompt for a number
 ***********************************************************************/
void prompt(int& number)
{
   cout << "Enter a number: ";
   cin >> number;
   while (cin.fail())
   {
      cout << "Invalid input.\n";
      cin.clear();
      cin.ignore(256, '\n');
      cout << "Enter a number: ";
      cin >> number;
   }

}
