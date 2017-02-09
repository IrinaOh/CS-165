// File: address.h
#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>
using namespace std;

class Address
{
  private:
  	string _street;
  	string _city;
  	string _state; 
  	string _zip;
  public:
  	Address();
  	Address(string streetValue, string cityValue, 
  		    string stateValue,  string zipValue);
  	
  	string getStreet() {  return _street; } 
    string getCity()   {  return _city;   } 
    string getState()  {  return _state;  }
    string getZip()    {  return _zip;    }

  	void setStreet(string value);	
  	void setCity(string value);
  	void setState(string value);	
  	void setZip(string value);

  	void prompt();
    void display();
};

#endif
