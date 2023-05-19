#include "Defender.h"
#include "System.h"
Defender::Defender(int id, string PlayerName, string PlayerTeam, int PlayerTotalPoints, string PlayerPosition, int TotalCleanSheets)
	:Player(id, PlayerName, PlayerTeam, PlayerTotalPoints,PlayerPosition) {
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
	for (auto& game : getPlayer_History()) {
		if (game.getRound() == System::CurrGameWeek) {
			points += game.getGoals_scored_gameweek() * 6;
			points += game.getAssists_gameweek() * 3;
			points += game.getClean_sheets_gameweek() * 4;
			points -= game.getYellow_cards_gameweek();
			points -= game.getRed_cards_gameweek() * 3;

			if (game.getMinutesPlayed() < 60) points += 1;
			else points += 2;

			points -= game.getPenaltiesMissed() * 2;
			points += game.getBonus();
			points -= game.getOwnGoals() * 2;
			points += game.getGoalsConceded() / 2;
		}
	}
	return points;
}
int Defender::CalculateMatchPoints(int matchid) {
	int points = 0;
	for (auto& game : getPlayer_History()) {
		if (game.getmatchID() == matchid) {
			points += game.getGoals_scored_gameweek() * 6;
			points += game.getAssists_gameweek() * 3;
			points += game.getClean_sheets_gameweek() * 4;
			points -= game.getYellow_cards_gameweek();
			points -= game.getRed_cards_gameweek() * 3;

			if (game.getMinutesPlayed() < 60) points += 1;
			else points += 2;

			points -= game.getPenaltiesMissed() * 2;
			points += game.getBonus();
			points -= game.getOwnGoals() * 2;
			points += game.getGoalsConceded() / 2;
			return points;
		}
	}
}