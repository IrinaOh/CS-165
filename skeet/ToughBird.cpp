#include "ToughBird.h"



int ToughBird::getScore()
{
   if (health > 0)
      return 0;
   else
      return 2;
}

void ToughBird::draw()
{
   if (_alive)
   {
      drawToughBird(_v.getPoint(),15, 3);
	  _v.setDx(1); //to move slower than the others
	  _v.setDy(1); //to move slower than the others
   }
}

int ToughBird::hit()
{
	--health;
	if (health < 1)
	{
		kill();
		return 3;
	}
	else
		return 1;
}