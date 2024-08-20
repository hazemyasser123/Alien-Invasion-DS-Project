#include "Drone.h"
#include "Game.h"
Drone::Drone():Unit()
{
	SetType("Drone");
}

Drone::Drone(int id, int tj, int h, int p, int ac, Game* Gp) : Unit(id, tj, h, p, ac, Gp)
{
	SetType("Drone");
}

void Drone::Attack(UnitQueue& Temp_List)
{
	int NumberUnitsToBeAttacked;
	Unit* UnitToBeAttacked = nullptr;
	UnitQueue IDSNeeded;
	if (GetAttackCap() % 2 == 0)
	{
		NumberUnitsToBeAttacked = GetAttackCap() / 2;
		for (int i = 0; i < NumberUnitsToBeAttacked; i++)
		{
			if (GetGamePtr()->GetEarthArmy()->pick(UnitToBeAttacked, "Earth_Gunnery") == true)
			{
				IDSNeeded.enqueue(UnitToBeAttacked);
				UnitToBeAttacked->SetHealth(UnitToBeAttacked->GetHealth() - ((GetPower() * GetHealth() / 100) / ((UnitToBeAttacked->GetHealth()) ^ (1 / 2))));
				UnitToBeAttacked->BeAttacked(GetPower(), GetGamePtr()->getCurrentTime());
				if (UnitToBeAttacked->IsAlive() == true)
				{
					Temp_List.enqueue(UnitToBeAttacked);
				}
				else
				{
					GetGamePtr()->InsertInKilled_List(UnitToBeAttacked);
				}
			}
		}
		for (int i = 0; i < NumberUnitsToBeAttacked; i++)
		{
			if (GetGamePtr()->GetEarthArmy()->pick(UnitToBeAttacked, "ET") == true)
			{
				IDSNeeded.enqueue(UnitToBeAttacked);
				UnitToBeAttacked->SetHealth(UnitToBeAttacked->GetHealth() - ((GetPower() * GetHealth() / 100) / ((UnitToBeAttacked->GetHealth()) ^ (1 / 2))));
				UnitToBeAttacked->BeAttacked(GetPower(), GetGamePtr()->getCurrentTime());
				if (UnitToBeAttacked->IsAlive() == true)
				{
					if (UnitToBeAttacked->GetHealth() < 0.2 * UnitToBeAttacked->GetOrignalHealth()) //If the unit needs healing
					{
						UnitToBeAttacked->SetTm(GetGamePtr()->getCurrentTime());
						GetGamePtr()->GetEarthArmy()->AddToUML_Tanks(UnitToBeAttacked);
					}
					else
					{
						Temp_List.enqueue(UnitToBeAttacked);
					}
				}
				else
				{
					GetGamePtr()->InsertInKilled_List(UnitToBeAttacked);
				}
			}
		}
	}
	else
	{
		NumberUnitsToBeAttacked = GetAttackCap() / 2;
		for (int i = 0; i < NumberUnitsToBeAttacked + 1; i++)
		{
			if (GetGamePtr()->GetEarthArmy()->pick(UnitToBeAttacked, "Earth_Gunnery") == true)
			{
				IDSNeeded.enqueue(UnitToBeAttacked);
				UnitToBeAttacked->SetHealth(UnitToBeAttacked->GetHealth() - ((GetPower() * GetHealth() / 100) / ((UnitToBeAttacked->GetHealth()) ^ (1 / 2))));
				UnitToBeAttacked->BeAttacked(GetPower(), GetGamePtr()->getCurrentTime());
				if (UnitToBeAttacked->IsAlive() == true)
				{

					Temp_List.enqueue(UnitToBeAttacked);
				}
				else
				{
					GetGamePtr()->InsertInKilled_List(UnitToBeAttacked);
				}
			}
		}
		for (int i = 0; i < NumberUnitsToBeAttacked; i++)
		{
			if (GetGamePtr()->GetEarthArmy()->pick(UnitToBeAttacked, "ET") == true)
			{
				IDSNeeded.enqueue(UnitToBeAttacked);
				UnitToBeAttacked->SetHealth(UnitToBeAttacked->GetHealth() - ((GetPower() * GetHealth() / 100) / ((UnitToBeAttacked->GetHealth()) ^ (1 / 2))));
				UnitToBeAttacked->BeAttacked(GetPower(), GetGamePtr()->getCurrentTime());
				if (UnitToBeAttacked->IsAlive() == true)
				{
					if (UnitToBeAttacked->GetHealth() < 0.2 * UnitToBeAttacked->GetOrignalHealth()) //If the unit needs healing
					{
						UnitToBeAttacked->SetTm(GetGamePtr()->getCurrentTime());
						GetGamePtr()->GetEarthArmy()->AddToUML_Tanks(UnitToBeAttacked);
					}
					else
					{
						Temp_List.enqueue(UnitToBeAttacked);
					}
				}
				else
				{
					GetGamePtr()->InsertInKilled_List(UnitToBeAttacked);
				}
			}
		}
	}
	if (GetGamePtr()->Get_Interactive_true_silent_false())
	{
		cout << "AD " << GetID() << " shot ";
		IDSNeeded.PrintQueue();
	}
}