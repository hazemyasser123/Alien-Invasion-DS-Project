#include "Game.h"
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib> // For rand() function
#include <ctime>   // For time() function
#include <random>
#include <Windows.h> // for the sound effects
#include "MMSystem.h" // for the sound effects
using namespace std;
#pragma comment(lib,"winmm.lib") // for the sound effects
Game::Game()
{
	Interactive_true_silent_false = true; // interactive by default
	InfectionPer = 0;
	g2 = new randGen(this);
	ReadParameters();
	CurrentTime = 1;
	We_Are_Not_Done_Yet = true;
}

Game::~Game()
{
	delete g2;
}

void Game::InsertInKilled_List(Unit* ToBeInserted)
{
	KilledList.enqueue(ToBeInserted);
}

void Game::ReadParameters()
{
	ifstream infile;
	string line;
	infile.open("Input.txt");
	int N = 0;
	int ESper = 0;
	int ETper = 0;
	int EGper = 0;
	int ASper = 0;
	int AMper = 0;
	int ADper = 0;
	int HUper = 0;
	int Prob = 0;
	int PowerMinE = 0;
	int PowerMaxE = 0;
	int HealthMinE = 0;
	int HealthMaxE = 0;
	int AttackCapMinE = 0;
	int AttackCapMaxE = 0;
	int PowerMinA = 0;
	int PowerMaxA = 0;
	int HealthMinA = 0;
	int HealthMaxA = 0;
	int AttackCapMinA = 0;
	int AttackCapMaxA = 0;
	if (infile.is_open() == true)
	{
		infile >> N;
		getline(infile, line);
		infile >> ESper >> ETper >> EGper >> HUper;
		getline(infile, line);
		infile >> ASper >> AMper >> ADper >> InfectionPer;
		getline(infile, line);
		infile >> Prob;
		getline(infile, line);
		getline(infile, line);
		infile >> PowerMinE >> PowerMaxE >> HealthMinE >> HealthMaxE >> AttackCapMinE >> AttackCapMaxE;
		getline(infile, line);
		infile >> PowerMinA >> PowerMaxA >> HealthMinA >> HealthMaxA >> AttackCapMinA >> AttackCapMaxA;
	}
	infile.close();


	PowerMaxE = -PowerMaxE;
	HealthMaxE = -HealthMaxE;
	AttackCapMaxE = -AttackCapMaxE;
	PowerMaxA = -PowerMaxA;
	HealthMaxA = -HealthMaxA;
	AttackCapMaxA = -AttackCapMaxA;

	g2->setN(N);
	g2->setESper(ESper);
	g2->setETper(ETper);
	g2->setEGper(EGper);
	g2->setHUper(HUper);
	g2-> setASper(ASper);
	g2-> setAMper(AMper);
	g2-> setADper(ADper);
	g2-> setProb(Prob);
	g2-> setPowerMinE(PowerMinE);
	g2-> setPowerMaxE(PowerMaxE);
	g2-> SetHealthMinE(HealthMinE);
	g2-> SetHealthMaxE(HealthMaxE);
	g2-> SetAttackCapMinE(AttackCapMinE);
	g2-> SetAttackCapMaxE(AttackCapMaxE);
	g2-> SetPowerMinA(PowerMinA);
	g2-> SetPowerMaxA(PowerMaxA);
	g2-> SetHealthMinA(HealthMinA);
	g2-> SetHealthMaxA(HealthMaxA);
	g2-> SetAttackCapMinA(AttackCapMinA);
	g2-> SetAttackCapMaxA(AttackCapMaxA);
}

void Game::print()
{
	cout << "Current Timestep " << CurrentTime << endl;
	EarthArmy.Print();
	cout << endl;
	AlienArmy.Print();
	cout << endl << endl;
}

