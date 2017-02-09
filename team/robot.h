#ifndef ROBOT_H
#define ROBOT_H

#include "point.h"

class Robot
{
  private:
   Point position;
   int energy;

  public:
   void display() const;
   Robot();
   Robot(int energy);
   Robot(Point p, int energy);
   Point getPosition() const { return position; }
   int getEnergy() const { return energy; }   
   void setPosition(Point position);
   void setEnergy(int energy);
};

#endif
