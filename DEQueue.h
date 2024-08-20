#pragma once
#ifndef DEQUEUE_H
#define DEQUEUE_H

#include "LinkedQueue.h"
#include <iostream>
using namespace std;
template <typename T>
class DEQueue :public LinkedQueue<T>
{
public:
	DEQueue();
	bool enqueuefront(T& frntEntry);
	bool enqueueboth(T& backEntry, T& frntEntry);
	bool dequeueback(T& backEntry);
	bool dequeueboth(T& backEntry, T& frntEntry);
	bool peekback(T& backEntry);
	bool peekboth(T& backEntry, T& frntEntry);
	~DEQueue();
	//copy constructor
	DEQueue(DEQueue<T>& LQ);
};
/////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
DEQueue<T>::DEQueue() : LinkedQueue<T>()
{}

/////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
bool DEQueue<T>::enqueuefront(T& frntEntry)
{
	if (this->frontPtr == nullptr)
	{
		this->count++;
		this->enqueue(frntEntry);
		return true;
	}
	Node<T>* x(frntEntry);
	x->setNext(this->frontPtr);
	this->frontPtr = x;
	this->count++;
	return true;
}


template <typename T>
bool DEQueue<T>::enqueueboth(T& backEntry,T& frntEntry)
{
	return (this->enqueue(backEntry) && this->enqueuefront(frntEntry));
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////


template <typename T>
bool DEQueue<T>::dequeueback(T& backEntry)
{
	if (this->isEmpty())
		return false;
	if (this->count == 1)
	{
		backEntry = this->backPtr->getItem();
		delete this->backPtr;
		this->backPtr = this->frontPtr = nullptr;
		this->count--;
		return true;
	}
	Node<T>* mover = this->frontPtr;
	if (this->count == 2)
	{
		backEntry = this->backPtr->getItem();
		this->backPtr = this->frontPtr;
		this->frontPtr->setNext(nullptr);
		this->count--;
		return true;
	}
	while (mover->getNext()->getNext() != nullptr)
	{
		mover = mover->getNext();
	}
	backEntry = this->backPtr->getItem();
	delete this->backPtr;
	this->backPtr = mover;
	this->backPtr->setNext(nullptr);
	this->count--;
	return true;
}

template <typename T>
bool DEQueue<T>::dequeueboth(T& backEntry, T& frntEntry)
{
	// when i removed this and tried the test code it gave me a runtime error that i acutually didn't have time to understand
	// but since i still had to remove it for EG to work so i removed it  
	/*if (this->count < 2)
	{
		return false;
	}*/
	bool x = dequeueback(backEntry);
	bool y = this->dequeue(frntEntry);
	if (x == false)
	{
		backEntry = nullptr;
	}
	if (y == false)
	{
		frntEntry = nullptr;
	}
	if (backEntry == frntEntry)
	{
		backEntry = nullptr;
	}
	return (x && y);
}

/////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
bool DEQueue<T>::peekback(T& backEntry)
{
	if (this->isEmpty())
		return false;
	backEntry = this->backPtr->getItem();
}

template <typename T>
bool DEQueue<T>::peekboth(T& backEntry, T&frntEntry)
{
	return(peekback(backEntry) && this->peek(frntEntry));
}

///////////////////////////////////////////////////////////////////////////////////

template <typename T>
DEQueue<T>::~DEQueue()
{
	//Free all nodes in the queue
	T temp;
	while (this->dequeue(temp));

}

/////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
DEQueue<T>::DEQueue(DEQueue<T>& LQ)
{
	T x;
	LinkedQueue<T> y;
	while (this->dequeue(x))
	{}
	while (LQ.dequeue(x))
	{
		this->enqueue(x);
		y.enqueue(x);
	}
	while (y.dequeue(x))
	{
		LQ.enqueue(x);
	}
}

#endif