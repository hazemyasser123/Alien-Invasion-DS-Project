#include "UnitAOP.h"
#include <iostream>
using namespace std;

void UnitAOP::PrintAll()
{
	cout << "[";
	for (int i = 0; i < count; i++)
	{
		if (i != count - 1)
		{
			items[i]->Print();
			cout << ", ";
		}
		else
		{
			items[i]->Print();
		}
	}
	cout << "]" << endl;
}




bool UnitAOP::Delete(Unit*& data)
{
	if (count == 0)
		return false;
	if (count ==1)
	{
		data = items[0];
		count--;
		return true;
	}
	int c = rand() % (count - 1);
	data = items[c];
	items[c] = items[count - 1];
	count--;
	return false;
}

bool UnitAOP::AcceesRandomMonster(Unit*& data)
{
	if (count == 0)
	{
		data = nullptr;
		return false;
	}
	if (count == 1)
	{
		data = items[0];
		return true;
	}
	int c = rand() % (count - 1);
	data = items[c];
	return true;
}
