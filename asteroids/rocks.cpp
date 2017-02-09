#include "rocks.h"

/*******************************************
* Draw big asteroid
********************************************/
void BigRock::draw() 
{ 
	if (_alive)
	{
		_angle += BIG_ROCK_SPIN;
		if (_angle >= 360)
			_angle -= 360;
		drawLargeAsteroid(_v.getPoint(), _angle); 
	}
}

/*******************************************
* Big Rock constructor
********************************************/
BigRock::BigRock(const Velocity& startVelocity) : Rock()
{
	setVelocity(startVelocity);
	_v = startVelocity;
	_rotationSpeed = BIG_ROCK_SPIN;
	_radius = BIG_ROCK_SIZE;
	_angle = 0;
	_angle += _rotationSpeed;
	if (_angle >= 360)
		_angle -= 360;
}

/*******************************************
* Medium rock constructor
********************************************/
MediumRock::MediumRock() : Rock() 
{
	_radius = MEDIUM_ROCK_SIZE; 
	_rotationSpeed = MEDIUM_ROCK_SPIN; 
	_angle += _rotationSpeed;
	if (_angle >= 360) 
		_angle -= 360; 
}

MediumRock::MediumRock(const Velocity& startVelocity) : Rock()
{
	_radius = MEDIUM_ROCK_SIZE;
	_rotationSpeed = MEDIUM_ROCK_SPIN;
	_angle += _rotationSpeed;
	if (_angle >= 360)
		_angle -= 360;
	setVelocity(startVelocity);
}

/*******************************************
* Medium Rock draw
********************************************/
void MediumRock::draw()
{
	if (_alive)
		_angle += MEDIUM_ROCK_SPIN;
	if (_angle >= 360)
		_angle -= 360;
	drawMediumAsteroid(_v.getPoint(), _angle); 
}

/*******************************************
* Small Rock constructor
********************************************/
SmallRock::SmallRock() : Rock()
{
	_radius = SMALL_ROCK_SIZE;
	_rotationSpeed = SMALL_ROCK_SPIN;
	_angle += _rotationSpeed;
	if (_angle >= 360)
		_angle -= 360;
}

SmallRock::SmallRock(const Velocity& startVelocity) : Rock()
{
	_radius = SMALL_ROCK_SIZE;
	_rotationSpeed = SMALL_ROCK_SPIN;
	_angle += _rotationSpeed;
	if (_angle >= 360)
		_angle -= 360;
	setVelocity(startVelocity);
}
/*******************************************
* Small Rock draw
********************************************/
void SmallRock::draw()
{
	if (_alive)
		_angle += SMALL_ROCK_SPIN;
	if (_angle >= 360)
		_angle -= 360;
	drawSmallAsteroid(_v.getPoint(), _angle); 
}