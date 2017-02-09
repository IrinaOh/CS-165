/*******************
 * smartphone.cpp
 *******************/

#include "smartphone.h"
using namespace std;
#include <iostream>

void Smartphone::prompt()
{
	promptNumber();

	string email;

	cout << "Email: ";
	cin >> email;

	setEmail(email);

}

void Smartphone::display()
{
	Phone::display();
	//cout << endl;
	cout << _email << endl;
}

