#include "Defender.h"
Defender::Defender(int id, string PlayerName, string PlayerTeam, int PlayerTotalPoints, int PlayerPrice, string PlayerPosition, string PlayerStatus, int TotalCleanSheets)
	:Player(id, PlayerName, PlayerTeam, PlayerTotalPoints, PlayerPrice, PlayerPosition, PlayerStatus) {
	this->TotalCleanSheets = TotalCleanSheets;
}
void Defender::setCurrentCleanSheet(bool currentCleanSheet) {
	CurrentCleanSheet = currentCleanSheet;
}

void Defender::setTotalCleanSheets(int totalCleanSheets) {
	TotalCleanSheets = totalCleanSheets;
}

bool Defender::getCurrentCleanSheet() {
	return CurrentCleanSheet;
}

int Defender::getTotalCleanSheets() {
	return TotalCleanSheets;
}

void Defender::updateTotalCleanSheets() {
	if (CurrentCleanSheet)
		TotalCleanSheets++;
}
int Defender::CalculatePoints() {
	int points = 0;
	points += this->getPlayer_History().back().getGoals_scored_gameweek() * 6;
	points += this->getPlayer_History().back().getAssists_gameweek() * 3;
	points += this->getPlayer_History().back().getClean_sheets_gameweek()*4;
	points -= this->getPlayer_History().back().getYellow_cards_gameweek();
	points -= this->getPlayer_History().back().getRed_cards_gameweek() * 3;

	if (this->getPlayer_History().back().getMinutesPlayed() < 60) points += 1;
	else points += 2;

	points -= this->getPlayer_History().back().getPenaltiesMissed() * 2;
	points += this->getPlayer_History().back().getBonus();
	points -= this->getPlayer_History().back().getOwnGoals() * 2;
	points += this->getPlayer_History().back().getGoalsConceded() / 2;
	return points;
}