void Game::Test()
{
	int A = rand() % 100 + 1;
	if (A <= 10)
	{
		Unit* EARTHSOILDER = nullptr;
		EarthArmy.pick(EARTHSOILDER,"ES");
		EarthArmy.addUnit(EARTHSOILDER);
	}
	else
		if (A <= 20)
		{
			Unit* TANK = nullptr;
			EarthArmy.pick(TANK, "ET");
			if (TANK != nullptr)
			{
				KilledList.enqueue(TANK);
			}
		}
		else if (A <= 30)
		{
			Unit* EG = nullptr;
			EarthArmy.pick(EG, "Earth_Gunnery");
			if (EG)
			{
				/*EG->SetHealth(EG->GetHealth() / 2);*/
				EarthArmy.addUnit(EG);
			}
		}
		else if(A <= 40)
		{
			LinkedQueue<Unit*> AlienSoliderlist;
			Unit* AlienSolider;
			for (int i = 0; i < 5; i++)
			{
				AlienSolider = AlienArmy.PickAS();
				if (AlienSolider)
				{
					AlienSoliderlist.enqueue(AlienSolider);
					/*AlienSolider->SetHealth(AlienSolider->GetHealth() / 2);*/
				}
			}
			for (int i = 0; i < 5; i++)
			{
				AlienSoliderlist.dequeue(AlienSolider);
				AlienArmy.addUnit(AlienSolider);
			}
		}
		else if (A <= 50)
		{
			Unit* Monster1;
			Unit* Monster2;
			Unit* Monster3;
			Unit* Monster4;
			Unit* Monster5; 
			Monster1 = AlienArmy.PickAM();
			Monster2 = AlienArmy.PickAM();
			Monster3 = AlienArmy.PickAM();
			Monster4 = AlienArmy.PickAM();
			Monster5 = AlienArmy.PickAM();
			AlienArmy.addUnit(Monster1);
			AlienArmy.addUnit(Monster2);
			AlienArmy.addUnit(Monster3);
			AlienArmy.addUnit(Monster4);
			AlienArmy.addUnit(Monster5);
		}
		else if (A <= 60)
		{
			Unit* Drone1 = nullptr;
			Unit* Drone2 = nullptr;
			Unit* Drone3 = nullptr;
			Unit* Drone4 = nullptr;
			Unit* Drone5 = nullptr;
			Unit* Drone6 = nullptr;
			AlienArmy.pickDrones(Drone1, Drone2);
			if (!Drone1)
			{
				return;
			}
			AlienArmy.pickDrones(Drone3, Drone4);
			if (!Drone3)
			{
				KilledList.enqueue(Drone1);
				KilledList.enqueue(Drone2);
				return;
			}
			AlienArmy.pickDrones(Drone5, Drone6);


			if (!Drone5)
			{
				KilledList.enqueue(Drone1);
				KilledList.enqueue(Drone2);
				KilledList.enqueue(Drone3);
				KilledList.enqueue(Drone4);
				return;
			}
			else
			{
				if (!Drone6)
				{
					KilledList.enqueue(Drone1);
					KilledList.enqueue(Drone2);
					KilledList.enqueue(Drone3);
					KilledList.enqueue(Drone4);
					KilledList.enqueue(Drone5);
				}
				else
				{
					KilledList.enqueue(Drone1);
					KilledList.enqueue(Drone2);
					KilledList.enqueue(Drone3);
					KilledList.enqueue(Drone4);
					KilledList.enqueue(Drone5);
					KilledList.enqueue(Drone6);
				}
			}
		}
}


void Game::Attack()
{
	if (Interactive_true_silent_false == true)
	{
		cout << "==============  Units fighting at current step =======" << endl;
		UnitQueue TempList;
		EarthArmy.Attack(TempList);
		Unit* x;
		while (TempList.dequeue(x))
		{
			AlienArmy.addUnit(x);
		}
		AlienArmy.Attack(TempList);
		while (TempList.dequeue(x))
		{
			EarthArmy.addUnit(x);
		}
		cout << "==============  Killed/Destructed Units ==============" << endl;
		cout << KilledList.getcount() << " units ";
		KilledList.PrintQueue();
		cout << endl << endl;
	}
	else
	{

		UnitQueue TempList;
		EarthArmy.Attack(TempList);
		Unit* x;
		while (TempList.dequeue(x))
		{
			AlienArmy.addUnit(x);
		}
		AlienArmy.Attack(TempList);
		while (TempList.dequeue(x))
		{
			EarthArmy.addUnit(x);
		}
	}


	CurrentTime++;

}

bool Game::AreWeNotDoneYet()
{
	return We_Are_Not_Done_Yet;
}

