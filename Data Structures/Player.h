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
	int Price;
	string Position;
	string Status;
	vector<gameWeek> Player_History;
	


	int TotalPoints;
	int TotalGoals;
	int TotalAssists;
	
	int TotalYellowCards;
	int TotalRedCards;



public:
	Player();

	virtual int CalculatePoints()=0;
	Player(int id,string PlayerName, string PlayerTeam, int PlayerTotalPoints, int PlayerPrice, string PlayerPosition, string PlayerStatus);
	string getFullname();
	void setFullname(string Fullname);

	string getClub();
	void setClub(string PlayerTeam);


	int getPrice();
	void setPrice(int PlayerPrice);
	void increasePrice();
	void decreasePrice();

	int getTotalPoints();
	void setTotalPoints(int TPoints);
	void updateTotalPoints();

	string getPosition();
	void setPosition(string PlayerPosition);

	string getStatus();
	void setStatus(string PlayerStatus);



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
	
};
	