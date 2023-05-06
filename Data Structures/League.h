#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "User.h"
#include <queue>
using namespace std;
class League
{
private:
    int id;
    string name;
    bool isPublic;
    int code =NULL;
    User* league_creator; // int user created legaue
    priority_queue<pair<int, pair<int, User*>>> leaderBoard; // score,userid,user object
public:
    League();
    League(int id, string name, User* u, bool IsPublic,int=generateCode());
    void setname(string n);
    string getName();
    int getId();
    int getcode();
    bool IsPublic();
    void displayLeaderboard();
    void displayUser(int userchoice);
    void removeUser(int id);
    int static generateCode();
    void insertUser(User*);

    bool userExists(User* u);

    int getLeagueCreatorID();
};

