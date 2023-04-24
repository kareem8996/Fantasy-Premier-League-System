#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(string PlayerName, string PlayerTeam, int PlayerTotalPoints, float PlayerPrice, string PlayerPosition, string PlayerStatus, int PlayerNumber) {
	FullName = PlayerName;
	Team = PlayerTeam;
	Points = 0;
	Price = PlayerPrice;
	Position = PlayerPosition;
	Status = PlayerStatus;
	Number = PlayerNumber;
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

int Player::getPoints() {
	return Points;
}
void Player::setPoints(int PLayerPoints) {
	Points += PLayerPoints;
}
void Player::ResetPoints() {
	Points = 0;
}


float Player::getPrice() {
	return Price;
}
void Player::setPrice(float PlayerPrice) {
	Price = PlayerPrice;
}
void Player::increasePrice() {
	Price += 0.1;
}
void Player::decreasePrice() {
	Price -= 0.1;
}


int Player::getTotalPoints() {
	return TotalPoints;
}

void Player::setTotalPoints(int TPoints) {
	TotalPoints = TPoints;
}
void Player::updateTotalPoints() {
	TotalPoints += Points;
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

int Player::getNumber() {
	return Number;
}
void Player::setNumber(int PlayerNumber) {
	Number = PlayerNumber;
}



void Player::setGoals(int goals) {
	Goals = goals;
}

void Player::setTotalGoals(int totalGoals) {
	TotalGoals = totalGoals;
}

void Player::setAssists(int assists) {
	Assists = assists;
}

void Player::setTotalAssists(int totalAssists) {
	TotalAssists = totalAssists;
}

void Player::setCurrentCleanSheet(bool currentCleanSheet) {
	CurrentCleanSheet = currentCleanSheet;
}

void Player::setTotalCleanSheets(int totalCleanSheets) {
	TotalCleanSheets = totalCleanSheets;
}

void Player::setYellowCards(int yellowCards) {
	YellowCards = yellowCards;
}

void Player::setTotalYellowCards(int totalYellowCards) {
	TotalYellowCards = totalYellowCards;
}

void Player::setRedCards(int redCards) {
	RedCards = redCards;
}

void Player::setTotalRedCards(int totalRedCards) {
	TotalRedCards = totalRedCards;
}

// Getters
int Player::getGoals() {
	return Goals;
}

int Player::getTotalGoals() {
	return TotalGoals;
}

int Player::getAssists() {
	return Assists;
}

int Player::getTotalAssists() {
	return TotalAssists;
}

bool Player::getCurrentCleanSheet() {
	return CurrentCleanSheet;
}

int Player::getTotalCleanSheets() {
	return TotalCleanSheets;
}

int Player::getYellowCards() {
	return YellowCards;
}

int Player::getTotalYellowCards() {
	return TotalYellowCards;
}

int Player::getRedCards() {
	return RedCards;
}

int Player::getTotalRedCards() {
	return TotalRedCards;
}

void Player::updateTotalAssists() {
	TotalAssists += Assists;
}

void Player::updateTotalGoals() {
	TotalGoals += Goals;
}

void Player::updateTotalCleanSheets() {
	if (CurrentCleanSheet)
		TotalCleanSheets++;
}

void Player::updateTotalYellowCards() {
	TotalYellowCards += YellowCards;
}

void Player::updateTotalRedCards() {
	TotalRedCards += RedCards;
}

int Player::getID() {
	return ID;
}

void Player::setID(int id) {
	ID = id;
}