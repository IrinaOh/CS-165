###############################################################
# Program:
#     Assignment 05, Order Tracking
#     Brother Falin, CS165
# Author:
#     Anderson Erichsen Fagundes
# Summary:
#     Create classes to manage orders and customers
###############################################################


all : a.out

a.out : product.o address.o customer.o order.o assign05.cpp 
	g++ product.o address.o customer.o order.o assign05.cpp 

address.o : address.h address.cpp
	g++ -o address.o -c address.cpp

customer.o : customer.h customer.cpp address.o
	g++ -o customer.o -c customer.cpp address.o

product.o : product.h product.cpp
	g++ -o product.o -c product.cpp

order.o : order.h order.cpp customer.o product.o
	g++ -o order.o -c order.cpp customer.o product.o

clean : 
	rm *.o a.out