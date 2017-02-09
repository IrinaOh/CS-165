#include "circle.h"

#include <iostream>
using namespace std;

void Circle :: promptForCircle()
{
   promptForPoint();

   cout << "Enter radius: ";
   cin >> radius;
}

void Circle :: display() const
{
   Point::display();

   cout << " - Radius: " << radius;
}
