#pragma once
#include "User.h"
#include "Player.h"
#include "Club.h"
#include <map>
class User_Team
{
private:
	map<int, Player> Squad; //player id,player object
public:
	void setSquad();
};

