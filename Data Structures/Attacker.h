#pragma once
#include "Player.h"
using namespace std;

class Attacker : public Player
{
public:
	int CalculatePoints();
	int CalculatePoints(int);
	int CalculateMatchPoints(int matchID);
	Attacker(int id, string PlayerName, string PlayerTeam, int PlayerTotalPoints, string PlayerPosition);
};


