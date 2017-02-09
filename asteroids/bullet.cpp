#include "bullet.h"
#include "bullet.h"
#include "uiDraw.h"
#define M_PI 3.14159265358979323846 

/*********************************************
* Initial constructor for the bullet
*********************************************/
void Bullet::draw()
{
	if (_alive)
	{
		drawDot(_v.getPoint());
		if (--_frames <= 0)
			kill();
	}
}

/*********************************************
* Shot the bullet
*********************************************/
void Bullet::fire(const Point& point, float angle, bool value)
{
	if (value == false)
		kill();
	if (value == true)
	{
		_v.setPoint(point);
		_v.setDx(-sin(2 * M_PI * (angle / 360)) * 5);
		_v.setDy(cos(2 * M_PI * (angle / 360)) * 5);
	}
}

/*********************************************
* Move the bullets
*********************************************/
void Bullet::advance()
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