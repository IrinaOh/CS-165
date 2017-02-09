#ifndef SACREDBIRD_H
#define SACREDBIRD_H
#include "bird.h"
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

class SacredBird : public Bird
{
public:
   SacredBird() : Bird(getPoint()) { }
   int hit() { kill();  return -10; }
   void draw();

};

#endif //SACREDBIRD_H 
