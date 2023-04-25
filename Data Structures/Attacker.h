#pragma once
#include "Player.h"
using namespace std;

class Attacker : public Player
{
public:
	Attacker(int id, string PlayerName, string PlayerTeam, int PlayerTotalPoints, int PlayerPrice, string PlayerPosition, string PlayerStatus);
};

