#include "GoalKeeper.h"

GoalKeeper::GoalKeeper(int id, string PlayerName, string PlayerTeam, int PlayerTotalPoints,string PlayerPosition,int TotalSaves,int TotalCleanSheets) 
	:Player(id, PlayerName, PlayerTeam, PlayerTotalPoints, PlayerPosition){
	this->TotalCleanSheets = TotalCleanSheets;
	this->TotalSaves = TotalSaves;
}

void GoalKeeper::setCurrentCleanSheet(bool currentCleanSheet) {
	CurrentCleanSheet = currentCleanSheet;
}

void GoalKeeper::setTotalCleanSheets(int totalCleanSheets) {
	TotalCleanSheets = totalCleanSheets;
}

bool GoalKeeper::getCurrentCleanSheet() {
	return CurrentCleanSheet;
}

int GoalKeeper::getTotalCleanSheets() {
	return TotalCleanSheets;
}

void GoalKeeper::updateTotalCleanSheets() {
	if (CurrentCleanSheet)
		TotalCleanSheets++;
}

int GoalKeeper::getSaves() {
	return Saves;
}

void GoalKeeper::setSaves(int saves) {
	Saves = saves;
}

int GoalKeeper::getTotalSaves() {
	return TotalSaves;
}

void GoalKeeper::setTotalSaves(int totalsave) {
	TotalSaves = totalsave;
}

void GoalKeeper::updateTotalSaves() {
	TotalSaves += Saves;
}

int GoalKeeper::CalculatePoints() {
	int points = 0;
	points += this->getPlayer_History().back().getGoals_scored_gameweek() * 6;
	points += this->getPlayer_History().back().getAssists_gameweek() * 3;
	points += this->getPlayer_History().back().getClean_sheets_gameweek() * 4;
	points += this->getPlayer_History().back().getSaves_gameweek()/3;
	points -= this->getPlayer_History().back().getYellow_cards_gameweek();
	points -= this->getPlayer_History().back().getRed_cards_gameweek() * 3;

	if (this->getPlayer_History().back().getMinutesPlayed() < 60) points += 1;
	else points += 2;

	points -= this->getPlayer_History().back().getPenaltiesMissed() * 2;
	points += this->getPlayer_History().back().getBonus();
	points -= this->getPlayer_History().back().getOwnGoals() * 2;
	points += this->getPlayer_History().back().getGoalsConceded() / 2;
	points += this->getPlayer_History().back().getPenaltiesSaved() * 5;
	return points;
}
