/****************
 * smartphone.h
 ****************/

#ifndef SMARTPHONE_H
#define SMARTPHONE_H

#include "phone.h"

using namespace std;
#include <iostream>

class Smartphone : public Phone
{
private:
	string _email;

public:
	string getEmail()           {  return _email; }
	void setEmail(string value) { _email = value; }
	void prompt();
	void display();

}; 

#endif
