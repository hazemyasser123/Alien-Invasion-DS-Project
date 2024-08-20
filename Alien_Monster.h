#pragma once
#include "Unit.h"


class Alien_Monster : public Unit // IMPORTANT: It's DS is Array_Of_Pointers
{

public:
	Alien_Monster();
	Alien_Monster(int id, int tj, int h, int p, int ac, Game* Gp);
	void Attack(UnitQueue& Temp_List);
};

