#pragma once
#include "Player.h"
using namespace std;
class Midfielder : public Player
{
private:

	bool CurrentCleanSheet;
	int TotalCleanSheets;

public:
	Midfielder(int id, string PlayerName, string PlayerTeam, int PlayerTotalPoints, string PlayerPosition,int TotalCleanSheets);
	int CalculatePoints();
	int CalculatePoints(int);
	int CalculateMatchPoints(int matchid);
	bool getCurrentCleanSheet();
	void setCurrentCleanSheet(bool Cleansheet);
	int getTotalCleanSheets();
	void updateTotalCleanSheets();
	void setTotalCleanSheets(int CleanSheet);
};

