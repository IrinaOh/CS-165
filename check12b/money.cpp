/***********************
 * File: money.cpp
 ***********************/

#include <iostream>
#include <iomanip>
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
 * Function: display
 * Purpose: Displays the value of the money object.
 ****************************************************************/
void Money :: display() const 
{
   cout << "$" << getDollars() << ".";
   cout << setfill('0') << setw(2) << getCents();
}

/*****************************************************************
 * Function: handleOverflow
 * Purpose: Checks if cents is greater than 100, and if so, rolls
 *   that amount over to dollars.
 ****************************************************************/
void Money :: handleOverflow()  
{
   if (cents >= 100)
   {
      dollars += cents / 100;
      cents = cents % 100;
   }
}


// Put the bodies of your member functions here!


Money& operator+=(Money & lhs, const Money & rhs)
{
   lhs.setDollars(lhs.getDollars() + rhs.getDollars());
   lhs.setCents(lhs.getCents() + rhs.getCents());
   lhs.handleOverflow();

   return lhs;
}

Money operator+(const Money & lhs, const Money & rhs)
{
   Money sum;

   sum.setDollars(lhs.getDollars() + rhs.getDollars());
   sum.setCents(lhs.getCents() + rhs.getCents());
   sum.handleOverflow();
   
   return sum;
}

Money& operator++(Money & lhs)
{
   lhs.setCents(lhs.getCents()+1);
   lhs.handleOverflow();
   return lhs;
}