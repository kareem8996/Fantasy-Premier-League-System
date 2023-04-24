#pragma once
#include "User.h"
#include "Player.h"
#include "Club.h"
#include <map>
class User_Team
{
private:
	map<int, Player> Squad;//player id,player object
	int totalPlayers; //total number of players picked
	int totalAttackers; //total number of attackers picked
	int totalDefenders;//total number of defenders picked
	int totalMidfielders;//total number of midfielders picked
	bool isGoalKeeper; //was GoalKeeper picked
	int totalPrice;
	map<string, int> teamCount; // this is a map to count number of player picked in each team ex: Chelsea, 2


public:
	static const int MAX_PLAYERS = 11;
	static const int MAX_BUDGET = 100000000; //100 million
	static const int MAX_GOALKEEPERS = 1;
	static const int MAX_DEFENDERS = 5;
	static const int MAX_MIDFIELDERS = 5;
	static const int MAX_ATTACKERS = 4;
	void pickSquad();
	void pickPlayer(Player p);
	bool canAddPlayerPosition(string pos); //validation for position
	bool canAddPlayerPrice(Player p); //validation for price
	bool canAddPlayerCount(Player p); //validation for teamCount
	
};

