#ifndef _VELOCITY_H
#define _VELOCITY_H

#include "point.h"
#include <iostream>
#include <cmath>
#include "rifle.h"

class Velocity
{
private:
	float _dx;
	float _dy;
	Point point; 
	
public:
	Velocity() : point(), _dx(0.0), _dy(0.0) {  }
	Velocity(float x, float y) : point(x, y), _dx(0.0), _dy(0.0) {  }
	
	Point getPoint()      const { Point point(getX(), getY()); return point; }
	Point getRiflePoint() const { Point point(getX() - 20, getY() + 20); return point; }
	void setPoint(Point value)  { point = value; }
	float getDx()         const { return _dx; }
	float getDy()         const { return _dy; }
	float getX()          const { return point.getX(); };
	float getY()          const { return point.getY(); };

	

	void setDx(float value) { _dx = value; }
	void setDy(float value) { _dy = value; }
	void advance();
	void setX(float x) { point.setX(x); };
	void setY(float y) { point.setY(y); };



};

#endif