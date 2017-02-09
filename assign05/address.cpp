// File: address.cpp

#include <iostream>
#include <iomanip>
#include "address.h"

using namespace std;



// Put your method bodies for the address class here


/*****************************************************************
 * Default - Set the street to "unknown", the zip to "00000",
 * and the other data members to "".
 ****************************************************************/
Address :: Address()
{
	_street = "unknown";
	_zip = "00000";
	_city = "";
  	_state = "";
}

/*****************************************************************
 * Non-default - Accept 4 strings (street, city, state, zip)
 * and set each of the values.
 ****************************************************************/
Address :: Address(string streetValue, string cityValue, string stateValue,  string zipValue)
{
	// set each of the values to what?
	_street = streetValue;
	_city = cityValue;
	_state = stateValue;
  	_zip = zipValue;
}

/*****************************************************************
 * Prompt the complete address
 ****************************************************************/
void Address :: prompt()
{
	string street;
	string zip;
	string city;
	string state;

	cout << "Street: ";
	cin >> street;

	cout << "City: ";
	cin >> city;

	cout << "State: ";
	cin >> state;

	cout << "Zip: ";
	cin >> zip;

	 setStreet(street);
	 setCity(city);
	 setState(state);
	 setZip(zip);
}

/*****************************************************************
 * set the street
 ****************************************************************/
 void Address :: setStreet(string value)
 {
 	_street = value;
 }

 /*****************************************************************
 * set the city
 ****************************************************************/
 void Address :: setCity(string value)
 {
 	_city = value;
 }

 /*****************************************************************
 * set the state
 ****************************************************************/
 void Address :: setState(string value)
 {
 	_state = value;
 }

 /*****************************************************************
 * set the zip
 ****************************************************************/
 void Address :: setZip(string value)
 {
 	_zip = value;
 }

 /*****************************************************************
 * Display the address
 ****************************************************************/
 void Address :: display()
 {
 	cout << getStreet() << endl;
 	cout << getCity() << ", " << getState() << " " << getZip() << endl; 
 }