#include "League.h"
#include "System.h"
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
}
void League::setId(int id)
{
	this->id = id;
}
void League::setIsPublic(bool is)
{
	isPublic = is;
}
void League::setCode(int code)
{
	this->code = code;
}
void League::setLeagueCreator(User*u)
{
	this->league_creator = u;
}
;

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
	UpdateLeaderBoard();
	const pair<int, pair<int, User*>>* p;
	p = &leaderBoard.top();

	for (int i = 0; i < leaderBoard.size(); i++) {
		cout << "Position #" << i + 1;
		cout <<"\nManager: " << (p + i)->second.second->getUsername();
		cout <<"\nPoints\n" << (p + i)->first;
		System::printSeprator_for_errors();
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
	if (id == league_creator->getID()){
		cout << "You can't remove League Creator";
		return;
	}
	
	//O(logn)
	priority_queue<pair<int, pair<int, User*>>> newLeaderBoard;
	const pair<int, pair<int, User*>>* p;

	while (!leaderBoard.empty()) {
		p = &leaderBoard.top();
		if (p->second.first != id) {
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

void League::insertUser(User*& u) {
	this->leaderBoard.push({ 0, { u->getID(),u} });
	u->updateLeagues(id);
}

void League::insertUser(int score, User*u)
{
	this->leaderBoard.push({ score, { u->getID(),u} });
}

bool League::userExists(int id) {

	const pair<int, pair<int, User*>>* p = &leaderBoard.top();

	for (int i = 0; i < leaderBoard.size(); i++) {
		
		if ((p + i)->second.first == id){
		
			return true;
		}
	}
	
	return false;
}

int League::getLeagueCreatorID()
{
	return league_creator->getID();
}

priority_queue<pair<int, pair<int, User*>>> League::getLeaderBoard()
{
	return leaderBoard;
}

void League::setLeaderBoard(priority_queue<pair<int, pair<int, User*>>> leaderboard)
{
	this->leaderBoard = leaderboard;
}

void League::UpdateLeaderBoard()
{
	priority_queue<pair<int, pair<int, User*>>> newleaderboard;
	const pair<int, pair<int, User*>>* p = &leaderBoard.top();

	for (int i = 0; i < leaderBoard.size(); i++) {
		newleaderboard.push({ (System::AllUsersTeams[(p + i)->second.first]->getTotalPointsPerWeek(System::CurrGameWeek - 1) + (p + i)->second.second->getTotalPoints()) , {(p + i)->second.first,(p + i)->second.second}});
	}
	this->leaderBoard = newleaderboard;
}
void League::togglePublic(){
	this->isPublic = !this->isPublic;
	if(!isPublic){
		code=generateCode();
		cout << "Now this league's code is " << code<<endl;
	}
}
void League::displayUsers(){
	const pair<int, pair<int, User*>>* p = &leaderBoard.top();
	for (int i = 0; i < leaderBoard.size(); i++) {

		cout << (p + i)->second.first <<" - " << (p + i)->second.second->getName();
	}
}


