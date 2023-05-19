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
			<< "\t\t4  - Change Price\n"
			<< "\t\t5  - Change Status\n"// cheack a d i n s u
			<< "\t\t6  - Change Yellow Cards\n"
			<< "\t\t7  - Change Red Cards\n"
			<< "\t\t8  - Change Own Goals\n"
			<< "\t\t9  - Change Bonus\n"
			<< "\t\t10 - Change Penalties Missed\n";
		

				if(pos=="GKP"){
					cout<< "\t\t11 - Change Saves\n";
					cout<< "\t\t12 - Change Penalties Saved\n";
			}
		cout << "\t\t0 - Back\n";
}
void option_choise(int option,Player *&p) {
	string changed;

	int x = -1;
	switch (option) {
	case 1:
	Minutes:
		cout << "Enter Minutes Played: ";
		cin >> changed;
		if (System::isNumber(changed)) {
			int Ichanged = stoi(changed);
			if (Ichanged >=0 && Ichanged <= 90)
			{
				p->updateMinutes(Ichanged);
			}
			else{
			cout << "Invalid Number of Minutes\n";
			goto Minutes;
			}
		}
		else{
			cout << "Please enter a number\n";
			goto Minutes;
		}
		break;
	case 2:
	{
	Goals:
		cout << "Enter Amount of Goals: ";
		cin >> changed;
		if (System::isNumber(changed)) {
			p->updateGoalScoredGameweek(stoi(changed));
			p->updateTotalGoals();
		}
		else {
			cout << "Please enter a number\n";
			goto Goals;
		}
	break;
	}
	case 3:
	{
	Assists:
		cout << "Enter Amount of Assists: ";
		cin >> changed;
		if (System::isNumber(changed)) {
			p->updateAssistsGameweek(stoi(changed));
			p->updateTotalAssists();
		}
		else {
			cout << "Please enter a number\n";
			goto Assists;
		}
		
		
	break;
	}
	///////////////////
	case 4:
	Price:
	cout << "do you want to increase or decrease " << p->getFullname() << " price \n";
		cout << "\t\t1 - increase price \n" << "\t\t2 - decrease price \n";
		cin >> changed;
		if (System::isNumber(changed)) {
			if (x == 1)
				p->increasePrice();
			else if (x == 2)
				p->decreasePrice();
			else {
				cout << "Invalid Number\n";
				goto Price;
			}
		}
		else {
			cout << "Please write a number\n";
			goto Price;
		}
		break;
		///////////////////
	case 5:
		while (changed != "a" || changed != "d" || changed != "i" || changed != "n" || changed != "s" || changed != "u")
		{
		cout << "what is the new status 'a d i n s u'";
			cin >> changed;
		}
		p->updateStatusGameweek(changed);
		break;
		///////////////////
	case 6:
	YellowCards:
		cout << "Enter Amount of Yellow Cards\n";
		cin >> changed;
		cout << "Enter Amount of Assists: ";
		cin >> changed;
		if (System::isNumber(changed)) {
			if (stoi(changed) < 3) {
				p->updateYellowCardsGameweek(stoi(changed));
			}
			else {
				cout << "Yellow cards cannot be more than 2\n";
				goto YellowCards;
			}
		}
		else {
			cout << "Please enter a number\n";
			goto YellowCards;
		}
		break;
		///////////////////
	case 7:
	RedCard:
		cout << "Did player receive Red card (Y/N): ";
		cin >> changed;
		if (changed == "y" || changed == "Y") {
			p->updateRedCardGameweek();
			p->updateTotalRedCards();
		}
		else if (changed != "n" || changed != "N") {
			cout << "Invalid Option\n";
			goto RedCard;
		}
		break;
		///////////////////
	case 8:
	OwnGoals:
		cout << "Enter Amount of Own Goals: ";
		cin >> changed;
		if (System::isNumber(changed)) {
			p->updateOwnGoals(stoi(changed));
		}
		else {
			cout << "Please enter a number\n";
			goto OwnGoals;
		}
		break;
	case 9:
	Bonus:
		cout << "Enter Bonus: ";
		cin >> changed;
		if (System::isNumber(changed)) {
			if(stoi(changed)<3 ||stoi(changed)>0)
			p->updateBonusGameweek(stoi(changed));
			else {
				cout << "Bonus is between 1 and 3 points\n";
				goto Bonus;
			}
		}
		else {
			cout << "Please enter a number\n";
			goto Bonus;
		}
		break;
	case 10:
	PenaltiesMissed:
		cout << "Enter Amount of Penalties Missed: ";
		cin >> changed;
		if (System::isNumber(changed)) {
			p->updatePenaltiesMissedGameweek(stoi(changed));
			
		}
		else {
			cout << "Please enter a number\n";
			goto PenaltiesMissed;
		}
		break;
	case 11:
	Saves:
		cout << "Enter Amount of Saves: ";
		cin >> changed;
		if (System::isNumber(changed)) {
			p->updateSavesGameweek(stoi(changed));
		}
		else {
			cout << "Please enter a number\n";
			goto Saves;
		}
		break;

	case 12:
	PenaltiesSaved:
		cout << "Enter Amount of Penalties Saved: ";
		cin >> changed;
		if (System::isNumber(changed)) {
			p->updatePenaltiesSaved(stoi(changed));
		}
		else {
			cout << "Please enter a number\n";
			goto PenaltiesSaved;
		}
		break;


		///////////////////
	default:
		cout << "enter valid number";
		option_choise(option, p);
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

	} while (option != 1);
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
			GoalKeeper golytemp(id, PlayerName, PlayerTeam, PlayerTotalPoints, PlayerPosition, TotalSaves, TotalCleanSheets);
			break; }
		case '2': {
			Defender deftemp(id, PlayerName, PlayerTeam, PlayerTotalPoints, PlayerPosition, TotalCleanSheets);
			break;
		}
		case '3': {

			Midfielder midtemp(id, PlayerName, PlayerTeam, PlayerTotalPoints, PlayerPosition, TotalCleanSheets);
			break;
		}
		case '4': {

			Attacker atktemp(id, PlayerName, PlayerTeam, PlayerTotalPoints, PlayerPosition);
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
		for (auto user : System::AllUsers) {
			cout << user.first << "\t" << user.second->getUsername()<<endl;
		}
		display_user:
		cout << "\nenter user id\n";
		cin >> user_name;

		if (System::AllUsers.find(stoi(user_name)) == System::AllUsers.end())
			goto display_user;


		
		System::ChangeAccountSettings(System::AllUsers[stoi(user_name)]);
}
//===================== Update League Data=========================

