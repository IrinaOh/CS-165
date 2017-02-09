#ifndef BULLET_H
#define BULLET_H

#include "velocity.h"

class Bullet
{
private:
	bool _alive;
	Velocity _v;

public:
	Bullet() : _alive(true)           {                       }           //+ Bullet()
	Point getPoint() const            { return _v.getPoint(); }           //+ getPoint() : Point
	Velocity & getVelocity()          { return _v;            }           //+ getVelocity() : Velocity
	bool isAlive()                    { return _alive;        }           //+ isAlive() : bool
	void setPoint(const Point& value)       { _v.setPoint(value); }       //+ setPoint(Point) : void
	void setVelocity(const Velocity& value) { _v = value;         }       //+ setVelocity(Velocity) : void
	void kill()                             { _alive = false;     }       //+ kill() : void
	void advance()                          { _v.advance();       }       //+ advance() : void
	void draw();                                                          //+ draw() : void
	void fire(Point Point, float angle);                                  //+ fire(point : Point, angle : float) : void
};


#endif // BULLET_H