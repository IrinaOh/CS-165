#ifndef LANDER_H
#define LANDER_H

#include "velocity.h"
#include "uiDraw.h"
#include "point.h"

class Lander
{
  private:
   Velocity velocity;
   int _fuel;
   bool _alive;
   bool _landed;

  public:
   Lander();
   Point getPoint()       const   { return velocity.getPoint(); }
   Velocity getVelocity() const   { return velocity;            }  
	
   bool isAlive()                 { return _alive;       }
   bool isLanded()                { return _landed;      }
   int getFuel()                  { return _fuel;        }
   bool canThrust(); 

   void setFuel(int value)        { _fuel = value;       }
   void setAlive(bool value)      { _alive = value;      } // allow to keep moving
   void setLanded(bool value)     { _landed = value;     } // have its center within the horizontal boundaries of the platform.
   // be within 4 pixels vertically, above the platform.
   // arrive at the platform with a velocity of no more than 3 pixels 
   // per frame in any direction.

   void applyGravity(float value);     // Gravity on the moon can be modeled as 0.1 pixels per frame.
	
   void applyThrustLeft();     
   void applyThrustRight();   
   void applyThrustBottom();   

   void advance();
   void draw(); 
 
};

#endif
