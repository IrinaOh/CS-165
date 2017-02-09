###############################################################
# Program:
#      Project 13, Asteroids
#     Brother Falin, CS165
# Author:
#     Anderson Erichsen Fagundes
# Summary:
#     Create the game of asteroids
# Above and Beyond
#     - Keep track of score
#	  - Enhaced colors and fill
#     - Added star background
#     - Game over display
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: driver.o game.o uiInteract.o uiDraw.o point.o  flyingObject.o rocks.o velocity.o bullet.o ship.o 
	g++ driver.o game.o uiInteract.o uiDraw.o point.o flyingObject.o rocks.o velocity.o bullet.o ship.o $(LFLAGS)

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h point.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h point.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

game.o: game.cpp game.h uiDraw.h uiInteract.h velocity.h rocks.h ship.h bullet.h
	g++ -c game.cpp

driver.o: game.h driver.cpp uiInteract.h 
	g++ -c driver.cpp

flyingObject.o: flyingObject.cpp flyingObject.h velocity.h uiDraw.h
	g++ -c flyingObject.cpp 

rocks.o: rocks.cpp rocks.h flyingObject.h uiDraw.h
	g++ -c rocks.cpp

ship.o: ship.cpp ship.h flyingObject.h velocity.h 
	g++ -c ship.cpp

bullet.o: ship.cpp ship.h flyingObject.h velocity.h 
	g++ -c bullet.cpp

velocity.o: velocity.cpp velocity.h point.h
	g++ -c velocity.cpp

###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o


