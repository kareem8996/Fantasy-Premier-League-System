#pragma once
#include "Player.h"
using namespace std;

class Attacker : public Player
{
public:
	int CalculatePoints();
	Attacker(int id, string PlayerName, string PlayerTeam, int PlayerTotalPoints, string PlayerPosition, string PlayerStatus);
};


