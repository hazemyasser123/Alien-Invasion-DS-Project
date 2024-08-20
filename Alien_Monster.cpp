#include "Alien_Monster.h"
#include "Game.h"

Alien_Monster::Alien_Monster() :Unit()
{
	SetType("Alien_Monster");
}

Alien_Monster::Alien_Monster(int id, int tj, int h, int p, int ac, Game* Gp) :Unit(id, tj, h, p, ac, Gp)
{
	SetType("Alien_Monster");
}


void Alien_Monster::Attack(UnitQueue& Temp_List)
{
	int NumberUnitsToBeAttacked;
	Unit* UnitToBeAttacked;
	UnitQueue IDSNeeded;
	
	NumberUnitsToBeAttacked = GetAttackCap();
	while (NumberUnitsToBeAttacked > GetAttackCap() / 2)
	{
		if (GetGamePtr()->GetEarthArmy()->pick(UnitToBeAttacked, "ES") == true)
		{
			IDSNeeded.enqueue(UnitToBeAttacked);
			UnitToBeAttacked->SetHealth(UnitToBeAttacked->GetHealth() - ((GetPower() * GetHealth() / 100) / sqrt((UnitToBeAttacked->GetHealth()))));
			UnitToBeAttacked->BeAttacked(GetPower(), GetGamePtr()->getCurrentTime());
			NumberUnitsToBeAttacked--;
			if (UnitToBeAttacked->IsAlive() == true)
			{
				if (UnitToBeAttacked->GetHealth() < 0.2 * UnitToBeAttacked->GetOrignalHealth()) //If the unit needs healing
				{
					UnitToBeAttacked->SetTm(GetGamePtr()->getCurrentTime());
					GetGamePtr()->GetEarthArmy()->AddToUML_Soldiers(UnitToBeAttacked);
				}
				else
				{
					Temp_List.enqueue(UnitToBeAttacked);
					UnitToBeAttacked->BeAttacked(GetPower(), GetGamePtr()->getCurrentTime());
				}
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

		if (GetGamePtr()->GetEarthArmy()->pick(UnitToBeAttacked, "ET") == true)
		{
			IDSNeeded.enqueue(UnitToBeAttacked);
			UnitToBeAttacked->SetHealth(UnitToBeAttacked->GetHealth() - ((GetPower() * GetHealth() / 100) / sqrt((UnitToBeAttacked->GetHealth()))));
			UnitToBeAttacked->BeAttacked(GetPower(), GetGamePtr()->getCurrentTime());
			NumberUnitsToBeAttacked--;
			if (UnitToBeAttacked->IsAlive() == true)
			{
				if (UnitToBeAttacked->GetHealth() < 0.2 * UnitToBeAttacked->GetOrignalHealth())
				{
					GetGamePtr()->GetEarthArmy()->AddToUML_Tanks(UnitToBeAttacked);
				}
				else {
					Temp_List.enqueue(UnitToBeAttacked);
					UnitToBeAttacked->BeAttacked(GetPower(), GetGamePtr()->getCurrentTime());
				}
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
		if (GetGamePtr()->GetEarthArmy()->pick(UnitToBeAttacked, "ES") == true)
		{
			IDSNeeded.enqueue(UnitToBeAttacked);
			UnitToBeAttacked->SetHealth(UnitToBeAttacked->GetHealth() - ((GetPower() * GetHealth() / 100) / sqrt((UnitToBeAttacked->GetHealth()))));
			UnitToBeAttacked->BeAttacked(GetPower(), GetGamePtr()->getCurrentTime());
			NumberUnitsToBeAttacked--;
			if (UnitToBeAttacked->IsAlive() == true)
			{
				if (UnitToBeAttacked->GetHealth() < 0.2 * UnitToBeAttacked->GetOrignalHealth()) //If the unit needs healing
				{
					UnitToBeAttacked->SetTm(GetGamePtr()->getCurrentTime());
					GetGamePtr()->GetEarthArmy()->AddToUML_Soldiers(UnitToBeAttacked);
				}
				else
				{
					Temp_List.enqueue(UnitToBeAttacked);
					UnitToBeAttacked->BeAttacked(GetPower(), GetGamePtr()->getCurrentTime());
				}
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
	if (GetGamePtr()->Get_Interactive_true_silent_false() == true)
	{
		cout << "AM " << GetID() << " shot ";
		IDSNeeded.PrintQueue();
	}
}