void Game::WhoWon()
{
	Unit* SOLIDER = nullptr;
	Unit* TANK_MONSTER = nullptr;
	Unit* Gunner_Drone1 = nullptr;
	EarthArmy.pick(SOLIDER, "ES");
	EarthArmy.pick(TANK_MONSTER, "ET");
	EarthArmy.pick(Gunner_Drone1, "Earth_Gunnery");

	if (SOLIDER == nullptr && TANK_MONSTER == nullptr && Gunner_Drone1 == nullptr)
	{
		We_Are_Not_Done_Yet = false;
		Whos_the_Winner = ALIENWON;
	}
	else
	{
		if (SOLIDER != nullptr)
		{
			EarthArmy.addUnit(SOLIDER);
		}
		if (TANK_MONSTER != nullptr)
		{
			EarthArmy.addUnit(TANK_MONSTER);
		}
		if (Gunner_Drone1 != nullptr)
		{
			EarthArmy.addUnit(Gunner_Drone1);
		}
	}

	SOLIDER = AlienArmy.PickAS();
	TANK_MONSTER = AlienArmy.PickAM();
	Unit* Drone2;
	AlienArmy.pickDrones(Gunner_Drone1, Drone2);

	if (SOLIDER == nullptr && TANK_MONSTER == nullptr && Gunner_Drone1 == nullptr)
	{
		We_Are_Not_Done_Yet = false;
		Whos_the_Winner = EARTHWON;
	}
	else
	{
		if (SOLIDER != nullptr)
		{
			AlienArmy.addUnit(SOLIDER);
		}
		if (TANK_MONSTER != nullptr)
		{
			AlienArmy.addUnit(TANK_MONSTER);
		}
		if (Gunner_Drone1 != nullptr)
		{
			AlienArmy.addUnit(Gunner_Drone1);
		}
		if (Drone2 != nullptr)
		{
			AlienArmy.addUnit(Drone2);
		}
	}
	if (CurrentTime == 500)
	{
		We_Are_Not_Done_Yet = false;
		Whos_the_Winner = DRAW;
	}
}

void Game::generateOutputFile()
{
	ofstream outputFile;
	outputFile.open("output2.txt");
	if (!outputFile.is_open())
	{
		cerr << "Error opening file." << endl;
	}
	Unit* unitptr;
	Unit* check;
	KilledList.dequeue(unitptr);
	check = unitptr;
	do
	{
		outputFile << "Td = " << unitptr->GetTd() << "\t\t";
		if (unitptr->GetID() >= 2000)
		{
			outputFile << "ID = " << unitptr->GetID() << "\t";
		}
		else
		{
			outputFile << "ID = " << unitptr->GetID() << "\t\t";
		}
		outputFile << "Tj = " << unitptr->GetTj() << "\t\t";
		outputFile << "Df = " << unitptr->GetDf() << "\t\t";
		outputFile << "Dd = " << unitptr->GetDd() << "\t\t";
		outputFile << "Db = " << unitptr->GetDb() << "\n";
		KilledList.enqueue(unitptr);
	} while (KilledList.dequeue(unitptr) && unitptr != check);

	outputFile << "\n\n";

	outputFile << "Battle result: ";
	switch (Whos_the_Winner)
	{
	case EARTHWON:
		outputFile << "Win";
		break;
	case ALIENWON:
		outputFile << "Loss";
		break;
	case DRAW:
		outputFile << "Draw";
		break;
	default:
		break;
	}
	outputFile << "\n\n";

	outputFile << " ============ STATISTICS ============ " << "\n\n";

	outputFile << " For Earth Army: " << "\n\t";
	outputFile << " - Total ES: " << EarthArmy.getEScreated() << "\n\t";
	outputFile << " - Total ET: " << EarthArmy.getETcreated() << "\n\t";
	outputFile << " - Total EG: " << EarthArmy.getEGcreated() << "\n\n\t";
	outputFile << " - ES destructed %: " << (ES_destructed / EarthArmy.getEScreated()) * 100 << "\n\t";
	outputFile << " - ET destructed %: " << (ET_destructed / EarthArmy.getETcreated()) * 100 << "\n\t";
	outputFile << " - EG destructed %: " << (EG_destructed / EarthArmy.getEGcreated()) * 100 << "\n\t";
	outputFile << " - Total destructed %: " << (ES_destructed + ET_destructed + EG_destructed) / (EarthArmy.getEScreated() + EarthArmy.getETcreated() + EarthArmy.getEGcreated()) * 100 << "\n\n\t";

	float y = 0;
	KilledList.getEarthDf(y);
	if (y != 0)
	{
		outputFile << " - Average Df: " << KilledList.getEarthDf(y) / y << "\n\t";
	}
	else outputFile << " - Average Df: 0" << "\n\t";

	KilledList.getEarthDd(y);
	if (y != 0)
	{
		outputFile << " - Average Dd: " << KilledList.getEarthDd(y) / y << "\n\t";
	}
	else outputFile << " - Average Dd: 0" << "\n\t";

	KilledList.getEarthDb(y);
	if (y != 0)
	{
		outputFile << " - Average Db: " << KilledList.getEarthDb(y) / y << "\n\n\t";
	}
	else outputFile << " - Average Db: 0" << "\n\n\t";

	if (y != 0)
	{
		outputFile << " - DF/Db %: " << (KilledList.getEarthDf(y) / KilledList.getEarthDb(y)) * 100 << "\n\t";
	}
	else outputFile << " - DF/Db %: 0" << "\n\t";

	if (y != 0)
	{
		outputFile << " - Dd/Db %: " << (KilledList.getEarthDd(y) / KilledList.getEarthDb(y)) * 100 << "\n\n";
	}
	else outputFile << " - Dd/Db %: 0" << "\n\n";
	//alien part
	outputFile << " For Alien Army: " << "\n\t";
	outputFile << " - Total AS: " << AlienArmy.getAScreated() << "\n\t";
	outputFile << " - Total AM: " << AlienArmy.getAMcreated() << "\n\t";
	outputFile << " - Total AD: " << AlienArmy.getADcreated() << "\n\n\t";
	outputFile << " - AS destructed %: " << (AS_destructed / AlienArmy.getAScreated()) * 100 << "\n\t";
	outputFile << " - AM destructed %: " << (AM_destructed / AlienArmy.getAMcreated()) * 100 << "\n\t";
	outputFile << " - AD destructed %: " << (AD_destructed / AlienArmy.getADcreated()) * 100 << "\n\t";
	outputFile << " - Total destructed %: " << (AS_destructed + AM_destructed + AD_destructed) / (AlienArmy.getAScreated() + AlienArmy.getAMcreated() + AlienArmy.getADcreated()) * 100 << "\n\n\t";

	KilledList.getAlienDf(y);
	outputFile << " - Average Df: " << KilledList.getAlienDf(y) / y << "\n\t";
	KilledList.getAlienDd(y);
	outputFile << " - Average Dd: " << KilledList.getAlienDd(y) / y << "\n\t";
	KilledList.getAlienDb(y);
	outputFile << " - Average Db: " << KilledList.getAlienDb(y) / y << "\n\n\t";

	outputFile << " - DF/Db %: " << (KilledList.getAlienDf(y) / KilledList.getAlienDb(y)) * 100 << "\n\t";
	outputFile << " - Dd/Db %: " << (KilledList.getAlienDd(y) / KilledList.getAlienDb(y)) * 100 << "\n\n";
}

