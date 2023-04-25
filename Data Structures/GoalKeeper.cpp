#include "GoalKeeper.h"

GoalKeeper::GoalKeeper(int id, string PlayerName, string PlayerTeam, int PlayerTotalPoints, int PlayerPrice, string PlayerPosition, string PlayerStatus,int TotalSaves,int TotalCleanSheets) 
	:Player(id, PlayerName, PlayerTeam, PlayerTotalPoints, PlayerPrice, PlayerPosition, PlayerStatus){
	
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