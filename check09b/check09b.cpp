/***********************************************************************
* Program:
*    Checkpoint 09b, Pure Virtual Functions
*    Brother Falin, CS165
* Author:
*    Anderson Erichsen Fagundes
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// For this assignment, for simplicity, you may put all of your classes
// in this file.

class Shape
{
protected:
   string _name;

public:
   virtual ~Shape() { }
   string getName() const { return _name; }
   void setName(string name) { _name = name; }
   
   // TODO: Define your pure virtual function here
   virtual float getArea() = 0; // pure virtual function

};

class Circle : public Shape
{
private:
   float _radius;

public:
   ~Circle()
   {
      cout << "Cleaning up " << getName() << endl;
   }

   float getRadius() const { return _radius; }
   void setRadius(float radius) { _radius = radius; }

   // TODO: Implement a constructor here
   Circle() { _name = "Circle"; }

   // TODO: Redefine getArea() here
   float getArea() { return 3.14 * _radius * _radius;}

};

class Rectangle : public Shape
{
private:
   float _length;
   float _width;

public:
   ~Rectangle()
   {
      cout << "Cleaning up " << getName() << endl;
   }

   float getLength() const { return _length; }
   float getWidth() const { return _width; }
   void setWidth(float width) { _width = width; }
   // function **** added
   void setLength(float length) { _length = length;}  

   // TODO: Implement a constructor here
   Rectangle() { _name = "Rectangle" ; }

   // TODO: Redefine getArea() here
   float getArea () { return _length * _width;}

};

const int MAX_SIZE = 10;

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   // We will put all of our code in main for this one, just to keep
   // the focus on the virtual functions and not on passing items
   // between functions.
   
   // TODO: 1. Declare your array here
   // For this assignment you can use the size: MAX_SIZE
	Shape * shape[MAX_SIZE];
	//char input;


   char letter;
   int count = 0;

   do
   {
      cout << "Please enter 'c' for circle, 'r' for rectangle or 'q' to quit: ";
      cin >> letter;

      if (letter == 'c')
      {
         
         float radius;
         cout << "Enter the radius: ";
         cin >> radius;

         // TODO: 2. Create your circle object here, set the radius value
         // and add it to the array at index "count".
         
         shape[count] = new Circle(); 
         ((Circle*) shape[count])->setRadius(radius); //CASTING

         
         count++; // we have seen another shape
      }
      else if (letter == 'r')
      {
         float length;
         float width;

         cout << "Enter the length: ";
         cin >> length;

         cout << "Enter the width: ";
         cin >> width;
      
         // TODO: 3. Create your rectangle object here, set the length and
         // width, and add it to the array at index "count".
        shape[count] = new Rectangle(); 
        ((Rectangle*) shape[count])->setLength(length); //CASTING
        ((Rectangle*) shape[count])->setWidth(width);

         count++; // we have seen another shape
      }

   } while (letter != 'q');

   // Set the precision for our decimals
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   // Now we will display each shape
   for (int i = 0; i < count; i++)
   {
      // TODO: 4. Add a cout statment here to display the name and the area
      // of each shape in the list in the format "Circle - 10.32"
   	cout << shape[i]->getName() << " - " << shape[i]->getArea() << endl;
  
   }

   // TODO: 5. Loop through and free the memory of each object.
   for (int j = 0; j < count; j++)
   {
   	//delete [] shape;

   	cout << "Cleaning up " << shape[j]->getName() << endl;

   }

   return 0;
}


