#include "randGen.h"

randGen::randGen(Game* Gp)
{
	GamePtr = Gp;
	Earth = 1;
	Aliens = 2000;
	srand(time(0));
}


void randGen::CreateUnits()
{
	Unit* UnitToinsert;
	//For Earth Army
	for (int i = 0; i < N; i++)
	{
		int A = rand() % 100 + 1; //To get chance between 1 and 100
		if (A <= Prob)
		{
			int B = rand() % 100 + 1; //To determine which type of unit 
			//This section checks for value of B to determine its type.
			if (B <= ESper)
			{
				// Generate Earth Soldier

				//Generate its hp
				int SoldierHP = HealthMinE + rand() % (HealthMaxE - HealthMinE + 1);
				//Generate its power
				int SoldierPower = PowerMinE + rand() % (PowerMaxE - PowerMinE + 1);
				//Generate its capcity
				int SoldierCapacity = AttackCapMinE + rand() % (AttackCapMaxE - AttackCapMinE + 1);
				//Generate its ID
				int ID = Earth;
				Earth++;
				UnitToinsert = new ES(ID, GamePtr->getCurrentTime(), SoldierHP, SoldierPower, SoldierCapacity, GamePtr);
				GamePtr->GetEarthArmy()->addUnit(UnitToinsert);

			}
			else if (B <= (ETper + ESper))
			{
				// Generate Earth Tank

				//Generate its hp
				int TankHP = HealthMinE + rand() % (HealthMaxE - HealthMinE + 1);
				//Generate its power
				int TankPower = PowerMinE + rand() % (PowerMaxE - PowerMinE + 1);
				//Generate its capcity
				int TankCapacity = AttackCapMinE + rand() % (AttackCapMaxE - AttackCapMinE + 1);
				//Generate its ID
				int ID = Earth;
				Earth++;
				UnitToinsert = new ET(ID, GamePtr->getCurrentTime(), TankHP, TankPower, TankCapacity, GamePtr);
				GamePtr->GetEarthArmy()->addUnit(UnitToinsert);
			}
			else if (B <= (ETper + ESper + EGper))
			{
				// Generate Earth Gunnery

				//Generate its hp
				int GunneryHP = HealthMinE + rand() % (HealthMaxE - HealthMinE + 1);
				//Generate its power
				int GunneryPower = PowerMinE + rand() % (PowerMaxE - PowerMinE + 1);
				//Generate its capcity
				int GunneryCapacity = AttackCapMinE + rand() % (AttackCapMaxE - AttackCapMinE + 1);
				//Generate its ID
				int ID = Earth;
				Earth++;
				UnitToinsert = new Earth_Gunnery(ID, GamePtr->getCurrentTime(), GunneryHP, GunneryPower, GunneryCapacity, GamePtr);
				GamePtr->GetEarthArmy()->addUnit(UnitToinsert);
			}
			else
			{
				//Generate Health Unit
				//Generate its hp
				int HealthUnitHP = HealthMinE + rand() % (HealthMaxE - HealthMinE + 1);
				//Generate its power
				int HealthUnitPower = PowerMinE + rand() % (PowerMaxE - PowerMinE + 1);
				//Generate its capcity
				int HealthUnitCapacity = AttackCapMinE + rand() % (AttackCapMaxE - AttackCapMinE + 1);
				//Generate its ID
				int ID = Earth;
				Earth++;
				UnitToinsert = new HU(ID, GamePtr->getCurrentTime(), HealthUnitHP, HealthUnitPower, HealthUnitCapacity, GamePtr);
				GamePtr->GetEarthArmy()->addUnit(UnitToinsert);
			}
			GamePtr->GetEarthArmy()->calc_created(UnitToinsert);
		}
	}
	//For Alien Army
	for (int i = 0; i < N; i++)
	{
		int A = rand() % 100 + 1; //To get chance between 1 and 100
		if (A <= Prob)
		{
			int B = rand() % 100 + 1; //To determine which type of unit 
			//This section checks for value of B to determine its type.
			if (B <= ASper)
			{
				// Generate Alien Soldier

				//Generate its hp
				int SoldierHP = HealthMinA + rand() % (HealthMaxA - HealthMinA + 1);
				//Generate its power
				int SoldierPower = PowerMinA + rand() % (PowerMaxA - PowerMinA + 1);
				//Generate its capcity
				int SoldierCapacity = AttackCapMinA + rand() % (AttackCapMaxA - AttackCapMinA + 1);
				//Generate its ID
				int ID = Aliens;
				Aliens++;
				UnitToinsert = new AS(ID, GamePtr->getCurrentTime(), SoldierHP, SoldierPower, SoldierCapacity, GamePtr);
				GamePtr->GetAlienArmy()->addUnit(UnitToinsert);
			}
			else  if (B <= (AMper + ASper))
			{
				// Generate Alien Monster

				//Generate its hp
				int MonsterHP = HealthMinA + rand() % (HealthMaxA - HealthMinA + 1);
				//Generate its power
				int MonsterPower = PowerMinA + rand() % (PowerMaxA - PowerMinA + 1);
				//Generate its capcity
				int MonsterCapacity = AttackCapMinA + rand() % (AttackCapMaxA - AttackCapMinA + 1);
				//Generate its ID
				int ID = Aliens;
				Aliens++;
				UnitToinsert = new Alien_Monster(ID, GamePtr->getCurrentTime(), MonsterHP, MonsterPower, MonsterCapacity, GamePtr);
				GamePtr->GetAlienArmy()->addUnit(UnitToinsert);
			}
			else
			{
				// Generate Alien Drone

				//Generate its hp
				int DroneHP = HealthMinA + rand() % (HealthMaxA - HealthMinA + 1);
				//Generate its power
				int DronePower = PowerMinA + rand() % (PowerMaxA - PowerMinA + 1);
				//Generate its capcity
				int DroneCapacity = AttackCapMinA + rand() % (AttackCapMaxA - AttackCapMinA + 1);
				//Generate its ID
				int ID = Aliens;
				Aliens++;
				UnitToinsert = new Drone(ID, GamePtr->getCurrentTime(), DroneHP, DronePower, DroneCapacity, GamePtr);
				GamePtr->GetAlienArmy()->addUnit(UnitToinsert);
			}
			GamePtr->GetAlienArmy()->calc_created(UnitToinsert);
		}
	}
}

