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
