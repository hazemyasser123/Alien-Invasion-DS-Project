#pragma once
#include "LinkedQueue.h"
#include "AS.h"
#include "Array_Of_Pointers.h"
#include "Alien_Monster.h"
#include "DEQueue.h"
#include "Drone.h"
#include "UnitAOP.h"
#include "UnitQueue.h"
#include "UnitStack.h"
#include "UnitDEQueue.h"
#include <iostream>
using namespace std;

class alienArmy
{
private:
	UnitQueue AS_List;
	UnitAOP AM_List;
	UnitDEQueue AD_List;
	int armyCount;
	float AS_created = 0;
	float AM_created = 0;
	float AD_created = 0;

public:
	void Attack(UnitQueue& Temp_List);
	void Print();
	Unit* PickAM();
	Unit* PickAS();
	void pickDrones(Unit*& frntDrone, Unit*& backDrone);
	bool addUnit(Unit* armyunit);
	int getarmyCount();
	int GetASCount();
	void calc_created(Unit* armyunit);
	float getAScreated();
	float getAMcreated();
	float getADcreated();
};