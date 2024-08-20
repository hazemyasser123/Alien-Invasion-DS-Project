#pragma once
#pragma once
#include "DEQueue.h"
#include "Unit.h"
class UnitDEQueue : public DEQueue<Unit*>
{
public:
	void PrintQueue();
};