/***********************************************************************
* Program:
*    Checkpoint 09a, Virtual Functions
*    Brother Falin, CS165
* Author:
*    Anderson Erichsen Fagundes
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Car
{
protected:
	string _name;
public:
	Car()                      { _name = "Unknown model";          }
	string getName()           { return _name;                     }
	void setName(string value) { _name = value;                    }
    virtual string getDoorSpecs()      { return "Unknown doors\n";         }
};

class Civic : public Car
{
	public:
		Civic()                    { _name = "Civic";              }
		string getDoorSpecs()      { return "4 doors\n";           }
};

class Odyssey : public Car
{
	public:
		Odyssey() { _name = "Odyssey";}  
		string getDoorSpecs()      { return "2 front doors, 2 sliding doors, 1 tail gate\n";}
};

class Ferrari : public Car
{
	public:
		Ferrari() { _name = "Ferrari";}
		string getDoorSpecs()      { return "2 butterfly doors\n"; }
};

/**********************************************************************
 * Function: attachDoors
 * Purpose: This function can accept any type of Car object. It will
 *  call the appropriate functions to display the name and the doors info.
 ***********************************************************************/

// TODO: Include your attachDoors function here

 void attachDoors(Car* car)
 {
 	cout << "Attaching doors to " << car->getName() << " - " << car->getDoorSpecs();
 }


/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   // You should not change main

   Civic civic;
   Odyssey odyssey;
   Ferrari ferrari;


   attachDoors(&civic);
   attachDoors(&odyssey);
   attachDoors(&ferrari);

   return 0;
}


