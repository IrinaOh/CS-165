#ifndef rocks_h
#define rocks_h

#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10

#include "flyingObject.h"
#include "uiDraw.h"
#include "vector"
//#include "game.h"


class Rock : public FlyingObject
{
protected:
	int _radius;
	int _rotationSpeed;
	
public:
	virtual void draw() = 0;
	void advance() { FlyingObject::advance(); }
	Rock() : FlyingObject() {}

};

class BigRock : public Rock
{
public:
	BigRock(Point & startPosition, Velocity& startVelocity);
	BigRock(const Velocity& startVelocity) : Rock() { setVelocity(startVelocity); }
	void draw();
	//bool split(FlyingObject* object, Game game);
};

class MediumRock : public Rock
{
public:
	MediumRock() : Rock() { _radius = MEDIUM_ROCK_SIZE; _rotationSpeed = MEDIUM_ROCK_SPIN; _angle += _rotationSpeed; if (_angle >= 360) _angle -= 360; }
	MediumRock(const Velocity& startVelocity) : Rock() { setVelocity(startVelocity); }
	void draw() { drawMediumAsteroid(_v.getPoint(), _angle); }
};

class SmallRock : public Rock
{
public:
	SmallRock() : Rock() { _radius = SMALL_ROCK_SIZE; _rotationSpeed = SMALL_ROCK_SPIN; _angle += _rotationSpeed; if (_angle >= 360) _angle -= 360; }
	SmallRock(const Velocity& startVelocity) : Rock() { setVelocity(startVelocity); }
	void draw() { drawSmallAsteroid(_v.getPoint(), _angle); }
};


#endif /* rocks_h */
