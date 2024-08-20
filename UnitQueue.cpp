#include "UnitQueue.h"
#include <iostream>
#include "Node.h"
using namespace std;

void UnitQueue::PrintQueue()
{
	Unit* K;
	UnitQueue Qcopy(*this);
	Node <Unit*>* follow = frontPtr;
	cout << "[";
	while (Qcopy.dequeue(K))
	{
		if (follow->getNext() == nullptr)
		{
			K->Print();

		}
		else
		{
			K->Print();
			cout << ", ";

		}
		follow = follow->getNext();

	}
	cout << "]" << endl;

}

float UnitQueue::getEarthDf(float& y)
{
	float x = 0;
	//y = 0;
	Node <Unit*>* follow = frontPtr;
	while (follow)
	{
		if (follow->getItem()->GetType() == "ES" || follow->getItem()->GetType() == "ET" || follow->getItem()->GetType() == "Earth_Gunnery")
		{
			x = x + follow->getItem()->GetDf();
			y = y + 1;
		}
		follow = follow->getNext();
	}
	return x;
}

float UnitQueue::getEarthDd(float& y)
{
	float x = 0;
	//y = 0;
	Node <Unit*>* follow = frontPtr;
	while (follow)
	{
		if (follow->getItem()->GetType() == "ES" || follow->getItem()->GetType() == "ET" || follow->getItem()->GetType() == "Earth_Gunnery")
		{
			x = x + follow->getItem()->GetDd();
			y = y + 1;
		}
		follow = follow->getNext();
	}
	return x;
}

float UnitQueue::getEarthDb(float& y)
{
	float x = 0;
	//y = 0;
	Node <Unit*>* follow = frontPtr;
	while (follow)
	{
		if (follow->getItem()->GetType() == "ES" || follow->getItem()->GetType() == "ET" || follow->getItem()->GetType() == "Earth_Gunnery")
		{
			x = x + follow->getItem()->GetDb();
			y = y + 1;
		}
		follow = follow->getNext();
	}
	return x;
}

float UnitQueue::getAlienDf(float& y)
{
	float x = 0;
	//y = 0;
	Node <Unit*>* follow = frontPtr;
	while (follow)
	{
		if (follow->getItem()->GetType() == "AS" || follow->getItem()->GetType() == "Alien_Monster" || follow->getItem()->GetType() == "Drone")
		{
			x = x + follow->getItem()->GetDf();
			y = y + 1;
		}
		follow = follow->getNext();
	}
	return x;
}

float UnitQueue::getAlienDd(float& y)
{
	float x = 0;
	//y = 0;
	Node <Unit*>* follow = frontPtr;
	while (follow)
	{
		if (follow->getItem()->GetType() == "AS" || follow->getItem()->GetType() == "Alien_Monster" || follow->getItem()->GetType() == "Drone")
		{
			x = x + follow->getItem()->GetDd();
			y = y + 1;
		}
		follow = follow->getNext();
	}
	return x;
}

float UnitQueue::getAlienDb(float& y)
{
	float x = 0;
	//y = 0;
	Node <Unit*>* follow = frontPtr;
	while (follow)
	{
		if (follow->getItem()->GetType() == "AS" || follow->getItem()->GetType() == "Alien_Monster" || follow->getItem()->GetType() == "Drone")
		{
			x = x + follow->getItem()->GetDb();
			y = y + 1;
		}
		follow = follow->getNext();
	}
	return x;
}