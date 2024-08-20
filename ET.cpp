#include "ET.h"
#include "Game.h"

ET::ET() : Unit()
{
	SetType("ET");
}

ET::ET(int id, int tj, int h, int p, int ac, Game* Gp) : Unit(id, tj, h, p, ac, Gp)
{
	SetType("ET");
}

void ET::Attack(UnitQueue& Temp_List)
{
	Unit* UnitToBeAttacked;
	UnitQueue IDSNeeded;
	for (int i = 0; i < GetAttackCap(); i++) //This for loop attacks alien monsters
	{
		UnitToBeAttacked = GetGamePtr()->GetAlienArmy()->PickAM();
		if (UnitToBeAttacked != nullptr)
		{
			IDSNeeded.enqueue(UnitToBeAttacked);
			UnitToBeAttacked->SetHealth(UnitToBeAttacked->GetHealth() - ((GetPower() * GetHealth() / 100) / sqrt((UnitToBeAttacked->GetHealth()))));
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
	
	
	if (AttackMode) //Attack soldiers too
	{
		for (int i = 0; i < GetAttackCap(); i++) //This for loop attacks alien soldiers 
		{
			UnitToBeAttacked = GetGamePtr()->GetAlienArmy()->PickAS();
			if (UnitToBeAttacked != nullptr)
			{
				IDSNeeded.enqueue(UnitToBeAttacked);
				UnitToBeAttacked->SetHealth(UnitToBeAttacked->GetHealth() - ((GetPower() * GetHealth() / 100) / sqrt((UnitToBeAttacked->GetHealth()))));
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
	}
	if (GetGamePtr()->Get_Interactive_true_silent_false())
	{
		cout << "ET " << GetID() << " shot ";
		IDSNeeded.PrintQueue();
	}
}

void ET::DetermineAttackMode()
{
	int ESCount = GetGamePtr()->GetEarthArmy()->GetESCount();
	int ASCount = GetGamePtr()->GetAlienArmy()->GetASCount();
	if (!AttackMode) //at initial state, if attacking only monsters
	{
		//change the mode only if ES counts drops below 30% of AS count
		if (ESCount < (0.3 * ASCount)) //Check if ES count is less than 30% of AS count
		{
			AttackMode = true;
		}
	}
	else //if the tank was already attacking soliders
	{
		/*Switch Mode only if the ES count reaches 80% of AS count*/
		if (ESCount >= (0.8 * ASCount)) //Check if ES count reached80% of AS count
		{
			AttackMode = false;
		}
	}
}

