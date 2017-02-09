###############################################################
# Program:
#     Project 07, Moon Lander
#     Brother Falin, CS165
# Author:
#     Anderson Erichsen Fagundes
# Summary:
#      MoonLander game 
# Above and Beyond
#     When the lander hits something, it is set on fire
#     The mountain has a blue color now
#     There is an astorid add to the back ground now
#     The place text is displayed in a different coordinate
###############################################################

all: a.out
LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main Moon Lander game
###############################################################
a.out: driver.o ground.o game.o uiInteract.o uiDraw.o point.o lander.o velocity.o 
	g++ -o a.out lander.o driver.o ground.o game.o uiInteract.o uiDraw.o point.o velocity.o $(LFLAGS) 
	tar -j -cf moonLander.tar makefile *.h *.cpp

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

ground.o: ground.cpp ground.h
	g++ -c ground.cpp

game.o: game.h game.cpp uiDraw.h uiInteract.h point.h ground.h lander.h
	g++ -c game.cpp

driver.o: driver.cpp game.h uiInteract.h
	g++ -c driver.cpp

lander.o: lander.h lander.cpp point.h velocity.h uiDraw.h
	g++ -c lander.cpp

velocity.o: velocity.h velocity.cpp point.h
	g++ -c velocity.cpp

###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o *.tar
