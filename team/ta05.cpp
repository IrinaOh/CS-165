#include "robot.h"
#include "point.h"
#include <iostream>
#include <string>

using namespace std;

void partI()
{
   Point p;

   p.setX(6);
   p.setY(7);

   cout << "This point should be: (6, 7). It is: ";
   p.display();
   cout << endl;

   cout << "Your point is x=" << p.getX() << " and y=" << p.getY() << endl;

   p.setX(-10);
   p.setY(15);

   cout << "This one should be: (1, 10). It is: ";
   p.display();
   cout << endl;

   Robot robot;
   robot.setPosition(p);
   robot.setEnergy(-10);

   cout << "Testing the robot, first with -10 energy, then with 100.\n";
   robot.display();
   cout << endl;

   robot.setEnergy(100);
   robot.display();
   cout << endl;
}

void partII()
{
   Point p1;
   cout << "Default Point constructor. It should be: (5, 5). It is: ";
   p1.display();
   cout << endl;

   Point p2(3, 7);
   cout << "Non-default Point constructor. It should be: (3, 7). It is: ";
   p2.display();
   cout << endl;

   Point p3(15, -5);
   cout << "Non-default Point constructor. It should be: (10, 1). It is: ";
   p3.display();
   cout << endl;
}

void partIII()
{
   Robot r1;
   cout << "Default constructor. Should be: (5, 5) - 100. It is: ";
   r1.display();
   cout << endl;

   Robot r2(13);
   cout << "Non-default constructor 1. Should be: (5, 5) - 13. It is: ";
   r2.display();
   cout << endl;

   Robot r3(-50);
   cout << "Non-default constructor 1. Should be: (5, 5) - 0. It is: ";
   r3.display();
   cout << endl;

   Point p(7, 3);
   Robot r4(p, 19);
   cout << "Non-default constructor 2. Should be: (7, 3) - 19. It is: ";
   r4.display();
   cout << endl;

}

int main()
{
   partI();
   partII();
   partIII();

   return 0;
}