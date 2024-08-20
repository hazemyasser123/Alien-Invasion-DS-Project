#include "UnitStack.h"

void UnitStack::PrintStack()
{
	UnitStack Scopy;
	Scopy = *this;
	Unit* x;
	cout << "[";
	int count = 0;
	while (Scopy.pop(x))
	{
		count++;
		if (count == this->gettop() + 1)
		{
			x->Print();
			
		}
		else
		{
			x->Print();
			cout << ", ";

		}
	}
	cout << "]" << endl;
}

/*
	IF THE PRINTING IS WANTED IN ORDER IN THE STACK THIS WILL BE THE IMPLEMENTATION 
	
	void UnitStack::PrintStack()
	{
		UnitStack Scopy;
		UnitStack SnewCopy;
		Scopy = *this;
		Unit* x;
		Unit* y;
		cout << "[";
		int count = 0;
		while (Scopy.pop(y))
		{
			SnewCopy.push(y);
		}
		while (SnewCopy.pop(x))
		{
			count++;
			if (count == this->gettop() + 1)
			{
				x->Print();
			}
			else
			{
				x->Print();
				cout << ", ";
			}
		}
		cout << "]" << endl;
	}

*/
