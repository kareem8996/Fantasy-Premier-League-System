#pragma once
#include <iostream>
#include "gameWeek.h"
#include <vector>
using namespace std;

class Player
{
private:
	int ID;
	string FullName;
	string Team;
	string Position;
	vector<gameWeek> Player_History;
	


	int TotalPoints;
	int TotalGoals;
	int TotalAssists;
	
	int TotalYellowCards;
	int TotalRedCards;



public:
	Player();

	virtual int CalculatePoints()=0;
	virtual int CalculatePoints(int)=0;
	virtual int CalculateMatchPoints(int matchID)=0;
	Player(int id,string PlayerName, string PlayerTeam, int PlayerTotalPoints, string PlayerPosition);
	string getFullname();
	void setFullname(string Fullname);

	string getClub();
	void setClub(string PlayerTeam);


	int getTotalPoints();
	void setTotalPoints(int TPoints);
	void updateTotalPoints();

	string getPosition();
	void setPosition(string PlayerPosition);



	int getTotalGoals();
	void setTotalGoals(int PlayerGoals);
	void updateTotalGoals();



	int getTotalAssists();
	void updateTotalAssists();
	void setTotalAssists(int PlayerAssists);


	int getTotalYellowCards();
	void updateTotalYellowCards();
	void setTotalYellowCards(int YellowCards);


	int getTotalRedCards();
	void updateTotalRedCards();
	void setTotalRedCards(int RedCards);

	int getID();
	void setID(int id);
	
	vector<gameWeek> getPlayer_History();
	void updatePlayer_History(gameWeek hist);

	void updatePlayer_History(pair<int, int>);
	void increasePrice();
	void decreasePrice();

	void updateMinutes(int);

	void updateStatusGameweek(string );

	void updateGoalScoredGameweek(int goals);

	//void updatePointsGameweek();

	void updateAssistsGameweek(int);

	void updateCleansheetGameweek();

	void updateRedCardGameweek();

	void updateYellowCardsGameweek(int val);

	void updateSavesGameweek(int val);

	void updatePenaltiesMissedGameweek(int val);

	void updateBonusGameweek(int val);

	void updateOwnGoals(int val);

	void updatePenaltiesSaved(int val);

    void setWashome(bool);
    bool WasHome();

	void StartNewGameWeek(pair<int, int>);
};
	