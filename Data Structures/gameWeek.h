#pragma once
#include <string>
#include <vector>
using namespace std;
class gameWeek
{
private:
	string status;
	int value,
		total_points_gameweek,
		goals_scored_gameweek,
		assists_gameweek,
		clean_sheets_gameweek,
		red_cards_gameweek,
		yellow_cards_gameweek,
		saves_gameweek;
public:
	gameWeek();
	gameWeek(string status,
		int value,
		int total_points_gameweek,
		int goals_scored_gameweek,
		int assists_gameweek,
		int clean_sheets_gameweek,
		int red_cards_gameweek,
		int yellow_cards_gameweek,
		int saves_gameweek);

	void setStatus(string s);
	void setValue(int n);
	void setTotal_points_gameweek(int n);
	void setGoals_scored_gameweek(int n);
	void setAssists_gameweek(int n);
	void setClean_sheets_gameweek(int n);
	void setRed_cards_gameweek(int n);
	void setYellow_cards_gameweek(int n);
	void setSaves_gameweek(int n);

	string getStatus();
	int getValue();
	int getTotal_points_gameweek();
	int getGoals_scored_gameweek();
	int getAssists_gameweek();
	int getClean_sheets_gameweek();
	int getRed_cards_gameweek();
	int getYellow_cards_gameweek();
	int getSaves_gameweek();

};

