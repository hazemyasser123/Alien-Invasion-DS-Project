#pragma once
#include "Array_Of_Pointers.h"
#include "Unit.h"
class UnitAOP : public Array_Of_Pointers<Unit>
{
public:
	void PrintAll();
	bool Delete(Unit*& data);
	bool AcceesRandomMonster(Unit*& data);
};

