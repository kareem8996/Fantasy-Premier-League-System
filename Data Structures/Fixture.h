#pragma once
#include <string>
using namespace std;
class Fixture
{
private:
	int id,homeScore,awayScore;
	int homeTeam,awayTeam;
public:
	void setId(int);
	int getId();

	void setHomescore(int);
	void setAwayscore(int);
	int getAwayscore();
	int getHomescore();
	void setHomeTeam(int);
	void setAwayTeam(int);
	int getAwayTeam();
	int getHomeTeam();
	
	


};

