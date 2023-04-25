#include "Player.h"
#include <iostream>
using namespace std;

Player::Player() {
	FullName = "";
	Team = "";
	Points = 0;
	Price = 0;
	Position = "";
	Status = "";
}
Player::Player(int id,string PlayerName, string PlayerTeam, int PlayerTotalPoints, int PlayerPrice, string PlayerPosition, string PlayerStatus) {
	ID = id;
	FullName = PlayerName;
	Team = PlayerTeam;
	Points = PlayerTotalPoints;
	Price = PlayerPrice;
	Position = PlayerPosition;
	Status = PlayerStatus;
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


int Player::getPrice() {
	return Price;
}
void Player::setPrice(int PlayerPrice) {
	Price = PlayerPrice;
}
void Player::increasePrice() {
	Price += 1;
}
void Player::decreasePrice() {
	Price -= 1;
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

