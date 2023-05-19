#pragma once
#include <string>
using namespace std;
class Fixture
{
private:
	int id,homeScore,awayScore;
	int homeTeam,awayTeam;
	bool finished;
	int team_h_difficulty, team_a_difficulty;
public:
	Fixture();
	Fixture(int,int,int,int,int,int,int,bool);
	void setId(int);
	int getId();

	void setHomescore(int);
	void setAwayscore(int);
	void updateHomescore(int);
	void updateAwayscore(int);
	int getAwayscore();
	int getHomescore();

	void setHomeTeam(int);
	void setAwayTeam(int);
	int getAwayTeam();
	int getHomeTeam();

	int getHomeTeamDif();
	int getAwayTeamDif();

	bool IsFinished();
	void setFinished(bool);
	void updateWinnerPoints();
};

