#include "Player.h"
#include <iostream>
using namespace std;

Player::Player() {
	FullName = "";
	Team = "";
	TotalPoints = 0;
	Position = "";
	Status = "";

}
Player::Player(int id,string PlayerName, string PlayerTeam, int PlayerTotalPoints, string PlayerPosition, string PlayerStatus) {
	ID = id;
	FullName = PlayerName;
	Team = PlayerTeam;
	TotalPoints = PlayerTotalPoints;
	Position = PlayerPosition;
	Status = PlayerStatus;

	TotalGoals = 0;
	TotalAssists = 0;
	TotalYellowCards = 0;
	TotalRedCards = 0;
}

string Player::getFullname() {
	return FullName;
}
void Player::setFullname(string Fullname) {
	FullName = Fullname;
}

string Player::getClub() {
	return Team;
}
void Player::setClub(string PlayerTeam) {
	Team = PlayerTeam;
}

//int Player::getPoints() {
//	return Points;
//}
//void Player::setPoints(int PLayerPoints) {
//	Points += PLayerPoints;
//}
//void Player::ResetPoints() {
//	Points = 0;
//}





int Player::getTotalPoints() {
	return TotalPoints;
}

void Player::setTotalPoints(int TPoints) {
	TotalPoints = TPoints;
}
void Player::updateTotalPoints() {
	TotalPoints += Player_History.back().getTotal_points_gameweek();
}

string Player::getPosition() {
	return Position;
}
void Player::setPosition(string PlayerPosition) {
	Position = PlayerPosition;
}

string Player::getStatus() {
	return Status;
}
void Player::setStatus(string PlayerStatus) {
	Status = PlayerStatus;
}


//
//void Player::setGoals(int goals) {
//	Goals = goals;
//}

void Player::setTotalGoals(int totalGoals) {
	TotalGoals = totalGoals;
}

//void Player::setAssists(int assists) {
//	Assists = assists;
//}

void Player::setTotalAssists(int totalAssists) {
	TotalAssists = totalAssists;
}
//
//void Player::setYellowCards(int yellowCards) {
//	YellowCards = yellowCards;
//}

void Player::setTotalYellowCards(int totalYellowCards) {
	TotalYellowCards = totalYellowCards;
}
//
//void Player::setRedCards(int redCards) {
//	RedCards = redCards;
//}

void Player::setTotalRedCards(int totalRedCards) {
	TotalRedCards = totalRedCards;
}

// Getters
//int Player::getGoals() {
//	return Goals;
//}

int Player::getTotalGoals() {
	return TotalGoals;
}

/*nt Player::getAssists() {
	return Assists;
}*/

int Player::getTotalAssists() {
	return TotalAssists;
}


//int Player::getYellowCards() {
//	return YellowCards;
//}

int Player::getTotalYellowCards() {
	return TotalYellowCards;
}

//int Player::getRedCards() {
//	return RedCards;
//}

int Player::getTotalRedCards() {
	return TotalRedCards;
}

void Player::updateTotalAssists() {
	TotalAssists += Player_History.back().getAssists_gameweek();
}

void Player::updateTotalGoals() {
	TotalGoals += Player_History.back().getGoals_scored_gameweek();
}


void Player::updateTotalYellowCards() {
	TotalYellowCards += Player_History.back().getYellow_cards_gameweek();
}

void Player::updateTotalRedCards() {
	TotalRedCards += Player_History.back().getRed_cards_gameweek();
}

int Player::getID() {
	return ID;
}

void Player::setID(int id) {
	ID = id;
}

vector<gameWeek> Player::getPlayer_History()
{
	return Player_History;
}

void Player::updatePlayer_History(gameWeek hist)
{
	Player_History.push_back(hist);
}
void Player::updatePlayer_History()
{
	gameWeek game;
	Player_History.push_back(game);
}

void Player::StartNewGameWeek()
{
	Player_History.back().setTotal_points_gameweek (this->CalculatePoints());
	updatePlayer_History();
}

void Player::increasePrice()
{
	Player_History.back().increaseValue();
}

void Player::decreasePrice()
{
	Player_History.back().decreaseValue();
}

