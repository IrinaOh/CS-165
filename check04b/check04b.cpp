/*********************************************************************
 * File: check04b.cpp
 * Purpose: contains the main method to exercise the Date class.
 *********************************************************************/

#include "date.h"

#include <iostream>
using namespace std;

int main()
{
   Date date;

   date.setDate();
   date.displayAmerican();
   date.displayEuropean();
   date.displayISO();

   return 0;
}
