#include "flyingObject.h"

FlyingObject::FlyingObject(Point& position)
{
	setPoint(position);
	_alive = true;
	_angle = 0;
}

FlyingObject::FlyingObject(Point * position, Velocity & vel)
{
	_v.setPoint(position);
	_v = vel;
	_alive = true;
	_angle = 0;
}

void FlyingObject::advance()
{
	//point.setX(point.getX() + _v.getDx());
	//point.setY(point.getY() + _v.getDy());
	_v.advance();

	if (point.getX() > 200)
		point.setX(200);
	if (point.getX() < -200)
		point.setX(-200);
	if (point.getY() > 200)
		point.setY(200);
	if (point.getY() < -200)
		point.setY(-200);
}