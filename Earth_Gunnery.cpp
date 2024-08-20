#include "Earth_Gunnery.h"
#include "Game.h"

Earth_Gunnery::Earth_Gunnery() :Unit()
{
	SetType("Earth_Gunnery");
}

Earth_Gunnery::Earth_Gunnery(int id, int tj, int h, int p, int ac, Game* Gp) :Unit(id, tj, h, p, ac, Gp)
{
	SetType("Earth_Gunnery");
}


void Earth_Gunnery::Attack(UnitQueue& Temp_List)
{
	int NumberUnitsToBeAttacked;
	Unit* UnitToBeAttacked;
	Unit* UnitToBeAttacked2; // This is made for the case of attacking two drones 
	NumberUnitsToBeAttacked = GetAttackCap();
	UnitQueue IDSNeeded;
	while (NumberUnitsToBeAttacked > GetAttackCap() / 2)
	{
		UnitToBeAttacked = GetGamePtr()->GetAlienArmy()->PickAM();
		if (UnitToBeAttacked != nullptr)
		{
			IDSNeeded.enqueue(UnitToBeAttacked);
			UnitToBeAttacked->SetHealth(UnitToBeAttacked->GetHealth() - ((GetPower() * GetHealth() / 100) / sqrt((UnitToBeAttacked->GetHealth()))));
			UnitToBeAttacked->BeAttacked(GetPower(), GetGamePtr()->getCurrentTime());
			NumberUnitsToBeAttacked--;
			if (UnitToBeAttacked->IsAlive() == true)
			{
				Temp_List.enqueue(UnitToBeAttacked);
			}
			else
			{
				GetGamePtr()->InsertInKilled_List(UnitToBeAttacked);
			}
		}
		else
		{
			break;
		}
	}
	while (NumberUnitsToBeAttacked > 0)
	{
		GetGamePtr()->GetAlienArmy()->pickDrones(UnitToBeAttacked, UnitToBeAttacked2);
		if (UnitToBeAttacked == nullptr && UnitToBeAttacked2 == nullptr)
		{
			break;
		}
		if (UnitToBeAttacked != nullptr)
		{
			IDSNeeded.enqueue(UnitToBeAttacked);
			UnitToBeAttacked->SetHealth(UnitToBeAttacked->GetHealth() - ((GetPower() * GetHealth() / 100) / sqrt((UnitToBeAttacked->GetHealth()))));
			UnitToBeAttacked->BeAttacked(GetPower(), GetGamePtr()->getCurrentTime());
			NumberUnitsToBeAttacked--;
			if (UnitToBeAttacked->IsAlive() == true)
			{
				Temp_List.enqueue(UnitToBeAttacked);
			}
			else
			{
				GetGamePtr()->InsertInKilled_List(UnitToBeAttacked);
			}
		}
		if (UnitToBeAttacked2 != nullptr)
		{
			IDSNeeded.enqueue(UnitToBeAttacked);
			UnitToBeAttacked2->SetHealth(UnitToBeAttacked2->GetHealth() - ((GetPower() * GetHealth() / 100) / sqrt((UnitToBeAttacked2->GetHealth()))));
			UnitToBeAttacked2->BeAttacked(GetPower(), GetGamePtr()->getCurrentTime());
			NumberUnitsToBeAttacked--;
			if (UnitToBeAttacked2->IsAlive() == true)
			{
				Temp_List.enqueue(UnitToBeAttacked2);
			}
			else
			{
				GetGamePtr()->InsertInKilled_List(UnitToBeAttacked2);
			}
		}
	}
	while (NumberUnitsToBeAttacked > 0)
	{
		UnitToBeAttacked = GetGamePtr()->GetAlienArmy()->PickAM();
		if (UnitToBeAttacked != nullptr)
		{
			IDSNeeded.enqueue(UnitToBeAttacked);
			UnitToBeAttacked->SetHealth(UnitToBeAttacked->GetHealth() - ((GetPower() * GetHealth() / 100) / sqrt((UnitToBeAttacked->GetHealth()))));
			UnitToBeAttacked->BeAttacked(GetPower(), GetGamePtr()->getCurrentTime());
			NumberUnitsToBeAttacked--;
			if (UnitToBeAttacked->IsAlive() == true)
			{
				Temp_List.enqueue(UnitToBeAttacked);
			}
			else
			{
				GetGamePtr()->InsertInKilled_List(UnitToBeAttacked);
			}
		}
		else
		{
			break;
		}
	}
	if (GetGamePtr()->Get_Interactive_true_silent_false())
	{
		cout << "EG " << GetID() << " shot ";
		IDSNeeded.PrintQueue();
	}
}