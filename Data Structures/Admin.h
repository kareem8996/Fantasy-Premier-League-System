#pragma once
#include <iostream>
#include <string>
using namespace std;

class Admin {
private:
	
	string phoneNumber, name, password, email, userName;
	int id;
public:

	Admin(int id,
		string name,
		string email,
		string userName,
		string password,
		string phoneNumber);
	Admin();
	//===================== Update Admin Data=========================



	
	void setName(string name);
	void setEmail(string email);
	void setUsername(string username);
	bool setPhoneNumber(string phone_number);
	void setPassword(string pass, string conpass);
	void setPassword(string pass);
	
	string getName();
	string getEmail();
	string getUsername();
	string getPassword();
	string getPhoneNumber();

	void setID(int id);

	int getID();
	//===================== Update Player Data=========================
	void edit_player_menu();

	//===================== Update Team Data=========================
	void edit_team_menu();
	//======================Update Fixture Data=========================
	void edit_fixture_menu();

	//===================== Update User Account Data=========================
	void edit_user();
	//===================== Update League Data=========================
	void edit_leagues();

	void displaydata();
	//===================== ChangeGameweeks=========================
	void startNewGameweek();


};