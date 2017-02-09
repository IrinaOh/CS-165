/*********************************************************************
* File: game.h
* Description: Defines the game class for Asteroids
*
*********************************************************************/

#ifndef GAME_H
#define GAME_H
#include "uiInteract.h"
#include "velocity.h"
#include "uiDraw.h"
#include "rocks.h"
#include "ship.h"
#include "bullet.h"
#include <vector>
#include <list>
#define CLOSE_ENOUGH 15

using namespace std;

class Game
{
private:
	Point topLeft;
	Point bottomRight;
	Point point;
	Point pointStar[100];
	Velocity _v;
	vector<Rock*> _rocks;
	Ship ship;
	vector<Bullet> bullets;
	int points;
	int score;
public:
	Game                     (Point topLeft, Point bottomRight);
	void advance             (                                );
	void advanceRock         (                                );
	void handleInput         (const Interface& ui             );
	void draw                (const Interface& ui             );
	void createStartingRocks (int count                       );
	bool isOnScreen          (const Point & point             );
	void advanceBullets      (                                );
	void handleCollisions    (                                );
	void addRock             (Rock * rock                     );
	void splitBigRock        (BigRock * rock                  );
	void splitMediumRock     (MediumRock * rock               );
	void cleanUpZombies      (                                );
	void addBackGround       (                                );
};

#endif /* GAME_H */
