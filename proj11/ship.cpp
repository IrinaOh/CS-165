#include "ship.h"
# define M_PI                3.14159265358979323846 

// Put your ship methods here

void Ship::applyThrust()
{
	float x = (-sin(2 * M_PI * (_angle / 360)) * 2.5);
	float y = (cos(2 * M_PI * (_angle / 360)) * 2.5);


	//_v.setDx(_v.getDx() + x);
	//_v.setDy(_v.getDy() + y);


	_v.setX(_v.getX() + x);
	_v.setY(_v.getY() + y);

	//_v.setDx(-sin(2 * M_PI * (_angle / 360)) * 5);
	//_v.setDy(cos(2 * M_PI * (_angle / 360)) * 5);

}

bool Ship::thrust(bool value)
{
	thrust_ = value;
	return thrust_;
}

void Ship::draw()
{
	if (_alive)
	{
		drawShip(_v.getPoint(), _angle, thrust_);
	}
}