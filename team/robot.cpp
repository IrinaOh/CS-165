#include "robot.h"
#include <iostream>
using namespace std;


void Robot :: display() const
{
   position.display(); 

   cout << " - Energy: " << getEnergy();
}


Robot :: Robot()
{
   energy = 100;
}

Robot :: Robot(int energy)
{
   setEnergy(energy);
}

Robot :: Robot(Point p, int energy)
{
   setPosition(p);
   setEnergy(energy);
}


void Robot :: setPosition(Point position)
{
   this->position = position;
}

void Robot :: setEnergy(int energy)
{
   if (energy < 0)
   {
      this->energy = 0;
   }
   else
   {
      this->energy = energy;
   }
}
