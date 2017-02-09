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

class Rock : public FlyingObject
{
protected:
	int _radius;
	int _rotationSpeed;
public:
	int getRadius()           { return _radius;          }
	virtual void draw() = 0;
	void advance()            { FlyingObject::advance(); }
	void kill()               { _alive = false;          }
	Rock() : FlyingObject()   {                          }

};

class BigRock : public Rock
{
public:
	BigRock(const Velocity& startVelocity);	
	void draw();
};

class MediumRock : public Rock
{
public:
	MediumRock();  
	MediumRock(const Velocity& startVelocity); // : MediumRock() { setVelocity(startVelocity); }
	void draw();
};

class SmallRock : public Rock
{
public:
	SmallRock(); 
	SmallRock(const Velocity& startVelocity); //: SmallRock() { setVelocity(startVelocity); }
	void draw();
};

#endif /* rocks_h */
