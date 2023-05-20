#include "GoalKeeper.h"
#include "System.h"

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

int GoalKeeper::CalculatePoints(int week) {
	int points = 0;
	for (auto& game : getPlayer_History()) {
		if (game.getRound() == week) {
			points += game.getGoals_scored_gameweek() * 6;
			points += game.getAssists_gameweek() * 3;
			points += game.getClean_sheets_gameweek() * 4;
			points += game.getSaves_gameweek() / 3;
			points -= game.getYellow_cards_gameweek();
			points -= game.getRed_cards_gameweek() * 3;

			if (game.getMinutesPlayed() < 60 && game.getMinutesPlayed() > 0) points += 1;
			else if (game.getMinutesPlayed() >= 60)points += 2;

			points -= game.getPenaltiesMissed() * 2;
			points += game.getBonus();
			points -= game.getOwnGoals() * 2;
			points += game.getGoalsConceded() / 2;
			points += game.getPenaltiesSaved() * 5;
		}
	}
	return points;
}
int GoalKeeper::CalculatePoints() {
	return CalculatePoints(System::CurrGameWeek);
}

int GoalKeeper::CalculateMatchPoints(int matchid) {
	int points = 0;
	for (auto& game : getPlayer_History()) {
		if (game.getmatchID() == matchid) {
			points += game.getGoals_scored_gameweek() * 6;
			points += game.getAssists_gameweek() * 3;
			points += game.getClean_sheets_gameweek() * 4;
			points += game.getSaves_gameweek() / 3;
			points -= game.getYellow_cards_gameweek();
			points -= game.getRed_cards_gameweek() * 3;

			if (game.getMinutesPlayed() < 60 && game.getMinutesPlayed() > 0) points += 1;
			else if (game.getMinutesPlayed() >= 60)points += 2;

			points -= game.getPenaltiesMissed() * 2;
			points += game.getBonus();
			points -= game.getOwnGoals() * 2;
			points += game.getGoalsConceded() / 2;
			points += game.getPenaltiesSaved() * 5;
			return points;
		}
	}
}
