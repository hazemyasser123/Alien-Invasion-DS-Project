#pragma once
#include "Unit.h"

class Earth_Gunnery : public Unit  // IMPORTANT: It's DS is Priority Queue
{
public:
	Earth_Gunnery();
	Earth_Gunnery(int id, int tj, int h, int p, int ac, Game* Gp);
	void Attack(UnitQueue& Temp_List);
};

