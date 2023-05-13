#include "user.h"

// Constructor
User::User() {}
User::User(int id,string name,string email,string username,string password,string phoneNumber,int totalPoints,int currPoints,string teamName,vector<int> leagues) {
    this->id = id;
    this->name = name;
    this->email = email;
    this->username = username;
    this->password = password;
    this->phoneNumber = phoneNumber;
    this->totalPoints = totalPoints;
    this->currPoints = currPoints;
    this->teamName = teamName;
    this->leagues = leagues;
}


// Setters
void User::setName(string name) {
    this->name = name;
}

void User::setEmail(string email) {
    this->email = email;
}

void User::setUsername(string username) {
    this->username = username;
}

void User::setPassword(string password) {
    this->password = password;
}

void User::setPhoneNumber(string phoneNumber) {
    this->phoneNumber = phoneNumber;
}

void User::setBirthdate(string birthdate) {
    this->birthdate = birthdate;
}

void User::setTotalPoints(int totalPoints) {
    this->totalPoints = totalPoints;
}

void User::setCurrPoints(int currPoints) {
    this->currPoints = currPoints;
}

void User::setTeamName(string teamName) {
    this->teamName = teamName;
}

void User::setLeagues(vector<int>& leagues) {
    this->leagues = leagues;
}


// Getters
string User::getName() {
    return name;
}

string User::getEmail() {
    return email;
}

string User::getUsername() {
    return username;
}

string User::getPassword() {
    return password;
}

string User::getPhoneNumber() {
    return phoneNumber;
}

string User::getBirthdate() {
    return birthdate;
}

int User::getTotalPoints() {
    return totalPoints;
}

int User::getCurrPoints() {
    return currPoints;
}

string User::getTeamName() {
    return teamName;
}
vector<int> User::getLeagues() {
    return leagues;

}


void User::displaydata()
{
    cout<<getName() << endl;
    cout<<getEmail()<<endl;
    cout<<getUsername()<<endl;
    cout<<getPhoneNumber()<<endl;
    cout<<getBirthdate()<<endl;
    cout<<getTotalPoints()<<endl;
    cout<<getCurrPoints()<<endl;
    cout<<getTeamName()<<endl;
}

void User::setID(int id) {
    this->id = id;
}

int User::getID() {
    return id;
}

void User::updateLeagues(int leagueID)
{
    this->leagues.push_back(leagueID);
}
