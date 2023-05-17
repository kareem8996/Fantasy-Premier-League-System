#pragma once
#include <iostream>
#include "string"
#include"Player.h"
#include <unordered_map>
using namespace std;


class Club
{
private:
	int ID;
	string Name;
	unordered_map<int, Player*> Squad;
	int LeaguePoints;
	vector<int> Fixtures;
public:
	Club(int,string);
	void setName(string Name);
	void setLeaguePoints(int LeaguePoints);
	string getName();
	
	int getLeaguePoints();
	void win_UpdatePoints();
	void draw_UpdatePoints();
	
	void insertPlayer(Player*playerToBeInserted);
	void deletePlayer(int playerToBeDeleted);
	void deletePlayer(Player* playerToBeDeleted);
	
	void setFixtures(vector<int>);
	vector<int> getFixtures();
	void updateFixtures(int);

	bool isSquadEmpty();

	unordered_map<int, Player*> getSquad();

	void DisplaySquad();
	int getClubID();
};	