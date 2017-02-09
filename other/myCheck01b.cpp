/***********************************************************************
 * Program:
 *    Checkpoint 01b, C++ Basics
 *    Brother Falin, CS165
 * Author:
 *    Anderson Erichsen Fagundes
 * Summary:
 *    Summaries are not necessary for checkpoint assignments.
 * ***********************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

void getSize(int &list);
void getList(int& list, int index[]);
void displayMultiples(int& list, int index[]);

/**********************************************************************
 * This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   int list; 
   int* index = NULL; // creating a point to a future array in memory
   getSize(list);
   index = new int[list]; // static memory allocation
   getList(list, index);
   displayMultiples(list, index);
   delete [] index;
   
   return 0;
}

/**********************************************************************
 * This function will get the size of the list
 ***********************************************************************/
void getSize(int &list)
{
   cout << "Enter the size of the list: ";
   cin >> list;
}

/**********************************************************************
 * This function will get the values for the index
 ***********************************************************************/
void getList(int& list, int index[])
{
   for (int i = 0; i < list; i++) // Prompt numbers for index
   {
      cout << "Enter number for index " << i << ": ";
      cin >> index[i];
   }
   cout << '\n';
}

/**********************************************************************
 * This function will display divisibles of 3
 ***********************************************************************/
void displayMultiples(int& list, int index[])
{
   cout << "The following are divisible by 3:\n"; // display the numbers that are divisible
   for (int i = 0; i < list; i++)
   {
      if (index[i] % 3 == 0)
         cout << index[i] << endl;
   }

}










