/*********************
 * phone.cpp
 *********************/
#include "phone.h"

 using namespace std;
 #include <iostream>

void Phone::promptNumber()
{
	int area;
	int prefix;
	int suffix;

	//cout << "Phone:\n";
	
	cout << "Area Code: ";
	cin >> area;

	cout << "Prefix: ";
	cin >> prefix;

	cout << "Suffix: ";
	cin >> suffix;

	setAreaCode(area);  
	setPrefix(prefix); 
	setSuffix(suffix);
}

void Phone::display()
{
	//cout << "Phone info:\n";
	cout <<'(' << _area << ')' << _prefix <<'-' << _suffix << endl;

}

