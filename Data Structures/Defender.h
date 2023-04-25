#pragma once
#include "Player.h"
using namespace std;
class Defender : public Player
{
private:

	bool CurrentCleanSheet;
	int TotalCleanSheets;
public:

	bool getCurrentCleanSheet();
	void setCurrentCleanSheet(bool Cleansheet);
	int getTotalCleanSheets();
	void updateTotalCleanSheets();
	void setTotalCleanSheets(int CleanSheet);
};

