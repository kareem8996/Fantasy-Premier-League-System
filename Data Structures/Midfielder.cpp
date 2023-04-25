#include "Midfielder.h"

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