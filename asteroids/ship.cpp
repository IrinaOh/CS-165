#include "ship.h"
# define M_PI                3.14159265358979323846 

/*******************************************
* Move ship
********************************************/
void Ship::applyThrust()
{
	float x = (-sin(2 * M_PI * (_angle / 360)) * THRUST_AMOUNT);
	float y = (cos(2 * M_PI * (_angle / 360)) * THRUST_AMOUNT);

	_v.setX(_v.getX() + x);
	_v.setY(_v.getY() + y);
	_v.setDx(x);
	_v.setDy(y);

}

/*******************************************
* Bool thrust fire
********************************************/
bool Ship::thrust(bool value)
{
	thrust_ = value;
	return thrust_;
}

/*******************************************
* Draw ship
********************************************/
void Ship::draw()
{
	if (_alive)
		drawShip(_v.getPoint(), _angle, thrust_);
}

/*******************************************
* Advance Ship
********************************************/
void Ship::advance()
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