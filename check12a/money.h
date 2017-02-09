/******************
 * File: money.h
 ******************/
#ifndef MONEY_H
#define MONEY_H
using namespace std;
#include <iostream>
#include <iomanip>


/******************************************************
 * Class: Money
 * Description: Holds a value of dollars and cents.
 ******************************************************/
class Money
{
private:
   int dollars;
   int cents;

public:
   /************************
    * Constructors
    ************************/
   Money()
   {
      setDollars(0);
      setCents(0);
   }

   Money(int dollars, int cents)
   {
      setDollars(dollars);
      setCents(cents);
   }

   /************************
    * Getters and Setters
    ************************/
   int getDollars()  { return dollars; }
   int getCents()  { return cents; }
   
   void setDollars(int dollars) { this->dollars = dollars; }
   void setCents(int cents) { this->cents = cents; }

   /************************
    * Other public methods
    ************************/
   void prompt();

   friend void display(Money &money);

};



// Non-member operator prototypes go here

#endif


