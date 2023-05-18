#include "Admin.h"
#include "System.h"
#include "Player.h"
#include "Defender.h"
#include "Attacker.h"
#include "Midfielder.h"
#include "GoalKeeper.h"

using namespace std;

Admin::Admin(int id,string name, string email, string Adminname, string password, string phoneNumber) {
	this->id = id;
	this-> name = name;
	this->phoneNumber = phoneNumber;
	this->email = email;
	this->userName = Adminname;
	this-> password = password;

}
Admin::Admin() {}

bool Admin::setPhoneNumber(string phone_number) {
	bool vPhone;

	vPhone = System::Check_Phone(phone_number);
	if (vPhone) {
		phoneNumber = phone_number;
		cout << "Your Phone number changed Successfully";
		return true;
	}

	else {
		cout << "Couldn't change your pohne number";
		return false;
	}
}

string Admin::getPhoneNumber() {
	return phoneNumber;
}
void Admin::setID(int id)
{
	this->id = id;
}
int Admin::getID()
{
	return id;
}
void Admin::setName(string name) {
	bool VName;

	VName = System::Check_Name(name);
	if (VName) {
		cout << "Your Name changed Successfully";
		this->name = name;
	}

	else {
		cout << "Couldn't change Name";

	}
}
void Admin::setEmail(string email)
{
	bool vEmail;

	vEmail = System::Check_Email(email);
	if (vEmail) {
		this->email = email;
		cout << "Your Email changed Successfully";

	}

	else {
		cout << "Couldn't change your Email";

	}

}
void Admin::setUsername(string username)
{
	bool vUserName;

	vUserName = System::Check_Username(username);
	if (vUserName) {
		this->userName = username;
		cout << "Your Username changed Successfully";

	}

	else {
		cout << "Couldn't change your username";

	}

}
string Admin::getName() {
	return name;
}
string Admin::getEmail()
{
	return email;
}
void Admin::setPassword(string pass, string conpass) {
	if (pass == conpass) {
		if (pass == getUsername())
			cout << "Sorry password can not be as the username";
		else if (pass == getPassword())
			cout << "Sorry this is your old password";
		else
			password = pass;

	}
	else {
		cout << "Sorry password does not match";

	}
}

void Admin::setPassword(string pass)
{
	password = pass;
}

string Admin::getUsername()
{
	return userName;
}

string Admin::getPassword() {
	return password;
}



//===================== Update Player Data=========================
void edit_player_options(string pos) {
		cout << "\t\tWhat would you like to do ??\n"
			<< "\t\t1  - Minutes Played\n"
			<< "\t\t2  - Change Goals\n"
			<< "\t\t3  - Change Assists\n"
			<< "\t\t4  - change price\n"
			<< "\t\t5  - change status \n"// cheack a d i n s u
			<< "\t\t6  - Change YellowCards\n"
			<< "\t\t7  - Change RedCards\n"
			<< "\t\t8  - Change Own Goals\n"
			<< "\t\t9  - Change Bonus\n"
			<< "\t\t10 - Change Penalties Missed\n";
		if(pos!="FWD"){
			cout << "\t\t11 - Change Cleansheets\n";
			if(pos=="DEF"||pos=="GKP"){
			cout<< "\t\t12 - Change Goals Conceded\n";
			if(pos=="GKP"){
			cout<< "\t\t13 - Change Saves\n";
			cout<< "\t\t14 - Change Penalties Saved\n";
			}
		}
		}




}
void option_choise(int option,Player *&p) {
	string changed;

	int x = -1;
	switch (option) {
	case 1:
	validating:
		cout << "Enter Minutes Played: ";
		cin >> changed;
		if (System::isNumber(changed)) {
			int Ichanged = stoi(changed);
			if (Ichanged > 0 || Ichanged <= 90)
			{

			}
			else{
			cout << "Invalid Number of Minutes\n";
			goto validating;
			}
		}
		else{
			cout << "Please enter a number\n";
			goto validating;
		}
		break;
	case 2:
	{

	break;
	}
	case 3:
	{	cout << "what is the new status";
	string stat;
	cin >> stat;// cheack a d i n s u
	while (stat != "a" || stat != "d" || stat != "i" || stat != "n" || stat != "s" || stat != "u")
	{
		cout << "enter valid status from 'a d i n s u' ";
		cin >> stat;
	}
	p->setStatus(stat);
	break;
	}
	///////////////////
	case 4:
	cout << "do you want to increase or decrease " << p->getFullname() << " price \n";
		cout << "\t\t1 - increase price \n" << "\t\t2 - decrease price \n";
		if (x == 1)
			p->increasePrice();
		else if (x==2)
			p->decreasePrice();
		break;
		///////////////////
	case 5:
		int goals;
		cout << "enter total goals";
		cin >> goals;
		p->setTotalGoals(goals);
		break;
		///////////////////
	case 6:
		int assits;
		cout << "enter total assits";
		cin >> assits;
		p->setTotalAssists(assits);
		break;
		///////////////////
	case 7:
		int yellow;
		cout << "enter total yellow cards";
		cin >> yellow;
		p->setTotalYellowCards(yellow);
		break;
		///////////////////
	case 8:
		int red;
		cout << "enter total red cards";
		cin >> red;
		p->setTotalRedCards(red);
		break;
		///////////////////
	default:
		cout << "enter valid number";
	}
}

