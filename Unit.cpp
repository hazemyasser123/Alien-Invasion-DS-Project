#include "Unit.h"
#include <iostream>
using namespace std;

Unit::Unit() :OrignalHealth(0)
{
	SetID(0);
	SetTj(0);
	SetHealth(0);
	SetPower(0);
	SetAttackCap(0);
	wasShot = false;
}

Unit::Unit(int id, int tj, int h, int p, int ac, Game* Gp):OrignalHealth(h)
{
	SetID(id);
	SetTj(tj);
	SetHealth(h);
	SetPower(p);
	SetAttackCap(ac);
	PtrGame = Gp;
	wasShot = false;
}

void Unit::SetID(int id)
{
	ID = id;
}

void Unit::SetType(string t)
{
	Type = t;
}

void Unit::SetTm(int time)
{
	Tm = time;
}

void Unit::SetTj(int time)
{
	Tj = time;
}

void Unit::SetTd(int time)
{
	if (IsAlive() == false)
	{
		Td = time;
	}
}

void Unit::SetTa(int time)
{
	if (!wasShot)
	{
		Ta = time;
		wasShot = true;
	}
}

void Unit::SetDf(int time)
{
	Df = time;
}

void Unit::SetDd(int time)
{
	Dd = time;
}

void Unit::SetDb(int time)
{
	Db = time;
}

void Unit::DEATH(int deathtime)
{
	if (IsAlive() == false)
	{
		SetTd(deathtime);
		SetDf(Ta - Tj);
		SetDd(Td - Ta);
		SetDb(Td - Tj);
	}
}

void Unit::SetHealth(int h)
{
	Health = h;
}

void Unit::SetPower(int p)
{
	Power = p;
}

void Unit::SetAttackCap(int ac)
{
	Attack_Capacity = ac;
}

int Unit::GetID() const
{
	return ID;
}

int Unit::GetTd() const
{
	return Td;
}

int Unit::GetTa() const
{
	return Ta;
}

int Unit::GetDf() const
{
	return Df;
}

int Unit::GetTm() const
{
	return Tm;
}

int Unit::GetDd() const
{
	return Dd;
}

int Unit::GetDb() const
{
	return Db;
}

bool Unit::GetwasShot() const
{
	return wasShot;
}

int Unit::GetHealth() const
{
	return Health;
}

int Unit::GetOrignalHealth() const
{
	return OrignalHealth;
}

int Unit::GetPower() const
{
	return Power;
}

int Unit::GetAttackCap() const
{
	return Attack_Capacity;
}

int Unit::GetTj() const
{
	return Tj;
}

string Unit::GetType() const
{
	return Type;
}

void Unit::SetGamePtr(Game* pg)
{
	PtrGame = pg;
}

Game* Unit::GetGamePtr() const
{
	return PtrGame;
}

bool Unit::IsAlive()
{
	if (Health > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Unit::Print() const
{
	cout << ID;
}

void Unit::BeAttacked(int DAMGE, int currenttime)
{
	if (!wasShot)
	{
		SetTa(currenttime);
	}
	//SetHealth(Health - DAMGE);
	if (!IsAlive())
	{
		DEATH(currenttime);
	}
}

