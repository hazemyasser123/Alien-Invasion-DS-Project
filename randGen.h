#include <cstdlib>
#include <ctime>
#include <random>
#include "Game.h"
class Game;
using namespace std;

#ifndef RANDGEN
#define RANDGEN

class randGen
{
protected:
	Game* GamePtr;
	int Earth;
	int Aliens;
	int CurrentTime;
	int N;
	int ESper;
	int ETper;
	int EGper;
	int ASper;
	int AMper;
	int ADper;
	int HUper;
	int Prob;
	int PowerMinE;
	int PowerMaxE;
	int HealthMinE;
	int HealthMaxE;
	int AttackCapMinE;
	int AttackCapMaxE;
	int PowerMinA;
	int PowerMaxA;
	int HealthMinA;
	int HealthMaxA;
	int AttackCapMinA;
	int AttackCapMaxA;
public:
	randGen(Game* Gp);
	void CreateUnits();
	void setN(int input);
	void setESper(int input);
	void setETper(int input);
	void setEGper(int input);
	void setASper(int input);
	void setAMper(int input);
	void setADper(int input);
	void setHUper(int input);
	void setProb(int input);
	void setPowerMinE(int input);
	void setPowerMaxE(int input);
	void SetHealthMinE(int index);
	void SetHealthMaxE(int index);
	void SetAttackCapMinE(int index);
	void SetAttackCapMaxE(int index);
	void SetPowerMinA(int index);
	void SetPowerMaxA(int index);
	void SetHealthMinA(int index);
	void SetHealthMaxA(int index);
	void SetAttackCapMinA(int index);
	void SetAttackCapMaxA(int index);

};

#endif
