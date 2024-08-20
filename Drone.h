#pragma once

#include "DEQueue.h"
#include "Unit.h"
class Drone : public Unit
{
public:
	Drone();

	Drone(int id, int tj, int h, int p, int ac, Game* Gp);

	void Attack(UnitQueue& Temp_List);
};

