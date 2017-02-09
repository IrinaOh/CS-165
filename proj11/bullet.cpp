#include "bullet.h"
#include "bullet.h"
#include "uiDraw.h"
#define M_PI 3.14159265358979323846 


// Put your bullet methods here
/*********************************************
* Initial constructor for the bullet
*********************************************/
void Bullet::draw()
{
	if (_alive)
	{
		drawDot(_v.getPoint());
		if (--_frames <= 0)
		{
			kill();
		}
	}

}

/*********************************************
* Shot the bullet
*********************************************/
void Bullet::fire(const Point& point, float angle)
{
	_v.setPoint(point);

	_v.setDx(-sin(2 * M_PI * (angle / 360)) * 5);
	_v.setDy(cos(2 * M_PI * (angle / 360)) * 5);

	_alive = true;
}