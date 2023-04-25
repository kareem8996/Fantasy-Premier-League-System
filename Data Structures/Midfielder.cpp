#include "Midfielder.h"
Midfielder::Midfielder(int id, string PlayerName, string PlayerTeam, int PlayerTotalPoints, int PlayerPrice, string PlayerPosition, string PlayerStatus, int TotalCleanSheets)
:Player(id, PlayerName, PlayerTeam, PlayerTotalPoints, PlayerPrice, PlayerPosition, PlayerStatus)
{
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
