#include "League.h"
using namespace std;

League::League()
{
}

League::League(int id, string name, User* u, bool IsPublic,int code)
{
	this->id = id;
	this->name = name;
	this->code = code;
	this->league_creator = u;
	this->isPublic = IsPublic;
	this->leaderBoard.push({ 0, { u->getID(),u}});
}

void League::setname(string n)
{
	name = n;
}

string League::getName()
{
    return name;
};

int League::getId()
{
    return id;
};

int League::getcode()
{
    return code;
};

bool League::IsPublic()
{
    return isPublic;
};

void League::displayLeaderboard()
{
	const pair<int, pair<int, User*>>* p;
	p = &leaderBoard.top();

	cout << "Position\tManager\tPoints";
	for (int i = 0; i < leaderBoard.size(); i++) {
		cout <<i+1<<"\t" << (p + i)->second.second->getName() <<"\t"<< (p + i)->first<<endl;
	}

}

void League::displayUser(int userchoice)
{
	const pair<int, pair<int, User*>>* p;
	p = &leaderBoard.top();
	(p + userchoice)->second.second->displaydata();
}

void League::removeUser(int id)
{
	//O(logn)
	priority_queue<pair<int, pair<int, User*>>> newLeaderBoard;
	const pair<int, pair<int, User*>>* p;

	while (!leaderBoard.empty()) {
		p = &leaderBoard.top();
		if (p->second.second->getID() != id) {
			newLeaderBoard.push(*p);
		}
		leaderBoard.pop();
	}
	leaderBoard = newLeaderBoard;
}

int League::generateCode() {
    srand(time(NULL));
    int num1 = rand() % 10;
    int num2 = rand() % 10;
    int num3 = rand() % 10;
    int num4 = rand() % 10;

   return num1 * 1000 + num2 * 100 + num3 * 10 + num4;
}

void League::insertUser(User* u) {
	this->leaderBoard.push({ 0, { u->getID(),u} });
}

bool League::userExists(User* u) {

	const pair<int, pair<int, User*>>* p = &leaderBoard.top();

	for (int i = 0; i < leaderBoard.size(); i++) {
		
		if ((p + i)->second.second->getID() == u->getID())
			return true;
	}
	return false;
}

int League::getLeagueCreatorID()
{
	return league_creator->getID();
}


