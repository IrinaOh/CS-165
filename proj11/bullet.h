#ifndef bullet_h
#define bullet_h

#define BULLET_SPEED 5
#define BULLET_LIFE 40
// Put your Bullet class here

#include "velocity.h"

class Bullet
{
private:
	bool _alive;
	Velocity _v;
	int _frames;

public:
	Bullet() : _alive(true)                  { _frames = 40; }           //+ Bullet()
	Point getPoint() const                   { return _v.getPoint(); }   //+ getPoint() : Point
	Velocity & getVelocity()                 { return _v; }              //+ getVelocity() : Velocity
	bool isAlive()                           { return _alive; }          //+ isAlive() : bool //TODO Die after 40 frames
	void setPoint(const Point& value)        { _v.setPoint(value); }     //+ setPoint(Point) : void
	void setVelocity(const Velocity& value)  { _v = value; }             //+ setVelocity(Velocity) : void
	void kill() { _alive = false; }                                      //+ kill() : void
	void advance() { _v.advance(); }                                     //+ advance() : void
	void draw();                                                         //+ draw() : void
	void fire(const Point& Point, float angle);                          //+ fire(point : Point, angle : float) : void

};
#endif /* bullet_h */
