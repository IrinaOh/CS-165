#ifndef flyingObject_h
#define flyingObject_h
#include "velocity.h"
#include "uiDraw.h"


class FlyingObject
{
protected:
	Velocity _v;
	bool _alive;
	int _angle;
	Point point;

public:
	FlyingObject()                                  { _alive = true; _angle = 0; }
	FlyingObject(Point & position);
	FlyingObject(Point * position, Velocity & vel);
	
	Point getPoint() /*const*/                          {    return _v.getPoint();   }  
	Velocity & getVelocity()                        {    return _v;              }  
	bool isAlive()                                  {    return _alive;          }

	void setPoint(const Point& value)               {    _v.setPoint(value);     }  
	void setVelocity(const Velocity& value)         {    _v = value;             }  
	void kill()                                     {    _alive = false;         }

	virtual void advance();// {    _v.advance();           }
	virtual void draw() = 0;
	//virtual int hit();

};



#endif /* flyingObject_h */