void Admin::edit_leagues() {

	string leagueID;
	string choice;
	string confirm;
	string userID;
	System::displayLeagues(true);
EnterLeagueID:
	cout << "\t\tChoose the League you want to edit or 0 to go back: ";
	cin >> leagueID;
	if (cin.fail())
		System::InputFaliure(leagueID, "\t\tEnter League you want to edit or 0 to go back");
	if(!System::isNumber(leagueID))
	{
		cout << "\t\tPlease Enter a League ID in numbers";
		goto EnterLeagueID;
	}
	if (leagueID == "0") return;
	if (System::AllLeagues.find(stoi(leagueID)) == System::AllLeagues.end()){
		cout << "\t\tPlease Enter a valid League\n";
		goto EnterLeagueID;
	}
	League* currentleague = System::AllLeagues[stoi(leagueID)];
	EnterEditChoice:
	cout << "\t\tWhat do you want to edit for this league(" << currentleague->getName() << ") ?\n";
	cout << "\t\t1- Change league Accessebility\n"
		<< "\t\t2 - Generate new code\n"
		<< "\t\t3 - Remove User from league\n"
		<< "\t\t0 - Back\n";
	
	
		cout << "Enter your Choice: ";
		cin >> choice;
		if (cin.fail())
			System::InputFaliure(choice, "\t\tEnter League you want to edit");
		if (!System::isNumber(choice)|| (stoi(choice)>3 && stoi(choice) < 0))
		{
			cout << "\t\tPlease Enter a valid choice";
			goto EnterEditChoice;
		}
	switch(choice[0]){
		case'1':
			cout << "This league is " << ((currentleague->IsPublic()==true) ? "Public":"Not Public");
			cout << "\nWould you like to change it?(Y/N)";
			cin >> confirm;
			if (confirm == "Y" || confirm == "y") {
				currentleague->togglePublic();
				break;
			}
			goto EnterEditChoice;
		case'2':
			cout << "This league code is " << currentleague->getcode();
			cout << "\nWould you like to change it?(Y/N)";
			cin >> confirm;
			if (confirm == "Y" || confirm == "y") {
				currentleague->setCode(League::generateCode());
				cout << "Now this league's code is " << currentleague->getcode() << endl;
				break;
			}
			goto EnterEditChoice;
		case'3':
			currentleague->displayUsers();
			cout << "Enter User id to remove?";
			EnterUserID:
			cin >> userID;
			if (cin.fail())
				System::InputFaliure(userID, "\t\tEnter League you want to edit");
			if (!System::isNumber(userID)&&!currentleague->userExists(stoi(userID)))
			{
				cout << "\t\tPlease Enter a valid user ID: ";
				goto EnterUserID;
			}
			cout << "Are you sure you want to remove this user?(Y/N)";
			cin >> confirm;
			if (confirm == "Y" || confirm == "y") {
				currentleague->removeUser(stoi(userID));
				break;	
			}
			goto EnterEditChoice;
		case '0':
			goto EnterLeagueID;
		default:
			break;


	}
	}

