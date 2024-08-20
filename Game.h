#pragma once
#include "alienArmy.h"
#include "earthArmy.h"
#include "randGen.h"

#ifndef GAME
#define GAME
enum Result
{
	EARTHWON,
	ALIENWON,
	DRAW
};
class Game
{
private:
	randGen* g2;
	alienArmy AlienArmy;
	earthArmy EarthArmy;
	UnitQueue KilledList;
	int InfectionPer;
	bool Interactive_true_silent_false; // true: interactive , false: silent
	int CurrentTime;
	bool We_Are_Not_Done_Yet;
	Result Whos_the_Winner;	//Will take earth army as the refernce of being won or lost in the outfile //From Omar
	float ES_destructed;
	float ET_destructed;
	float EG_destructed;
	float AS_destructed;
	float AM_destructed;
	float AD_destructed;
public:
	Game();
	~Game();
	void InsertInKilled_List(Unit* ToBeInserted);
	void ReadParameters();
	int getCurrentTime();
	alienArmy* GetAlienArmy();
	earthArmy* GetEarthArmy();
	void print();
	void Test();
	void Attack();
	bool AreWeNotDoneYet();
	void WhoWon();
	void generateOutputFile();
	void DisplayResult();
	int GetInfectionPer();
	void Simulation();
	void ChooseMode();
	bool Get_Interactive_true_silent_false();
};

#endif