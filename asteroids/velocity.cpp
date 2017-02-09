#include "velocity.h"

/*******************************************
* Advance velocity
********************************************/
void Velocity::advance()
{
	point.addX(_dx);
	point.addY(_dy);
}