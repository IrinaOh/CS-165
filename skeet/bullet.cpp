#include "point.h"
#include "velocity.h"
#include "uiDraw.h"
#include "bullet.h"
#include <math.h>
# define M_PI 3.14159265358979323846 

/*********************************************
* Initial constructor for the bullet
*********************************************/
void Bullet::draw()
{
	if (_alive)
	{
		drawDot(_v.getPoint());
		
	}
		
}

/*********************************************
* Shot the bullet
*********************************************/
void Bullet::fire(Point point, float angle)
{
	_v.setPoint(point);
	drawLanderFlames((_v.getRiflePoint()), true, true, true);
	_v.setDx(-cos((M_PI / 180) * (angle)) * 10.0); 
	_v.setDy(sin((M_PI / 180) * (angle)) * 10.0);

	_alive = true;
}