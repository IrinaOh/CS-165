#include "flyingObject.h"
#include "velocity.h"

#ifndef ship_h
#define ship_h

#define SHIP_SIZE 10

#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5



// Put your Ship class here

class Ship : public FlyingObject
{
private:
	float _angle;
	float _thrust;
	bool thrust_;
	Velocity _v;
	bool _alive;

public:
	Ship() : FlyingObject() { _angle = 0; _thrust = THRUST_AMOUNT; _alive = true; }

	bool thrust(bool value);
	float getAngle()            { return _angle;           }
	void rotateLeft()           { _angle += ROTATE_AMOUNT; }
	void rotateRight()          { _angle -= ROTATE_AMOUNT; }
	void advance()              { FlyingObject::advance(); }  // { _v.advance(); } 
	void draw();
	Point getPoint()            { return _v.getPoint();    }
	void applyThrust();
	void kill()                 { _alive = false;          }


};


#endif /* ship_h */