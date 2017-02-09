// File: customer.cpp
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "customer.h"

// Put the method bodies for your customer class here

/*****************************************************************
 * Default - Set the name to "unspecified" and uses the address's
 * default constructor.
 ****************************************************************/
Customer :: Customer()
{
	_name = "unspecified";
	_address = Address :: Address(); 
}

/*****************************************************************
 * Non-default - Accept a name and an address object.
 ****************************************************************/
Customer :: Customer(string name, Address address)
{
	_name = name;
	_address = address;

	// not sure how to call this one
}

/*****************************************************************
 * set the name
 ****************************************************************/
void Customer :: setName(string value)
{
	_name = value;
}   

/*****************************************************************
 * set the address
 ****************************************************************/
void Customer :: setAddress(Address address)
{
	_address = address;

}

/*****************************************************************
 * prompt the information
 ****************************************************************/	
void Customer :: prompt()
{
	string name;
	cout << "Name: ";
	cin >> name;

	_address.prompt();

	setName(name);


}

/*****************************************************************
 * Displays the name, then calls the address's display method
 ****************************************************************/
void Customer :: display()
{
	cout << getName() << endl;
	_address.display(); 

}
