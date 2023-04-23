#pragma once
#include <iostream>
#include "string"
#include"Player.h"
#include <map>
using namespace std;


class Club
{
private:
	string Name;
	map<int, Player> Squad;
	string NextFixture;
	int LeaguePoints;
public:
	Club(string ClubName, string ClubNextFixture, int ClubLeaguePoints);
	void setName(string Name);
	void setNextFixture(string NextFixture);
	void setLeaguePoints(int LeaguePoints);
	string getName();
	string getNextFixture();
	int getLeaguePoints();
	void win_UpdatePoints();
	void draw_UpdatePoints();
	void insertPlayer(Player playerToBeInserted);
	void deletePlayer(int playerToBeDeleted);
	void deletePlayer(Player playerToBeDeleted);

};	