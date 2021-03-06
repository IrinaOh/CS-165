#ifndef _VELOCITY_H
#define _VELOCITY_H

#include "point.h"
#include <iostream>

class Velocity
{
  private:
   float _dx;
   float _dy;
   Point point;

  public:
  Velocity() : point(), _dx(0.0), _dy(1.0) {  }
  Velocity(float x, float y) : point(x, y), _dx(0.0), _dy(0.0) {  }
	
   Point getPoint()      const { return point; }
   float getDx()         const { return _dx; }
   float getDy()         const { return _dy; }

   void setDx(float value) { _dx = value; }
   void setDy(float value) { _dy = value; }
   void advance();

};

#endif
