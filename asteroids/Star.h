#pragma once

#include "point.h"
#include "uiDraw.h"

#define STATE_ON			1
#define STATE_OFF			2
#define STATE_NONE			3


class Star
{
public:
	Star(int x, int y) : pos((double)x, (double)y), state(STATE_ON) 
	{
		stateCount = random(1, 1000);
		colour = random(0.1, 0.5);
	};

	~Star() {};

	void draw();

private:
	Point pos;
	int state;
	int stateCount;
	double colour;
};

