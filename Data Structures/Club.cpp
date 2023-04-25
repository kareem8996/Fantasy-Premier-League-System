#include "Club.h"

#include <iostream>
using namespace std;
Club::Club(string ClubName, string ClubNextFixture, int ClubLeaguePoints)
{
	Name = ClubName;
	NextFixture = ClubNextFixture;
	LeaguePoints = ClubLeaguePoints;
}
void Club::setName(string ClubName) {
	Name = ClubName;
}
void Club::setNextFixture(string ClubNextFixture) {
	NextFixture = ClubNextFixture;
}
void Club::setLeaguePoints(int ClubLeaguePoints) {
	LeaguePoints = ClubLeaguePoints;
}
string Club::getName() {
	return Name;
}
string Club::getNextFixture() {
	return NextFixture;
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
void  Club::insertPlayer(Player playerToBeInserted) {
	Squad.insert({ playerToBeInserted.getID() , playerToBeInserted });
}
void  Club::deletePlayer(int playerToBeDeleted) {
	Squad.erase(playerToBeDeleted);
}
void  Club::deletePlayer(Player playerToBeDeleted) {
	Squad.erase(playerToBeDeleted.getID());
}
