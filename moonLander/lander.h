#ifndef LANDER_H
#define LANDER_H

#include "uiDraw.h"
#include "point.h"

class Lander
{
  private:
   Point coordinate;

  public:
   Lander() {  };
   void setFuel(int fuel) {  };
   void draw();
};

#endif
