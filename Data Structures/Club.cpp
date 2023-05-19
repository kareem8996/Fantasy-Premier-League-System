#include "Club.h"

#include <iostream>
using namespace std;
Club::Club(int id,string clubname)
{
	Name = clubname;
	ID = id;
}
void Club::setName(string ClubName) {
	Name = ClubName;
}
void Club::setLeaguePoints(int ClubLeaguePoints) {
	LeaguePoints = ClubLeaguePoints;
}
string Club::getName() {
	return Name;
}
int Club::getLeaguePoints() {
	return LeaguePoints;
}
void  Club::win_UpdatePoints()
{
	LeaguePoints += 3;
}
void  Club::draw_UpdatePoints() {
	LeaguePoints += 1;
}
void  Club::insertPlayer(Player* playerToBeInserted) {
	Squad.insert({ playerToBeInserted->getID() , playerToBeInserted });
}
void  Club::deletePlayer(int playerToBeDeleted) {
	Squad.erase(playerToBeDeleted);
}
void  Club::deletePlayer(Player* playerToBeDeleted) {
	Squad.erase(playerToBeDeleted->getID());
}

void Club::setFixtures(vector<pair<int,int>> fix)
{
	Fixtures = fix;
}

vector<pair<int, int>> Club::getFixtures()
{
	return Fixtures;
}

void Club::updateFixtures( int gameweek ,int fix )
{
	Fixtures.push_back({ gameweek,fix });
}

bool Club::isSquadEmpty() {
	return Squad.empty();
}

unordered_map<int, Player*> Club::getSquad() {
	return Squad;
}

void Club::DisplaySquad()
{
	for (auto player : Squad) {

		cout<< "\t" << player.first << "\t" << player.second->getFullname()<<endl;

	}
}


int Club::getClubID() {
	return ID;
}
