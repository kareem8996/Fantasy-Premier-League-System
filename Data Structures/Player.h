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
	Player(int id,string PlayerName, string PlayerTeam, int PlayerTotalPoints, int PlayerPrice, string PlayerPosition, string PlayerStatus);
	string getFullname();
	void setFullname(string Fullname);

	string getClub();
	void setClub(string PlayerTeam);

	//int getPoints();
	//void setPoints(int PLayerPoints);
	//void ResetPoints();

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

	/*int getNumber();
	void setNumber(int Number);

	int getGoals();
	void setGoals(int PlayerGoals);*/

	int getTotalGoals();
	void setTotalGoals(int PlayerGoals);
	void updateTotalGoals();

	/*int getAssists();
	void setAssists(int PlayerAssists);*/

	int getTotalAssists();
	void updateTotalAssists();
	void setTotalAssists(int PlayerAssists);

	/*bool getCurrentCleanSheet();
	void setCurrentCleanSheet(bool Cleansheet);*/

	/*int getTotalCleanSheets();
	void updateTotalCleanSheets();
	void setTotalCleanSheets(int CleanSheet);*/

	/*int getYellowCards();
	void setYellowCards(int YellowCards);*/

	int getTotalYellowCards();
	void updateTotalYellowCards();
	void setTotalYellowCards(int YellowCards);

	/*int getRedCards();
	void setRedCards(int RedCards);*/

	int getTotalRedCards();
	void updateTotalRedCards();
	void setTotalRedCards(int RedCards);

	int getID();
	void setID(int id);
	
	/*int getSaves();
	void setSaves(int save);*/
	
	vector<gameWeek> getPlayer_History();
	void updatePlayer_History(gameWeek hist);
	
	/*int getTotalSaves();
	void setTotalSaves(int totalsave);
	void updateTotalSaves();*/
};
	