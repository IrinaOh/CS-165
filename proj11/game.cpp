/*********************************************************************
 * File: game.cpp
 * Description: Contains the implementaiton of the game class
 *  methods.
 *
 *********************************************************************/

#include "game.h"
#include "uiInteract.h"
#include "flyingObject.h"
#define OFF_SCREEN_BORDER_AMOUNT 5


// These are needed for the getClosestDistance function...
#include <limits>
#include <algorithm>
using namespace std;

Game::Game(Point topLeft, Point bottomRight)
{
	this->topLeft = topLeft;
	this->bottomRight = bottomRight;
	createStartingRocks(5);

}

void Game::createStartingRocks(int count)
{
	Velocity startVelocity;
	for (int i = 0; i < count; i++)
	{
		startVelocity.setX(random(topLeft.getX(), bottomRight.getX())); //Position
		startVelocity.setY(random(bottomRight.getY(), topLeft.getY())); //Position
		startVelocity.setDx(random(-1.0, 1.0));
		startVelocity.setDy(random(-1.0, 1.0));
		Rock* theRock = new BigRock(startVelocity);
		_rocks.push_back(theRock);
	}

}
//void Game::addRock(Rock * rock)
//{
//	_rocks.push_back(rock);
//}

void Game::advance()
{
	advanceRock();
	advanceBullets();
	handleCollisions();
	ship.advance(); // not making difference here
}

void Game::advanceRock()
{
	for (int i = 0; i < _rocks.size(); i++)
	{
		_rocks[i]->advance();
		//if (!isOnScreen(_rocks[i].getPoint())
		{

		}
	}
}

void Game::advanceBullets()
{
	// Move each of the bullets forward if it is alive
	for (int i = 0; i < bullets.size(); i++)
		//for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].isAlive())
		{
			// this bullet is alive, so tell it to move forward
			bullets[i].advance();

			//Kill bullets if the move more then 40 frames
			if (!isOnScreen(bullets[i].getPoint()))
			{
				// the bullet has left the screen
				//bullets[i].kill();
			}

		}
	}
}

void Game::handleInput(const Interface & ui)
{
	if (ui.isUp())
	{
		ship.applyThrust();
	}

	if (ui.isLeft())
	{
		ship.rotateLeft();
	}

	if (ui.isRight())
	{
		ship.rotateRight();
	}
	
	if (ui.isSpace())
	{
		if (ship.isAlive())
		{
			Bullet newBullet;
			newBullet.fire(ship.getPoint(), ship.getAngle());
			bullets.push_back(newBullet);
		}
	}

}

void Game::draw(const Interface & ui)
{
	for (int i = 0; i < _rocks.size(); i++)
	{
		_rocks[i]->draw();
	}
	
	ship.draw();
	if (!ui.isUp())
	{
		bool value = false;
		ship.thrust(value);
	}
	if (ui.isUp())
	{
		bool value = true;
		ship.thrust(value);
	}
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].isAlive())
		{
			bullets[i].draw();
		}
	}

}

void Game::handleCollisions()
{
	for (int i = 0; i < bullets.size(); i++)
		for (int j = 0; j < _rocks.size(); j++)
		{
			if (bullets[i].isAlive() && _rocks[j] != NULL && _rocks[j]->isAlive())
			{

				//std::cout << "Bulltet and Rock alive " << std::endl;
				if (fabs(bullets[i].getPoint().getX() - _rocks[j]->getPoint().getX()) < CLOSE_ENOUGH
					&& fabs(bullets[i].getPoint().getY() - _rocks[j]->getPoint().getY()) < CLOSE_ENOUGH)
				{
					(_rocks[j])->kill();
					//score += points;
					bullets[i].kill();
				}
			}
		}
	for (int j = 0; j < _rocks.size(); j++)
	{
		if (ship.isAlive() && _rocks[j] != NULL && _rocks[j]->isAlive())
		{

			//std::cout << "Bulltet and Rock alive " << std::endl;
			if (fabs(ship.getPoint().getX() - _rocks[j]->getPoint().getX()) < CLOSE_ENOUGH
				&& fabs(ship.getPoint().getY() - _rocks[j]->getPoint().getY()) < CLOSE_ENOUGH)
			{
				(_rocks[j])->kill();
				//score += points;
				ship.kill();
			}
		}
	}
}



// You may find this function helpful...

/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/
/*
float Game :: getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const
{
   // find the maximum distance traveled
   float dMax = max(abs(obj1.getVelocity().getDx()), abs(obj1.getVelocity().getDy()));
   dMax = max(dMax, abs(obj2.getVelocity().getDx()));
   dMax = max(dMax, abs(obj2.getVelocity().getDy()));
   dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.
   
   float distMin = std::numeric_limits<float>::max();
   for (float i = 0.0; i <= dMax; i++)
   {
      Point point1(obj1.getPoint().getX() + (obj1.getVelocity().getDx() * i / dMax),
                     obj1.getPoint().getY() + (obj1.getVelocity().getDy() * i / dMax));
      Point point2(obj2.getPoint().getX() + (obj2.getVelocity().getDx() * i / dMax),
                     obj2.getPoint().getY() + (obj2.getVelocity().getDy() * i / dMax));
      
      float xDiff = point1.getX() - point2.getX();
      float yDiff = point1.getY() - point2.getY();
      
      float distSquared = (xDiff * xDiff) +(yDiff * yDiff);
      
      distMin = min(distMin, distSquared);
   }
   
   return sqrt(distMin);
}
*/

bool Game::isOnScreen(const Point & point)
{
	return (point.getX() >= topLeft.getX() - OFF_SCREEN_BORDER_AMOUNT
		&& point.getX() <= bottomRight.getX() + OFF_SCREEN_BORDER_AMOUNT
		&& point.getY() >= bottomRight.getY() - OFF_SCREEN_BORDER_AMOUNT
		&& point.getY() <= topLeft.getY() + OFF_SCREEN_BORDER_AMOUNT);
}