#include "GoalKeeper.h"

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