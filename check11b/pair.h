/*****************************************************
 * File: pair.h
 *
 * Purpose: Defines a Pair template class that can hold
 *   two items of arbitrary data types.
 ******************************************************/

#ifndef PAIR_H
#define PAIR_H

#include <iostream>
using namespace std;

template <class T, class T2>
class Pair
{
private:
	T _t1;
	T2 _t2;
public:
	T getFirst()     const           { return _t1;}
	void setFirst   (const T& t1)    { _t1 =   t1;}
	T2 getSecond()   const           { return _t2;}
	void setSecond  (const T2& t2)   { _t2 =   t2;}

	void display() { cout << _t1 << " - " << _t2; }
};




#endif // PAIR_H