//=============
void Admin::edit_player_menu()
{
	int option;
	string position_picked;
	cout << "Pick a Position\n1.Goalkeeper\n2.Defender\n3.Midfielder\n4.Attacker\n5.Back\n";
	cin >> position_picked;
	while (true) {
		cin >> position_picked;
		if (cin.fail())
			System::InputFaliure(position_picked, "write a suitable number ");
		if (System::isNumber(position_picked)) {
			if (stoi(position_picked) < 6) {
				if (stoi(position_picked) == 1) position_picked = "GKP";
				else if (stoi(position_picked) == 2) position_picked = "DEF";
				else if (stoi(position_picked) == 3) position_picked = "MID";
				else if (stoi(position_picked) == 4) position_picked = "FWD";
				else return;
				break;
			}
			else {
				cout << "Invalid Choice\n Please choose again\n";
			}

		}
		else {
			cout << "Invalid Choice\n Please choose again\n";
		}
	}


	System::displayPlayers(position_picked);
	string id;
	cout << "Enter the player ID\n";
	while (true) {
		cin >> id;
		if (cin.fail())
			System::InputFaliure(id, "write a suitable number ");
		if (System::isNumber(id)) {
			if (System::AllPlayers[position_picked].find(stoi(id)) != System::AllPlayers[position_picked].end()) {
				break;
			}
			else {
				cout << "Player does not exist\n";
			}

		}
		else {
			cout << "Please write a code consisting of only numbers\n";
		}
	}
	System::displayPlayers(System::AllPlayers[position_picked][stoi(id)], false, "\n");
	// ASK what change i want make change in temp var
	string Player_Option;
	cout << "Are you sure you want to pick " << System::AllPlayers[position_picked][stoi(id)]->getFullname() << " ?\n";
	cin >> Player_Option;
	if (Player_Option == "Y" || Player_Option == "y") {
		//assign temp var to obj

		edit_player_options(position_picked);
		cin >> option;
		//switch
		option_choise(option, System::AllPlayers[position_picked][stoi(id)]);
		//	System::AllPlayers["GKP"][id];
	}
	else{
		edit_player_menu();
	}
}


//===================== Update Team Data=========================
void edit_club_options() {
	cout << "\t\tWhat would you like to do ??\n"
		<< "\t\t1 - remove palyer from club  \n"
		<< "\t\t2 - add palyer to club \n";

		
}