void Admin::displaydata(){
	cout << "Name: " << getName() << endl;
	cout << "Email: " << getEmail() << endl;
	cout << "Username: " << getUsername() << endl;
	cout << "Phone Number: " << getPhoneNumber() << endl;

}




void Admin::edit_fixture_menu()
{
	string again;
	bool goBack=false;
	DisplayFixtures:

		int fixtureID;
		fixtureID=System::ChooseFixture(goBack);
		if (goBack) return;

	DisplayFixtureClubs:

		string teamName = System::ChooseFixtureClub(fixtureID, goBack);
		if (goBack)
			goto DisplayFixtures;
SelectFixturePlayer:

		Player* p = System::ChooseFixturePlayer(teamName, goBack);
		if (goBack)
			goto DisplayFixtureClubs;

DisplayPlayerEditMenu:

		edit_player_options(p->getPosition());

Validating:
		string choice;
		cout << "Please enter option\n";
		cin >> choice;
		if (!System::isNumber(choice)) {
			cout << "Please enter a number\n";
			goto Validating;
		}

		if (stoi(choice) > 12 || (p->getPosition()!="GKP" && stoi(choice)>10)){
			cout << "Please enter a suitable number\n";
			goto Validating;
		}
		if (choice == "0")
			goto SelectFixturePlayer;
	option_choise(stoi(choice),p);
	cout << "Change Statistics for Same Player Again?";
	cin >> again;
	if (again == "y" || again == "Y") {
		goto DisplayPlayerEditMenu;
	}
	else {
		goto SelectFixturePlayer;
	}
}

void Admin::startNewGameweek() {
	for (auto& UserTeam : System::AllUsersTeams) {
		UserTeam.second->StartNewGameWeek();
	}
	for (auto& position : System::AllPlayers) {
		for (auto& player : position.second) {
			player.second->StartNewGameWeek();
		}

	}
	for (auto& user : System::AllUsers) {
		user.second->startNewGameweek();
	}

	for(auto&league:System::AllLeagues){
		league.second->UpdateLeaderBoard();
	}

	for (auto& fixture : System::AllFixtures[System::CurrGameWeek - 1]) {
		fixture.second->setFinished(true);
		fixture.second->updateWinnerPoints();

	}

	for (auto& fixture : System::AllFixtures[System::CurrGameWeek]) {
		fixture.second->setFinished(false);
	}
	System::CurrGameWeek++;

}
