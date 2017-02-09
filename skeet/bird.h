#ifndef BIRD_H
#define BIRD_H

#include "velocity.h"
#include "point.h"
#include "uiDraw.h"

class Bird
{
protected:
	Velocity _v;
	bool _alive;
public:
	Bird(const Point& value);                                         //+Bird(Point)
	Point getPoint() const                  { return _v.getPoint();}  //+getPoint() : Point
	Velocity & getVelocity()                { return _v;           }  //+ getVelocity() : Velocity
	bool isAlive();                                                   //+ isAlive() : bool
	void setPoint(const Point& value)       { _v.setPoint(value);  }  //+ setPoint(Point) : void
	void setVelocity(const Velocity& value) { _v = value;          }  //+ setVelocity(Velocity) : void
	void kill()                             { _alive = false;      }  //+ kill() : void 
	void advance();                                                   //+ advance() : void
	virtual void draw();                                              //+ draw() : void
	virtual int hit();
		              
};



#endif // BIRD_H