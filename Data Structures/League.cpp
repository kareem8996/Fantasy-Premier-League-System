
#include "League.h"
using namespace std;
League::League()
{
}
League::League(int id, string name, User* u, bool IsPublic)
{


	this->id = id;
	this->name = name;
	this->code = League::generateCode();
	this->league_creator = u;
	this->isPublic = IsPublic;
	this->leaderBoard.push({ 0, { u.id,u } });
}
void League::setname(string n)
{
	name = n;
}
string League::getName()
{
    return name;
};

int League::getId(int id)
{
    return id;
};

int League::getcode()
{
    return code;
};

bool League::IsPublic()
{
    return isPublic = false;
};
void League::displayLeaderboard()
{
	const pair<int, pair<int, User*>>* p;
	p = &leaderBoard.top();
	for (int i = 0; i < leaderBoard.size(); i++) {
		cout << (p + i)->second.second << endl;
	}
}
void League::displayUser(string userchoice)
{
	const pair<int, pair<int, User*>>* p;
	p = &leaderBoard.top();
	(p + stoi(userchoice))->second.second->displaydata();
}
void League::removeUser(string user)
{
	
}
int League::generateCode() {
    srand(time(NULL));
    int num1 = rand() % 10;
    int num2 = rand() % 10;
    int num3 = rand() % 10;
    int num4 = rand() % 10;

   return num1 * 1000 + num2 * 100 + num3 * 10 + num4;
}