void Admin::edit_team_menu() {
	int option;
	int id;
	string PlayerName;
	string PlayerTeam;
	int PlayerTotalPoints;
	int PlayerPrice;
	string PlayerPosition;
	string PlayerStatus;
	int TotalCleanSheets;
	int TotalSaves;
	string PlayerPositionoption=NULL;
	cout << "\t\tWhat would you like to do ??\n"
		<< "\t\t1 - add palyer to club \n"
		<< "\t\t2 - remove palyer from club \n";
	cin >> option;
	do
	{
		cin >> option;

	} while (option != 1 || option != 1);
	switch (option) {
		
	case 1: {
		cout << "enter players id";
		cin >> id;
		cout << "enter players name";
		cin >> PlayerName;
		cout << "enter players total points";
		cin >> PlayerTotalPoints;
		cout << "enter players price";
		cin >> PlayerPrice;
		cout << "Pick a Position\n1.Goalkeeper\n2.Defender\n3.Midfielder\n4.Attacker\n";
		cin >> PlayerPositionoption;
		cout << "enter players status";
		cin >> PlayerStatus;
		cout << "enter players Total Clean Sheets";
		cin >> TotalCleanSheets;





	validate:
		switch (PlayerPositionoption[0])//add the temp to the file
		{
		case '1': {
			cout << "enter goalkeeper's total saves";
			cin >> TotalSaves;
			GoalKeeper golytemp(id, PlayerName, PlayerTeam, PlayerTotalPoints, PlayerPosition, PlayerStatus, TotalSaves, TotalCleanSheets);
			break; }
		case '2': {
			Defender deftemp(id, PlayerName, PlayerTeam, PlayerTotalPoints, PlayerPosition, PlayerStatus, TotalCleanSheets);
			break;
		}
		case '3': {

			Midfielder midtemp(id, PlayerName, PlayerTeam, PlayerTotalPoints, PlayerPosition, PlayerStatus, TotalCleanSheets);
			break;
		}
		case '4': {

			Attacker atktemp(id, PlayerName, PlayerTeam, PlayerTotalPoints, PlayerPosition, PlayerStatus);
			break;
		}
		default:
			cout << "enter valid number";
			cin >> PlayerPositionoption;
			goto validate;
			break;
		}

		break;
	}
	


	case 2: {
		
		string club_name;



	DisplayClubs:

		System::displayClubs();

		cout << "enter club name";
		cin >> club_name ; 

		if (System::AllClubs.find(club_name) == System::AllClubs.end())
			goto DisplayClubs;

	Display_squad:

		System::AllClubs[club_name]->DisplaySquad();
		string player_id;

		cout << "Please enter Player ID (or -1 to go back)";
		cin >> player_id;

		unordered_map<int, Player*> squad = System::AllClubs[club_name]->getSquad();

		if (squad.find(stoi(player_id)) == squad.end())
			goto Display_squad;
		else if (player_id == "-1")
			break;
		System::AllClubs[club_name]->deletePlayer(stoi(player_id));
		
		break;



	}
	default:
		cout << "enter valid number";
	}

}
	//club
	



//===================== Update User Account Data=========================


	void Admin::edit_user() { 
		string user_name;
		User tmp;
		for (auto user : System::AllUsers) {
			cout << user.first << "\t" << user.second->getName()<<endl;
	}
		display_user:
		cout << "\nenter user id\n";
		cin >> user_name;

		if (System::AllUsers.find(stoi(user_name)) == System::AllUsers.end())
			goto display_user;


		tmp = *System::AllUsers[stoi(user_name)];
		System::ChangeAccountSettings(tmp);
	}
//===================== Update League Data=========================

void Admin::edit_leagues() {}

void Admin::displaydata()
{
	cout << "Name: " << getName() << endl;
	cout << "Email: " << getEmail() << endl;
	cout << "Username: " << getUsername() << endl;
	cout << "Phone Number: " << getPhoneNumber() << endl;

}

void Admin::startNewGameweek()
{
	System::CurrGameWeek++;
	for (auto& x : System::AllUsersTeams) {
		x.second->StartNewtTotalPointsPerWeek();
	}
	for (auto& x : System::AllPlayers) {
		for (auto& y :x.second) {
			y.second->updatePlayer_History();
		}

	}
		

}
