#include "Defender.h"
Defender::Defender(int id, string PlayerName, string PlayerTeam, int PlayerTotalPoints, int PlayerPrice, string PlayerPosition, string PlayerStatus, bool CurrentCleanSheet, int TotalCleanSheets):Player(id, PlayerName, PlayerTeam, PlayerTotalPoints, PlayerPrice, PlayerPosition, PlayerStatus) {
	
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