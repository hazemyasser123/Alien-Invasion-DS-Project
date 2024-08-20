#pragma once
#include "LinkedQueue.h"
#include <iostream>
#include "Unit.h"
using namespace std;

class ET : public Unit
{
private:
	bool AttackMode; //false means attacking only monsters, true means attacking both monsters and soldiers
public:
	ET();
	ET(int id, int tj, int h, int p, int ac, Game* Gp);
	void Attack(UnitQueue& Temp_List);
	void DetermineAttackMode();
};