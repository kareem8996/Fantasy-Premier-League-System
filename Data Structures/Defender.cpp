#include "Defender.h"
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