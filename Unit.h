#pragma once
#include <iostream>
using namespace std;
#ifndef UNIT
#define UNIT
class Game;
class UnitQueue;
class Unit
{
private:
	int ID;
	string Type; // IMPORTANT : this should have a default value in each of the derived classes
	int Tj;     // Shows the timeskip when this unit joined the battle (Join Time)
	int Td;		// (Time dismissed or time of death)
	int Ta;		// (Time of the unit got the first shot by enemy)
	int Tm; // Time the unit joined the UML
	bool wasShot;	// if this is true the Ta won't be changed so don't screw up the inputing the first Ta & Df
	//and this won't be changed to flase again besides I made Death so that no values of D won't change only T
	int Dd;		// (Time of the unit killed compared to Ta)
	int Df;		// Ta -Tj Time taken to be spotted     
	int Db;		// (Time the unit spent in battle)                                                                
	int Health;
	int Power;
	int Attack_Capacity;
	Game* PtrGame;
	const int OrignalHealth;

	void SetDf(int time);

	void SetDd(int time);

	void SetDb(int time);

	void SetTj(int time);

	void SetTd(int time);

	void SetTa(int time);

	void SetPower(int p);

	void SetAttackCap(int ac);

	void SetID(int id);

	void SetGamePtr(Game* pg);

	void DEATH(int deathtime);

public:
	Unit();

	void SetType(string t);
	
	void SetTm(int time);

	Unit(int id, int tj, int h, int p, int ac, Game* Gp);

	int GetID() const;

	int GetTj() const;

	int GetTd() const;

	int GetTa() const;

	int GetDf() const;

	int GetTm() const;

	int GetDd() const;

	int GetDb() const;

	bool GetwasShot() const;

	int GetHealth() const;

	int GetOrignalHealth() const;

	int GetPower() const;

	int GetAttackCap() const;

	string GetType() const;

	Game* GetGamePtr() const;

	bool IsAlive();

	void Print() const;

	void SetHealth(int h);

	virtual void Attack(UnitQueue& Temp_List) = 0;

	virtual void BeAttacked(int DAMGE, int currenttime);
};


#endif

