#include "rocks.h"

// Put your Rock methods here

BigRock::BigRock(Point & startPosition, Velocity & startVelocity)
{
	_v.setPoint(startPosition);
	_v = startVelocity;
	_rotationSpeed = BIG_ROCK_SPIN;
	_radius = BIG_ROCK_SIZE;
	_angle += _rotationSpeed;
	if (_angle >= 360)
		_angle -= 360;
}

void BigRock::draw() 
{ 
	if (_alive)
	drawLargeAsteroid(_v.getPoint(), _angle); 
}

//bool BigRock::split(FlyingObject* object, Game game)
//{
	//if (BigRock::split(object, game))
	//{
		//game.addRock(new MediumRock(_v.getPoint, 3);
		//game.addRock(new MediumRock(_v.getPoint(), _angle));
		//game.addRock(new SmallRock(_v.getPoint(), _angle));
		//return true;
	//}
	//return false;
//}
