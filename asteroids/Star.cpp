#include "Star.h"
#include "uiDraw.h"

#define STATECOUNT			10

// ******************************************************************************
void Star::draw()
{
	switch (state)
	{
	case STATE_ON:
		drawDot(pos, colour, colour, colour);
		if (stateCount-- < 0)
			state = STATE_NONE;

		break;

	case STATE_OFF:
		if (stateCount-- < 0)
			state = STATE_NONE;

		break;

	case STATE_NONE:
	default:
		state = (random(0, 100) < 50) ? STATE_ON : STATE_OFF;
		stateCount = (state == STATE_ON) ? random(400, 1000) : random(2, 5);
		break;
	}
}