void Game::DisplayResult()
{
	switch (Whos_the_Winner)
	{
	case EARTHWON:
		cout << endl << "EARTH ARMY WON THE FIGHT" << endl;
		PlaySound(TEXT("Win.wav"), NULL, SND_SYNC);
		break;
	case ALIENWON:
		cout << endl << "ALIEN ARMY WON THE FIGHT" << endl;
		PlaySound(TEXT("Lose.wav"), NULL, SND_SYNC);
		break;
	case DRAW:
		cout << endl << "NO ONE WON ... what a disappointment ..." << endl;
		PlaySound(TEXT("Draw.wav"), NULL, SND_SYNC);
		break;
	default:
		break;
	}
}


int Game::GetInfectionPer()
{
	return InfectionPer;
}

void Game::ChooseMode()
{
	cout << "Choose I or i for Interaactive mode and S or s for Silent mode" << endl;
	char x;
	cin >> x;
	int z = 0;
	while ((x != 'I') && (x != 'i') && (x != 'S') && (x != 's'))
	{
		cout << "Pleasem, choose I or i for Interaactive mode and S or s for Silent mode" << endl;
	}
	if (x == 'I' || x == 'i')
	{
		Interactive_true_silent_false = true;
	}
	else
	{
		Interactive_true_silent_false = false;
	}
}

void Game::Simulation()
{
	ChooseMode();

	if (Interactive_true_silent_false == true)
	{
		for (int i = 0; i < 39; i++)
		{
			g2->CreateUnits();
			print();
			Attack();
			system("pause");
			cout << endl;
		}

		while (AreWeNotDoneYet())
		{
			g2->CreateUnits();
			print();
			Attack();
			WhoWon();
			system("pause");
			cout << endl;
		}
		DisplayResult();
	}
	else
	{
		cout << "simulation starts" << endl;
		for (int i = 0; i < 39; i++)
		{
			g2->CreateUnits();
			Attack();
		}

		while (AreWeNotDoneYet())
		{
			g2->CreateUnits();
			Attack();
			WhoWon();
		}
	}
	cout << "simulation end" << endl;
	generateOutputFile();
}

bool Game::Get_Interactive_true_silent_false()
{
	return Interactive_true_silent_false;
}

int Game::getCurrentTime()
{
	return CurrentTime;
}

alienArmy* Game::GetAlienArmy()
{
	alienArmy* Aptr;
	Aptr = &AlienArmy;
	return Aptr;
}

earthArmy* Game::GetEarthArmy()
{
	earthArmy* Eptr;
	Eptr = &EarthArmy;
	return Eptr;
}