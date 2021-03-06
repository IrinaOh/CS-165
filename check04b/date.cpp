/********************************************************************
 * File: date.cpp
 * Purpose: Holds the implementation of the Date class methods.
 ********************************************************************/
using namespace std;
#include <iostream>
#include "date.h"

// Put your method bodies here...
void Date::setDate()
{
	cout << "Month: ";
	cin >> month;
	
	cout << "Day: ";
	cin >> day;
	
	cout << "Year: ";
	cin >> year;

	cout << endl;
}

void Date::displayAmerican()
{
	cout << month << "/" << day << "/" << year << endl;
}

void Date::displayEuropean()
{
	cout << day<< "/" <<  month << "/" << year << endl;
}

void Date::displayISO()
{
	cout << year << "-" << month << "-" << day << endl;

}
