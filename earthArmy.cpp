#include "earthArmy.h"
#include "LinkedQueue.h"

void earthArmy::Attack(UnitQueue& Temp_List)
{
	Unit* ESthatWillAttack;
	if (ES_List.peek(ESthatWillAttack))
	{
		ESthatWillAttack->Attack(Temp_List);
	}

	Unit* ETthatWillAttack;
	if (ET_List.peek(ETthatWillAttack))
	{
		ETthatWillAttack->Attack(Temp_List);
	}
	
	Unit* EGthatWillAttack;
	int priEG; // dummy int
	if (EG_List.peek(EGthatWillAttack, priEG))
	{
		EGthatWillAttack->Attack(Temp_List);
	}
	
	Unit* HUthatWillHeal;
	if (HU_List.pop(HUthatWillHeal))
	{
		HUthatWillHeal->Attack(Temp_List);
	}
	// pop 3ashan neshlo mel army howa byro7 el killed list fel attack bta3to

	armyCount = ES_List.getcount() + (ET_List.gettop() + 1) + EG_List.getcount() + (HU_List.gettop() + 1);
}

void earthArmy::Print()
{
	cout << "==============  Earth Army Alive Units ==============" << endl;
	cout << ES_List.getcount() << " ES "; ES_List.PrintQueue();            // eg: 55 ES [1, 2, 3, 4, ...]
	cout << ET_List.gettop() + 1 << " ET "; ET_List.PrintStack();
	cout << EG_List.getcount() << " EG "; EG_List.PrintPriQueue();
	cout << HU_List.gettop() + 1 << " HU"; HU_List.PrintStack();
	PrintHealinglist(); cout << endl;
}

void earthArmy::PrintHealinglist()
{
	cout << "==============  Healing List Units ==================" << endl;
	cout << UML_Soldiers.getcount() << " UML Soliders "; UML_Soldiers.PrintPriQueue();
	cout << UML_Tanks.getcount() << " UML Tanks "; UML_Tanks.PrintQueue();
}

bool earthArmy::pick(Unit*& take, string x)
{
	if (x == "ET")
	{
		bool truth = ET_List.pop(take);
		if (truth)
			return true;
	}
	else if (x == "UML_S")
	{
		int y;
		if (UML_Soldiers.dequeue(take, y) == true)
		{
			return true;
		}
	}
	else if (x == "UML_T")
	{
		if (UML_Tanks.dequeue(take) == true)
		{
			return true;
		}
	}
	else
	{
		if (x == "ES")
		{
			if (ES_List.dequeue(take) == true)
				return true;
		}
		else
		{
			int y;
			if (EG_List.dequeue(take,y) == true)
				return true;
		}
	}
	return false;
}

bool earthArmy::addUnit(Unit* armyunit)  // add unit to appropiate list 
{
	if (armyunit == nullptr)
	{
		return false;
	}	
	if (armyunit->GetType() == "ES")
	{
		ES_List.enqueue((ES*)armyunit);
		return true;
	}
	else if (armyunit->GetType() == "ET")
	{
		ET_List.push((ET*)armyunit);
		return true;
	}
	else if (armyunit->GetType() == "Earth_Gunnery")
	{
		EG_List.enqueue((Earth_Gunnery*)armyunit, armyunit->GetHealth()+armyunit->GetPower()); //priority formula can be changed if needed later
		return true;
	}
	else if (armyunit->GetType() == "HU")
	{
		HU_List.push((HU*)armyunit);
	}
	else return false;
}

int earthArmy::GetESCount()
{
	return ES_List.getcount();
}

void earthArmy::calc_created(Unit* armyunit)
{
	//if (armyunit != nullptr)
	{
		if (armyunit->GetType() == "ES")
		{
			ES_created = ES_created + 1;
		}
		else if (armyunit->GetType() == "ET")
		{
			ET_created = ET_created + 1;
		}
		else if (armyunit->GetType() == "Earth_Gunnery")
		{
			EG_created = EG_created + 1;
		}
	}
	return;
}

float earthArmy::getEScreated()
{
	return ES_created;
}

float earthArmy::getETcreated()
{
	return ET_created;
}

float earthArmy::getEGcreated()
{
	return EG_created;
}

void earthArmy::AddToUML_Soldiers(Unit* ArmyUnit)
{

	UML_Soldiers.enqueue(ArmyUnit, 100 - (ArmyUnit->GetHealth())); //Priority is 100 - HP so lowest has highest priority.
}

void earthArmy::AddToUML_Tanks(Unit* ArmyUnit)
{
	UML_Tanks.enqueue(ArmyUnit);
}

int earthArmy::getarmyCount()
{
	return armyCount;
}
