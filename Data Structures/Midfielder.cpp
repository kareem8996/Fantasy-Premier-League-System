#include "Midfielder.h"
Midfielder::Midfielder(int id, string PlayerName, string PlayerTeam, int PlayerTotalPoints, string PlayerPosition,int TotalCleanSheets)
:Player(id, PlayerName, PlayerTeam, PlayerTotalPoints, PlayerPosition)
{
	this->TotalCleanSheets = TotalCleanSheets;
}
void Midfielder::setCurrentCleanSheet(bool currentCleanSheet) {
	CurrentCleanSheet = currentCleanSheet;
}

void Midfielder::setTotalCleanSheets(int totalCleanSheets) {
	TotalCleanSheets = totalCleanSheets;
}

bool Midfielder::getCurrentCleanSheet() {
	return CurrentCleanSheet;
}

int Midfielder::getTotalCleanSheets() {
	return TotalCleanSheets;
}

void Midfielder::updateTotalCleanSheets()
{
	TotalCleanSheets += CurrentCleanSheet;
}
int Midfielder::CalculatePoints() {
	int points = 0;
	points += this->getPlayer_History().back().getGoals_scored_gameweek() * 5;
	points += this->getPlayer_History().back().getAssists_gameweek() * 3;
	points += this->getPlayer_History().back().getClean_sheets_gameweek();
	points -= this->getPlayer_History().back().getYellow_cards_gameweek();
	points -= this->getPlayer_History().back().getRed_cards_gameweek() * 3;
	if (this->getPlayer_History().back().getMinutesPlayed() < 60) points += 1;
	else points += 2;

	points -= this->getPlayer_History().back().getPenaltiesMissed() * 2;
	points += this->getPlayer_History().back().getBonus();
	points -= this->getPlayer_History().back().getOwnGoals() * 2;
	return points;
}
