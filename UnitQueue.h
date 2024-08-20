#pragma once
#include "LinkedQueue.h"
#include "Unit.h"
class UnitQueue :  public LinkedQueue <Unit*>
{
public:
	void PrintQueue();
	float getEarthDf(float& y);
	float getEarthDd(float& y);
	float getEarthDb(float& y);
	float getAlienDf(float& y);
	float getAlienDd(float& y);
	float getAlienDb(float& y);
};

