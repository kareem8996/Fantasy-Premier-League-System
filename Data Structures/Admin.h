#pragma once
#include <iostream>
#include <string>
using namespace std;

class Admin {
private:
	int id;
	string phoneNumber, name, password, email, Adminname;
public:

	Admin(int id, string& name,
		string& email,
		string& Adminname,
		string& password,
		string& phoneNumber);
	Admin();
	//===================== Update Admin Data=========================



	void setId(int id);
	void setName(string name);
	void setEmail(string email);
	void setUsername(string username);
	bool setPhoneNumber(string phone_number);
	void setPassword(string password);

	int getId();
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