#pragma once
#include <string>
#include <vector>
#include"fixture.h"
using namespace std;
class gameWeek
{
private:
	string status;
	int round,
		value,
		total_points_gameweek,
		goals_scored_gameweek,
		assists_gameweek,
		clean_sheets_gameweek,
		red_cards_gameweek,
		yellow_cards_gameweek,
		saves_gameweek,



		minutes_played,
		penalties_missed,
		bonus,
		goals_conceded,
		own_goals,
		penalties_saved;
	bool wasHome;
	int match_ID;
public:
	gameWeek();
	gameWeek(string status,
		int round,
		int value,
		int total_points_gameweek,
		int goals_scored_gameweek,
		int assists_gameweek,
		int clean_sheets_gameweek,
		int red_cards_gameweek,
		int yellow_cards_gameweek,
		int saves_gameweek,
		int minutes_played,
		int penalties_missed,
		int bonus,
		int goals_conceded,
		int own_goals,
		int penalties_saved,
		int matchid);

	void setStatus(string s);
	void setValue(int n);
	void setTotal_points_gameweek(int n);
	void setGoals_scored_gameweek(int n);
	void setAssists_gameweek(int n);
	void setClean_sheets_gameweek();
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

	// Getter and setter for minutes_played
	int getMinutesPlayed();
	void setMinutesPlayed(int minutes);
	
	// Getter and setter for penalties_missed
	int getPenaltiesMissed();
	void setPenaltiesMissed(int penalties);

	// Getter and setter for bonus
	int getBonus();
	void setBonus(int bonus_value);

	// Getter and setter for goals_conceded
	int getGoalsConceded();
	void setGoalsConceded();

	// Getter and setter for own_goals
	int getOwnGoals();
	void setOwnGoals(int own);

	int getPenaltiesSaved();
	void getPenaltiesSaved(int saved);

	void increaseValue();

	void decreaseValue();

	bool getFixtureCleansheet();
	int  getFixtureGoalConceded();

	void setWashome(bool);
	bool WasHome();
	void updateFixture(int,bool);
	Fixture* getFixture();
	

	void updatePenaltiesSaved(int val);
	void updateOwnGoals(int val);
	void updatePenaltiesMissed(int val);
	void updateGoals_scored_gameweek(int goals);
	void updateYellow_Cards_gameweek(int val);
	void updateAssists_gameweek(int assists);
	void updateSaves_gameweek(int saves);
	int getmatchID();
	void setmatchID(int matchID);
	void setRound(int r);
	int getRound();
	void displayGameweek(string pos);
};

