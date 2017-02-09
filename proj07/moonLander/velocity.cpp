#include "velocity.h"

void Velocity::advance()
{
   point.addX(_dx);
   point.addY(_dy);
}
