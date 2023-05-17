#pragma once
#include "Player.h"
using namespace std;
class GoalKeeper : public Player
{
private:

	int TotalSaves;
	int Saves;
	bool CurrentCleanSheet;
	int TotalCleanSheets;
public:
	GoalKeeper(int id, string PlayerName, string PlayerTeam, int PlayerTotalPoints, string PlayerPosition, string PlayerStatus, int TotalSaves, int TotalCleanSheets);
	int CalculatePoints();
	bool getCurrentCleanSheet();
	void setCurrentCleanSheet(bool Cleansheet);

	int getTotalCleanSheets();
	void updateTotalCleanSheets();
	void setTotalCleanSheets(int CleanSheet);

	int getSaves();
	void setSaves(int save);

	int getTotalSaves();
	void setTotalSaves(int totalsave);
	void updateTotalSaves();
};

