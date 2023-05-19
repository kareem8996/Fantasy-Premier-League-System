#include "System.h"
#include "Player.h"
#include <iostream>
using namespace std;

Player::Player() {
	FullName = "";
	Team = "";
	TotalPoints = 0;
	Position = "";
}
Player::Player(int id,string PlayerName, string PlayerTeam, int PlayerTotalPoints, string PlayerPosition) {
	ID = id;
	FullName = PlayerName;
	Team = PlayerTeam;
	TotalPoints = PlayerTotalPoints;
	Position = PlayerPosition;

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

//FROM FIXTURES
//goals_conceded,
// clean sheet
// 
// 

//bool wasHome;
//Fixture match;
void Player::updateMinutes(int Minutes)
{
	Player_History.back().setMinutesPlayed(Minutes);
	Player_History.back().setClean_sheets_gameweek();
	Player_History.back().setGoalsConceded();
}

void Player::updateStatusGameweek(string status)
{
	Player_History.back().setStatus(status);
}
void Player::updateGoalScoredGameweek(int goals)
{
	Player_History.back().updateGoals_scored_gameweek(goals);
	
}
void Player::updatePointsGameweek()
{
	Player_History.back().setTotal_points_gameweek(CalculatePoints());
}

void Player::updateAssistsGameweek(int assists)
{
	Player_History.back().updateAssists_gameweek(assists);
}

void Player::updateCleansheetGameweek()
{
	Player_History.back().setClean_sheets_gameweek();
}

void Player::updateRedCardGameweek()
{
	Player_History.back().setRed_cards_gameweek(1);
}

void Player::updateYellowCardsGameweek(int val)
{
	Player_History.back().updateYellow_Cards_gameweek(val);
}

void Player::updateSavesGameweek(int val)
{
	Player_History.back().updateSaves_gameweek(val);
}

void Player::updatePenaltiesMissedGameweek(int val)
{
	Player_History.back().updatePenaltiesMissed(val);
}

void Player::updateBonusGameweek(int val)
{
	Player_History.back().setBonus(val);
}
void Player::updateOwnGoals(int val)
{
	Player_History.back().updateOwnGoals(val);
}

void Player::updatePenaltiesSaved(int val) {
	Player_History.back().updatePenaltiesSaved(val);

}


void Player::setWashome(bool) {
	int homeTeamId = Player_History.back().getFixture()->getHomeTeam();
	int playerTeam = System::AllClubs[Team]->getClubID();
	if (playerTeam == homeTeamId)
		Player_History.back().setWashome(true);
	else
		Player_History.back().setWashome(false);
}

bool Player::WasHome() {
	return Player_History.back().WasHome();
}
