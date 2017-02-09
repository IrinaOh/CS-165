###############################################################
# Program:
#     Project 07, Moon Lander
#     Brother Falin, CS165
# Author:
#     Anderson Erichsen Fagundes
# Summary:
#     MoonLander milestone  
# Above and Beyond
#     When you submit your final project (not for milestones),
#     list anything here that you did to go above and beyond
#     the base requirements for your project.
###############################################################

all: a.out
LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main Moon Lander game
###############################################################
a.out: driver.o ground.o game.o uiInteract.o uiDraw.o point.o lander.o
	g++ lander.o driver.o ground.o game.o uiInteract.o uiDraw.o point.o $(LFLAGS)
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
	g++ -o uiInteract.o-c uiInteract.cpp

point.o: point.cpp point.h
	g++ -o point.o-c point.cpp

ground.o: ground.cpp ground.h
	g++ -o ground.o-c ground.cpp

game.o: game.h game.cpp uiDraw.h uiInteract.h point.h ground.h
	g++ -o game.o-c game.cpp

driver.o: driver.cpp game.h uiInteract.h
	g++ -o driver.o-c driver.cpp

lander.o: lander.h lander.cpp
	g++ -o lander.o -c lander.cpp

###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o *.tar