void randGen::setN(int input)
{
	N = input;
}

void randGen::setESper(int input)
{
	ESper = input;
}

void randGen::setETper(int input)
{
	ETper = input;
}

void randGen::setEGper(int input)
{
	EGper = input;
}

void randGen::setASper(int input)
{
	ASper = input;
}

void randGen::setAMper(int input)
{
	AMper = input;
}

void randGen::setADper(int input)
{
	ADper = input;
}

void randGen::setProb(int input)
{
	Prob = input;
}

void randGen::setPowerMinE(int input)
{
	PowerMinE = input;
}

void randGen::setHUper(int input)
{
	HUper = input;
}

void randGen::setPowerMaxE(int input)
{
	PowerMaxE = input;
}

void randGen::SetHealthMinE(int index)
{
	HealthMinE = index;
}

void randGen::SetHealthMaxE(int index)
{
	HealthMaxE = index;
}

void randGen::SetAttackCapMinE(int index)
{
	AttackCapMinE = index;
}

void randGen::SetAttackCapMaxE(int index)
{
	AttackCapMaxE = index;
}

void randGen::SetPowerMinA(int index)
{
	PowerMinA = index;
}

void randGen::SetPowerMaxA(int index)
{
	PowerMaxA = index;
}

void randGen::SetHealthMinA(int index)
{
	HealthMinA = index;
}

void randGen::SetHealthMaxA(int index)
{
	HealthMaxA = index;
}

void randGen::SetAttackCapMinA(int index)
{
	AttackCapMinA = index;
}

void randGen::SetAttackCapMaxA(int index)
{
	AttackCapMaxA = index;
}

