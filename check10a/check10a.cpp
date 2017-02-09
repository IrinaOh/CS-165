/***********************************************************************
* Program:
*    Checkpoint 10a, Vectors
*    Brother Falin, CS165
* Author:
*    Anderson Erichsen Fagundes
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
************************************************************************/
#include <iostream>
#include <vector>
#include <string>

using namespace std;


/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
	vector<int> v;
	int value;
	
	cout << "Enter int: ";
	cin >> value;
	
	while (value != 0) 
	{
		v.push_back(value);
		cout << "Enter int: ";
		cin >> value;
	}
	

	cout << "Your list is:" << endl;

	for (vector<int> :: iterator it = v.begin(); it != v.end(); it++)
		cout << *it << endl;
	cout << endl;


	// Now handling the vector of strings
	vector<string> vString;
	string text;
	cout << "Enter string: ";
	cin >> text;
	while (text != "quit")
    {
		vString.push_back(text);
		cout << "Enter string: ";
		cin >> text;
	}
	
	
	cout << "Your list is:" << endl;

	for (vector<string> :: iterator it = vString.begin(); it != vString.end(); it++)
		cout << *it << endl;


   return 0;
}


