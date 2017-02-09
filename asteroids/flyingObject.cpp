#include "flyingObject.h"

/*******************************************
* Initial Constructor
********************************************/
FlyingObject::FlyingObject(Point& position)
{
	setPoint(position);
	_alive = true;
	_angle = 0;
}

/*******************************************
* Constructor with position and Velocity
********************************************/
FlyingObject::FlyingObject(Point * position, Velocity & vel)
{
	_v.setPoint(position);
	_v = vel;
	_alive = true;
	_angle = 0;
}

/*******************************************
* Advance flying objects
********************************************/
void FlyingObject::advance()
{
	_v.advance();
	if (_v.getX() > 200)
		_v.setX(-200);
	if (_v.getX() < -200)
		_v.setX(200);
	if (_v.getY() > 200)
		_v.setY(-200);
	if (_v.getY() < -200)
		_v.setY(200);
}