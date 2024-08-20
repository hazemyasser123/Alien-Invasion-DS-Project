#pragma once
#include "LinkedQueue.h"
#include <iostream>
#include "Unit.h"
using namespace std;

class HU : public Unit
{
public:
	HU();
	HU(int id, int tj, int h, int p, int ac, Game* Gp);
	void Attack(UnitQueue& Temp_List);
};