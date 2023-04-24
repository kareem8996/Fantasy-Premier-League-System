#pragma once
#include <iostream>

using namespace std;

class Player
{
private:
	int ID;
	string FullName;
	string Team;
	int Points;
	float Price;
	int TotalPoints;
	string Position;
	string Status;
	int Number;
	int Goals;
	int TotalGoals;
	int Assists;
	int TotalAssists;
	bool CurrentCleanSheet;
	int TotalCleanSheets;
	int YellowCards;
	int TotalYellowCards;
	int RedCards;
	int TotalRedCards;



public:
	Player();
	Player(string PlayerName, string PlayerTeam, int PlayerTotalPoints, float PlayerPrice, string PlayerPosition, string PlayerStatus, int PlayerNumber);
	string getFullname();
	void setFullname(string Fullname);

	string getClub();
	void setClub(string PlayerTeam);

	int getPoints();
	void setPoints(int PLayerPoints);
	void ResetPoints();

	float getPrice();
	void setPrice(float PlayerPrice);
	void increasePrice();
	void decreasePrice();

	int getTotalPoints();
	void setTotalPoints(int TPoints);
	void updateTotalPoints();

	string getPosition();
	void setPosition(string PlayerPosition);

	string getStatus();
	void setStatus(string PlayerStatus);

	int getNumber();
	void setNumber(int Number);

	int getGoals();
	void setGoals(int PlayerGoals);

	int getTotalGoals();
	void setTotalGoals(int PlayerGoals);
	void updateTotalGoals();

	int getAssists();
	void setAssists(int PlayerAssists);

	int getTotalAssists();
	void updateTotalAssists();
	void setTotalAssists(int PlayerAssists);

	bool getCurrentCleanSheet();
	void setCurrentCleanSheet(bool Cleansheet);

	int getTotalCleanSheets();
	void updateTotalCleanSheets();
	void setTotalCleanSheets(int CleanSheet);

	int getYellowCards();
	void setYellowCards(int YellowCards);

	int getTotalYellowCards();
	void updateTotalYellowCards();
	void setTotalYellowCards(int YellowCards);

	int getRedCards();
	void setRedCards(int RedCards);

	int getTotalRedCards();
	void updateTotalRedCards();
	void setTotalRedCards(int RedCards);

	int getID();
	void setID(int id);
};
	