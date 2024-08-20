#pragma once
#include "ArrayStack.h"
#include "Unit.h"
class UnitStack :  public ArrayStack<Unit*>
{
public:
	void PrintStack();
};

