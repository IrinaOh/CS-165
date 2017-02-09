###############################################################
# Program:
#     Checkpoint 06a, Makefiles
#     Brother Falin, CS165
# Author:
#     Anderson Erichsen Fagundes
# Summary:
#     Summaries are not necessary for checkpoint assignments.
###############################################################

all: a.out
# Insert your rule for a.out here:
a.out : robot.o point.o check06a.o 
	g++ robot.o point.o check06a.o 

# Insert your rule for point.o here:
point.o : point.h point.cpp
	 g++ -o point.o -c point.cpp

# Insert your rule for robot.o here:
robot.o : robot.h robot.cpp point.o
	 g++ -o robot.o -c robot.cpp point.o

# Insert your rule for check06a.o here:
check06a.o : check06a.cpp robot.o
	 g++ -o check06a.o -c robot.o check06a.cpp 

clean : 
	rm *.o a.out