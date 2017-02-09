// File: customer.h

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "address.h"
using namespace std;

// put your Customer class here
class Customer
{
private:
	string _name;
	Address _address; //it has the information coming from the Address class
public:
	Customer();
	Customer(string name, Address address);
	string getName()      { return _name;   } 
	Address getAddress()  { return _address;}
	
	void setName(string value);    
	void setAddress(Address address);
	
	void prompt();
	void display();

};


#endif


