#pragma once

#include "Player.h"
#include "Club.h"

#include <map>

class User_Team
{
private:
	int userTeam_ID=NULL;
	unordered_map<string, unordered_map<int, Player*>> Squad;//position, player id,player object
	int totalPlayers; //total number of players picked
	int totalAttackers; //total number of attackers picked
	int totalDefenders;//total number of defenders picked
	int totalMidfielders;//total number of midfielders picked
	bool isGoalKeeper; //was GoalKeeper picked
	int totalBudget;
	int currPoints=0;
	map<string, int> teamCount; // this is a map to count number of player picked in each team ex: "Chelsea", 2
	//vector<int> totalPointsPerWeek; // vector containing total points collected each week 
	unordered_map<int , pair<vector<pair<string, int>> , int >> squadPerweek; // {#gameweek, {{{"GKP",player_id},{"MID",player_id},{"ATK",player_id}},100 point}
	///			gameweek,{squad,squadpoints}
	///                squad:{{FWD,10},{DEF,50}}   
	int Transfers_left;
	
public:
	User_Team();
	void setUserTeamID(int);
	int  getUserTeamID();
	User_Team(int id);
	static const int MAX_PLAYERS = 11;
	static const int MAX_BUDGET = 1000; //1 billion
	static const int MAX_GOALKEEPERS = 1;
	static const int MAX_DEFENDERS = 5;
	static const int MAX_MIDFIELDERS = 5;
	static const int MAX_ATTACKERS = 4;
	bool Player_Exist(int);
	void pickSquad();
	void pickPlayer(Player*p);
	void RemovePlayer(Player*p);
	bool canAddPlayerPosition(string pos); //validation for position
	bool canAddPlayerPrice(Player*p); //validation for price
	bool canAddPlayerCount(Player* p); //validation for teamCount
	int getTotalPlayers();
	void setTotalPlayers(int);
	int calculateSquadPoints();

	// Getter and setter for totalAttackers
	int getTotalAttackers();
	void setTotalAttackers(int attackers);

	// Getter and setter for totalDefenders
	int getTotalDefenders();
	void setTotalDefenders(int defenders);

	// Getter and setter for totalMidfielders
	int getTotalMidfielders();
	void setTotalMidfielders(int midfielders);

	// Getter and setter for isGoalKeeper
	bool getIsGoalKeeper();
	void setIsGoalKeeper(bool is_goalkeeper);

	// Getter and setter for totalBudget
	int getTotalBudget();
	void setTotalBudget(int budget);

	

	int getTotalPointsPerWeek(int week);
	unordered_map<int, pair<vector<pair<string, int>>, int>> getSquadPerWeek();
	void setTotalPointsPerWeek(unordered_map<int, pair<vector<pair<string, int>>, int >>);
	void updateTotalPointsPerWeek(int);


	map<string, int> getTeamCount();
	void setTeamCount(map<string, int>);
	void displaySquadPrice();
	int getTransfers();
	void setTransfers(int t);
	void increaseTransfers();
	void decreaseTransfers();
	void PunishTransfers();
	unordered_map<string, unordered_map<int, Player*>> getCurrentSquad();
	void setSquad(unordered_map<string, unordered_map<int, Player*>> s);
	
	vector < pair<string, int>> getWeekSquad(int);
	
	void displaySquad(int);
	void displaySquad();
	



	void StartNewGameWeek();
	
	int displayGameweeks();

};

