#ifndef TOUGHBIRD_H
#define TOUGHBIRD_H

#include "bird.h"
#include "point.h"
#include "uiDraw.h"

class ToughBird : public Bird
{
private:
	int health;
public:
   ToughBird() : Bird(getPoint()), health(3) { } 
   int getScore();
   void draw();
   int hit();

};
#endif//TOUGHBIRD_H
