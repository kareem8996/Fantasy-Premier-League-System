#pragma once
#include <string>
#include <vector>
#include "User_Team.h"
using namespace std;
class User {
private:
    string name;
    string username;
    string password;
    string email;
    string phoneNumber;
    string birthdate;
    int totalPoints;
    int currPoints;
    string teamName;
    vector<int> leagues;
    int Sqaud_ID;

public:
    // Constructor
    User();
    User(string& name,
        string& email,
        string& username,
        string& password,
        string& phoneNumber,

        int totalPoints,
        int currPoints,
        string& teamName,
        vector<int>& leagues);

    // Setters
    void setName(string& name);
    void setEmail(string& email);
    void setUsername(string& username);
    void setPassword(string& password);
    void setPhoneNumber(string& phoneNumber);
    void setBirthdate(string& birthdate);
    void setTotalPoints(int totalPoints);
    void setCurrPoints(int currPoints);
    void setTeamName(string& teamName);
    void setLeagues(vector<int>& leagues);
    void setSquad(User_Team squad);
    
    // Getters
    string& getName();
    string& getEmail();
    string& getUsername();
    string& getPassword();
    string& getPhoneNumber();
    string& getBirthdate();
    int getTotalPoints();
    int getCurrPoints();
    string& getTeamName();
    vector<int>& getLeagues();
    int& getSquad();
    // Menus

};