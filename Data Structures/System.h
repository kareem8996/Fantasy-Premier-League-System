#pragma once
#include "User.h"
#include "Admin.h"
#include <string>
#include <vector>
using namespace std;
class System {
private:
	string const choice_error = "\tPlease enter your choice here --->\t";
	vector<string> const domains = { "gmail.com","outlook.com","yahoo.com","hotmail.com","icloud.com","cis.asu.edu.eg" };

public:
	System();

	string startchoice = "",
		registerChoice = "",
		loginChoice = "",
		menuChoice = "";
	User CurrUser;
	Admin CurrAdmin;
	vector<User> Allusers;
	vector<Admin> AllAdmins;
	//============= System Run ===========
	void RunSys();
	//============= Menus ================
	void Start_menu();
	void RegisterMenu();
	void loginInput();
	void printUserMenu();
	//============= System functions ==========
	void printSeprator();
	void printSeprator_for_errors();
	void InputFaliure(string& choice, string message);
	bool Check_Name(string& name);
	bool Check_Phone(string& Phone);
	bool Check_Username(string& Username);
	bool Check_Password(string& Password);
	bool Check_Email(string& Email);
	bool Check_EmailDatabase(string Email);
	void Pass_Encode(string& pass);
	//============= Registeration functions ================
	void RegisterUser();
	void RegisterAdmin();
	bool Check_Database(string username);
	bool Check_PhoneDatabase(string phone);
	//============= login functions====================
	bool userLogin(vector<User>allusers, string attemptedUsername, string attemptedPassword);
	bool AdminLogin(vector<Admin>AllAdmins, string attemptedUsername, string attemptedPassword);
};