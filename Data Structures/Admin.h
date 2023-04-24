#pragma once
#include <iostream>
#include <string>
using namespace std;

class Admin {
private:
	
	string phoneNumber, name, password, email, userName;
public:

	Admin(string& name,
		string& email,
		string& userName,
		string& password,
		string& phoneNumber);
	Admin();
	//===================== Update Admin Data=========================



	
	void setName(string name);
	void setEmail(string email);
	void setUsername(string username);
	bool setPhoneNumber(string phone_number);
	void setPassword(string password);

	
	string getName();
	string getEmail();
	string getUsername();
	string getPassword();
	string getPhoneNumber();


	//===================== Update Player Data=========================
	void edit_player_menu();

	//===================== Update Team Data=========================
	void edit_team_menu();

	//===================== Update User Account Data=========================
	void edit_account();
	//===================== Update League Data=========================
	void edit_leagues();



};