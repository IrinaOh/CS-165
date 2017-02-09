/*************************************************************
 * File: game.cpp
 * Author: Br. Burton
 *
 * Description: Contains the implementations of the
 *  method bodies for the game class.
 *
 * Please DO NOT share this code with other students from
 *  other sections or other semesters. They may not receive
 *  the same code that you are receiving.
 *************************************************************/

#include "game.h"

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "ground.h"
#include "lander.h"

using namespace std;


/******************************************
 * GAME :: JUST LANDED
 * Did we land successfully?
 ******************************************/
bool Game :: justLanded() const
{
   bool landed = false;
   
   Point platformCenter = ground.getPlatformPosition();
   int width = ground.getPlatformWidth();

   float xDiff = lander.getPoint().getX() - platformCenter.getX();
   float yDiff = lander.getPoint().getY() - platformCenter.getY();

   float margin = width / 2.0;
   
   if (fabs(xDiff) < margin)
   {
      // between edges
      
      if (yDiff < 4 && yDiff >= 0)
      {
         // right above it
         
         if (fabs(lander.getVelocity().getDx()) < 3 && fabs(lander.getVelocity().getDy()) < 3)
         {
            // we're there!
            landed = true;
         }
      }
   }
 
   return landed;
}

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game :: advance()
{
   cout << "Advance\n";
   
   
   if (lander.isAlive() && !lander.isLanded())
   {
      // advance the lander
      lander.applyGravity(GRAVITY_AMOUNT);
      lander.advance();
   
      // check for crash
      if (!ground.isAboveGround(lander.getPoint()))
      {
         lander.setAlive(false);
      }
   
      // check for just landed
      if (justLanded())
      {
         lander.setLanded(true);
      }
   }
   
}

/***************************************
 * GAME :: HANDLE INPUT
 * accept input from the user
 ***************************************/
void Game :: handleInput(const Interface & ui)
{
   if (lander.isAlive() && !lander.isLanded() && lander.canThrust())
   {
   
      if (ui.isDown())
      {
         lander.applyThrustBottom();
      }
      
      if (ui.isLeft())
      {
         lander.applyThrustLeft();
      }
      
      if (ui.isRight())
      {
         lander.applyThrustRight();
      }

      // reset game here
      if (ui.isSpace())
      {
         
      }
      
   }
   
}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game :: draw(const Interface & ui)
{
   lander.draw();
   
   Point asteroidLocation;
   asteroidLocation.setX(topLeft.getX() + 100);
   asteroidLocation.setY(topLeft.getY() - 20);

   drawSmallAsteroid(asteroidLocation, 0);

   Point textLocation;
   textLocation.setX(topLeft.getX() + 5);
   textLocation.setY(topLeft.getY() - 50);

   if (lander.isLanded())
   {
      //drawText(Point(), "Press SPACE to restart the game");
      drawText(textLocation, "You have successfully landed!");
	  
   }
   
   if (!lander.isAlive())
   {
      drawText(textLocation, "You have crashed!"); 
      //drawText(Point(), "Press SPACE to restart the game");
      drawLanderFlames(lander.getPoint(), true, true, true);
   }
   
   if (lander.canThrust())
   {
      drawLanderFlames(lander.getPoint(), ui.isDown(), ui.isRight(), ui.isLeft());
   }
   
   Point fuelLocation;
   fuelLocation.setX(topLeft.getX() + 5);
   fuelLocation.setY(topLeft.getY() - 5);
   
   drawNumber(fuelLocation, lander.getFuel());

   // draw ground
   ground.draw();
}

