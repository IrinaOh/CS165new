/*****************************************************
 * File: pair.h
 *
 * Purpose: Defines a Pair template class that can hold
 *   two items of arbitrary data types.
 ******************************************************/

#ifndef PAIR_H
#define PAIR_H

#include<iostream>
#include<string>
#include<assert.h>

template<typename T, typename S>

// TODO: Fill in this class
// Put all of your method bodies right in this file

class Pair {

private:
	T first;
	S second;

public:
	//getters
	T getFirst();
	S getSecond();

	//setters
	void setFirst(T value);
	void setSecond(S value);

	//display
	void display();

};

template<typename T, typename S>
T Pair<T, S>::getFirst()
{
	return first;
}

template<typename T, typename S>
S Pair<T, S>::getSecond() 
{
	return second;
}

template<typename T, typename S>
void Pair<T, S>::setFirst(T value) 
{
	first = value;
}

template<typename T, typename S>
void Pair<T, S>::setSecond(S value) {
	second = value;
}

template<typename T, typename S>
void Pair<T, S>::display() {
	std::cout << first << " - " << second;
}

#endif // PAIR_H


