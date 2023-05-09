#pragma once
#include <string>
#include <vector>
#include "User_Team.h"
using namespace std;
class User {
private:
    int id;
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

public:
    // Constructor
    User();
    User(int id,
        string name,
        string email,
        string username,
        string password,
        string phoneNumber,

        int totalPoints,
        int currPoints,
        string teamName,
        vector<int> leagues = {});

    // Setters

    void setName(string name);
    void setEmail(string email);
    void setUsername(string username);
    void setPassword(string password);
    void setPhoneNumber(string phoneNumber);
    void setBirthdate(string birthdate);
    void setTotalPoints(int totalPoints);
    void setCurrPoints(int currPoints);
    void setTeamName(string teamName);
    void setLeagues(vector<int>& leagues);
    void setSquad(User_Team squad);
    
    // Getters
    string getName();
    string getEmail();
    string getUsername();
    string getPassword();
    string getPhoneNumber();
    string getBirthdate();
    int getTotalPoints();
    int getCurrPoints();
    string getTeamName();
    vector<int> getLeagues();
    // Menus
    void  displaydata();

    void setID(int id);

    int getID();


};
