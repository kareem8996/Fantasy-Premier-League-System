#pragma once
#include "User.h"
#include "Admin.h"
#include "Player.h"
#include "Club.h"
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class System {
private:
	static string const choice_error ;
	static vector<string> const domains;

public:
	

	static string startchoice ,
		registerChoice ,
		loginChoice ,
		menuChoice ;
	static User CurrUser;
	static Admin CurrAdmin;
	static vector<User> Allusers;
	static vector<Admin> AllAdmins;
	static unordered_map<string, Club> AllClubs; //name,club object
	static unordered_map < string, unordered_map<int, Player *>> AllPlayers;
	
	//============= System Run ===========
	static void RunSys();
	//============= Menus ================
	static void Start_menu();
	static void RegisterMenu();
	static void loginInput();
	static void printUserMenu();
	static void printAdminMenu();
	//============= System functions ==========
	static void printSeprator();
	static void printSeprator_for_errors();
	static void InputFaliure(string& choice, string message);
	static bool Check_Name(string& name);
	static bool Check_Phone(string& Phone);
	static bool Check_Username(string& Username);
	static bool Check_Password(string& Password);
	static bool Check_Email(string& Email);
	static bool Check_EmailDatabase(string Email);
	static void Pass_Encode(string& pass);
	//============= Registeration functions ================
	static void RegisterUser();
	static void RegisterAdmin();
	static bool Check_Database(string username);
	static bool Check_PhoneDatabase(string phone);
	//============= login functions====================
	static bool userLogin(vector<User>allusers, string attemptedUsername, string attemptedPassword);
	static bool AdminLogin(vector<Admin>AllAdmins, string attemptedUsername, string attemptedPassword);
	//================User Menus=======================
	static void ManageSqaudMenu(User_Team& c);


	// ======================Player Display=======================
	static void displayPlayers(string position);
	static void displayPlayers(Player *p, bool flag, string delim);

	//==================File Handling:Read========================
	static void readPlayers();
};