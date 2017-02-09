/***********************
 * File: money.cpp
 ***********************/

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

#include "money.h"

/*****************************************************************
 * Function: prompt
 * Purpose: Asks the user for values for dollars and cents
 *   and stores them.
 ****************************************************************/
void Money :: prompt()
{
   int dollars;
   int cents;

   cout << "Dollars: ";
   cin >> dollars;

   cout << "Cents: ";
   cin >> cents;

   setDollars(dollars);
   setCents(cents);
}

/*****************************************************************
 * 
 ****************************************************************/
void Money :: setDollars(int value)
{
  _dollars = abs(value);   
}

/*****************************************************************
 * 
 ****************************************************************/
int Money :: getDollars() const
{
   return _dollars;
}

/*****************************************************************
 * 
 ****************************************************************/
void Money :: setCents(int value)
{
   _cents = abs(value);

}

/*****************************************************************
 * 
 ****************************************************************/
int Money :: getCents() const
{
   return _cents;
}

/*****************************************************************
 * Function: display
 * Purpose: Displays the value of the money object.
 ****************************************************************/
void Money :: display() const 
{
   cout << "$" << getDollars() << ".";
   cout << setfill('0') << setw(2) << getCents();
}
