#include "velocity.h"

void Velocity::advance()
{
	point.addX(_dx);
	point.addY(_dy);
}

Point Velocity::getRiflePoint()
{ 
		Point point(getX() - 20, getY() + 20);
		return point;
}