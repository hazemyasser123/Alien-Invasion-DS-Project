#include "ES.h"
#include "Game.h"

ES::ES() : Unit()
{
	SetType("ES");
}

ES::ES(int id, int tj, int h, int p, int ac, Game* Gp): Unit(id, tj, h, p, ac, Gp)
{
	IsImmune = false;
	IsInfected = false;
	SetType("ES");
}

void ES::Attack(UnitQueue& Temp_List)
{
	Unit* ToBeAttacked = nullptr;
	bool dont_Comma = true;
	UnitQueue IDSNeeded;
	for (int NumberAttacked = 0; NumberAttacked < GetAttackCap(); NumberAttacked++)
	{
		ToBeAttacked = GetGamePtr()->GetAlienArmy()->PickAS();
		if (ToBeAttacked != nullptr)
		{
			IDSNeeded.enqueue(ToBeAttacked);
			ToBeAttacked->SetHealth(ToBeAttacked->GetHealth() - ((GetPower() * GetHealth() / 100) / sqrt((ToBeAttacked->GetHealth()))));
			ToBeAttacked->BeAttacked(GetPower(), GetGamePtr()->getCurrentTime());
			if (ToBeAttacked->IsAlive() == true)
			{
				Temp_List.enqueue(ToBeAttacked);
			}
			else
			{
				GetGamePtr()->InsertInKilled_List(ToBeAttacked);
			}
		}
	}
	if (GetGamePtr()->Get_Interactive_true_silent_false())
	{
		cout << "ES " << GetID() << " shot ";
		IDSNeeded.PrintQueue();
	}
}

void ES::SetIsInfected(bool isinf)
{
	IsInfected = isinf;
}

void ES::SetIsImmune(bool isimmune)
{
	IsImmune = isimmune;
}

bool ES::GetIsInfected()
{
	return IsInfected;
}

bool ES::GetImmunity()
{
	return IsImmune;
}

