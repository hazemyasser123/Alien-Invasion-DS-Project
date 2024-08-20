#include "AS.h"
#include "Game.h"

AS::AS() : Unit()
{
	SetType("AS");
}

AS::AS(int id, int tj, int h, int p, int ac, Game* Gp) : Unit(id, tj, h, p, ac, Gp)
{
	SetType("AS");
}

void AS::Attack(UnitQueue& Temp_List)
{
	Unit* ToBeAttacked = nullptr;
	UnitQueue IDSNeeded;
	for (int NumberAttacked = 0; NumberAttacked < GetAttackCap(); NumberAttacked++)
	{
		if (GetGamePtr()->GetEarthArmy()->pick(ToBeAttacked, "ES"))
		{
			IDSNeeded.enqueue(ToBeAttacked);
			ToBeAttacked->SetHealth(ToBeAttacked->GetHealth() - ((GetPower() * GetHealth() / 100) / ((ToBeAttacked->GetHealth()) ^ (1 / 2))));
			ToBeAttacked->BeAttacked(GetPower(), GetGamePtr()->getCurrentTime());

			// should check if health is 1-20% of its initial heath to add it to UML1 otherwise to templist
			if (ToBeAttacked->IsAlive() == true)
			{
				if (ToBeAttacked->GetHealth() <= 0.2 * ToBeAttacked->GetOrignalHealth())
					GetGamePtr()->GetEarthArmy()->AddToUML_Soldiers(ToBeAttacked);
				else
					Temp_List.enqueue(ToBeAttacked);
			}
			else
			{
				GetGamePtr()->InsertInKilled_List(ToBeAttacked);
				ToBeAttacked->BeAttacked(GetPower(), GetGamePtr()->getCurrentTime());
			}
		}
	}
	if (GetGamePtr()->Get_Interactive_true_silent_false())
	{
		cout << "AS " << GetID() << " shot ";
		IDSNeeded.PrintQueue();
	}
}
