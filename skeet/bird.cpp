#include "bird.h"

/*********************************************
* Initial constructor to draw bird and set
* velocity
*********************************************/
Bird::Bird(const Point& value)
{
	_alive = true;

	_v.setX(-200);
	_v.setDx(random(2, 5));
	_v.setY(random((-200 / 2), (200 / 2)));
	int dynow = random(2, 5);
	if (_v.getY() > 0)  
		_v.setDy(-dynow);
	else               
		_v.setDy(dynow);
}

/*********************************************
* Advance the bird through the frames
*********************************************/
void Bird::advance()
{
	_v.advance(); 
}

/*********************************************
* Check to see if bird is alive
*********************************************/
bool Bird::isAlive()
{
	return _alive;
}

/*********************************************
* Give the shape of the bird
*********************************************/
void Bird::draw()
{
	if (_alive)
		drawCircle(_v.getPoint(), 15);
}

/*********************************************
* Kill the bird and add points
*********************************************/
int Bird::hit()
{
	if (_alive)
	{
		kill();
		return 1;
	}
	return 0;
}