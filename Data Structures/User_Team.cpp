#include "User_Team.h"
#include "System.h"
User_Team::User_Team()
{
}
void User_Team::setUserTeamID(int id)
{
	userTeam_ID = id;
}
int User_Team::getUserTeamID()
{
	return userTeam_ID;
}
User_Team::User_Team(int id) {
	userTeam_ID = id;
	totalPlayers = 0;
	totalAttackers = 0;
	totalDefenders = 0;
	totalMidfielders = 0;
	isGoalKeeper = false;
	totalBudget = MAX_BUDGET;
}
bool User_Team::canAddPlayerPosition(string pos) {
	if (pos == "GKP" && !isGoalKeeper) {
		return true;
	}
	else if(pos == "DEF" && totalDefenders!=MAX_DEFENDERS){
		return true;
	}
	else if (pos == "MID" && totalMidfielders != MAX_MIDFIELDERS) {
		return true;
	}
	else if (pos == "FWD" && totalAttackers != MAX_ATTACKERS) {
		return true;
	}
	return false;
}

bool User_Team::canAddPlayerPrice(Player*p) {
	return 0 <= (totalBudget - p->getPrice()); 
}

bool User_Team::canAddPlayerCount(Player*p) {
	return teamCount[p->getClub()] !=3;
}

bool User_Team::Player_Exist(int id) {
	for (auto& t : Squad) {
		if (t.second.find(id) != t.second.end())
			return true;
	}
	return false;
}
void User_Team::pickSquad() {
	/// <summary>
	/// This is the main menu for picking squad
	/// </summary>
	int current_totalPlayers = totalPlayers;
	string position_picked;
	System sys;
	while(totalPlayers!=MAX_PLAYERS) {
		cout << "\nPick a Position\n1.Goalkeeper\n2.Defender\n3.Midfielder\n4.Attacker\n5.Quit\n";
		cin >> position_picked;
		
		if (position_picked == "1") {

			if (canAddPlayerPosition("GKP")) {

				System::displayPlayers("GKP");
				cout << "Current Budget available: " << (float)totalBudget / 10 << endl;
				int id;
				cout << "Enter the player ID\n";
				cin >> id;
				if (!Player_Exist(id)) {

					System::displayPlayers(System::AllPlayers["GKP"][id], false, "\n");
					string Player_Option;
					cout << "Are you sure you want to pick " << System::AllPlayers["GKP"][id]->getFullname() << " ?\n";
					cin >> Player_Option;

					if (Player_Option == "Y" || Player_Option == "y") {

						if (canAddPlayerPrice(sys.AllPlayers["GKP"][id])) {

							if (canAddPlayerCount(sys.AllPlayers["GKP"][id])) {

								pickPlayer(sys.AllPlayers["GKP"][id]);
								continue;
							}
							else {
								cout << "Players limit from the same team exceeded\n";
							}
						}
						else {
							cout << "Player Price exceeds budget\n";
						}
					}
				}
				else {
					cout << "You already chose this player\n";
				}
			}
			else {
				cout << "You have reached the maximum number of GoalKeepers to choose from\n";
			}

		}
		else if (position_picked == "2") {
			if (canAddPlayerPosition("DEF")) {


				System::displayPlayers("DEF");
				cout << "Current Budget available: " << (float)totalBudget / 10 << endl;
				int id;
				cout << "Enter the player ID\n";
				cin >> id;
				if (!Player_Exist(id)) {

					System::displayPlayers(System::AllPlayers["DEF"][id], false, "\n");
					string Player_Option;
					cout << "Are you sure you want to pick " << System::AllPlayers["DEF"][id]->getFullname() << " ?\n";
					cin >> Player_Option;

					if (Player_Option == "Y" || Player_Option == "y") {

						if (canAddPlayerPrice(sys.AllPlayers["DEF"][id])) {

							if (canAddPlayerCount(sys.AllPlayers["DEF"][id])) {

								pickPlayer(sys.AllPlayers["DEF"][id]);
								continue;
							}
							else {
								cout << "Players limit from the same team exceeded\n";
							}
						}
						else {
							cout << "Player Price exceeds budget\n";
						}
					}
				}
				else {
					cout << "You already chose this player\n";
				}
			}
			else {
				cout << "You have reached the maximum number of Defenders to choose from\n";
			}
		}
		else if (position_picked == "3") {

			if (canAddPlayerPosition("MID")) {

				System::displayPlayers("MID");
				cout << "Current Budget available: " << (float)totalBudget / 10 << endl;
				int id;
				cout << "Enter the player ID\n";
				cin >> id;

				if (!Player_Exist(id)) {

					System::displayPlayers(System::AllPlayers["MID"][id], false, "\n");
					string Player_Option;
					cout << "Are you sure you want to pick " << System::AllPlayers["MID"][id]->getFullname() << " ?\n";
					cin >> Player_Option;

					if (Player_Option == "Y" || Player_Option == "y") {

						if (canAddPlayerPrice(sys.AllPlayers["MID"][id])) {

							if (canAddPlayerCount(sys.AllPlayers["MID"][id])) {

								pickPlayer(sys.AllPlayers["MID"][id]);
								continue;
							}
							else {
								cout << "Players limit from the same team exceeded\n";
							}
						}
						else {
							cout << "Player Price exceeds budget\n";
						}
					}
				}
				else {
					cout << "You already chose this player\n";
				}
			}
			else {
				cout << "You have reached the maximum number of Midfielders to choose from\n";
			}
		}
		else if (position_picked == "4") {

			if (canAddPlayerPosition("FWD")) {

				System::displayPlayers("FWD");
				cout << "Current Budget available: " << (float)totalBudget / 10 << endl;
				int id;
				cout << "Enter the player ID\n";
				cin >> id;
				if (!Player_Exist(id)) {

					System::displayPlayers(System::AllPlayers["FWD"][id], false, "\n");
					string Player_Option;
					cout << "Are you sure you want to pick " << System::AllPlayers["FWD"][id]->getFullname() << " ?\n";
					cin >> Player_Option;

					if (Player_Option == "Y" || Player_Option == "y") {

						if (canAddPlayerPrice(sys.AllPlayers["FWD"][id])) {

							if (canAddPlayerCount(sys.AllPlayers["FWD"][id])) {

								pickPlayer(sys.AllPlayers["FWD"][id]);
								continue;
							}
							else {
								cout << "Players limit from the same team exceeded\n";
							}
						}
						else {
							cout << "Player Price exceeds budget\n";
						}
					}
				}
				else {
					cout << "You already chose this player\n";
				}
			}
			else {
				cout << "You have reached the maximum number of Attackers to choose from\n";
			}
		}
		else if(position_picked=="5") {
			break;
		}
	}
}

void User_Team::pickPlayer(Player*p) {
	/// <summary>
	/// this function updates all User_Team variables
	/// </summary>
	/// <param name="p">Player object</param>
	totalBudget -= p->getPrice();

	teamCount[p->getClub()]++;

	if (p->getPosition() == "GKP") {
		isGoalKeeper = true;
	}
	else if (p->getPosition() == "DEF") {
		totalDefenders++;
	}
	else if (p->getPosition() == "MID") {
		totalMidfielders++;
	}
	else if (p->getPosition() == "FWD") {
		totalAttackers++;
	}
	totalPlayers++;
	Squad[p->getPosition()].insert({p->getID(),p});
}
void User_Team::RemovePlayer(Player*p) {
	/// <summary>
	/// this function removes player from squad and updates User_Team variables
	/// </summary>
	/// <param name="p">Player object</param>
	totalBudget += p->getPrice();

	teamCount[p->getClub()]--;

	if (p->getPosition() == "GKP") {
		isGoalKeeper = false;
	}
	else if (p->getPosition() == "DEF") {
		totalDefenders--;
	}
	else if (p->getPosition() == "MID") {
		totalMidfielders--;
	}
	else if (p->getPosition() == "FWD") {
		totalAttackers--;
	}
	totalPlayers--;
	Squad[p->getPosition()].erase(p->getID());
}



int User_Team::getTotalPlayers()
{
	return totalPlayers;
}

int User_Team::calculateSquadPoints()
{
	int total_points=0;
	for (auto v : this->Squad)
	{
		for (auto t : v.second)
		total_points += t.second->CalculatePoints();
	}
	return total_points;
}

void User_Team::setTotalPlayers(int players) {
	totalPlayers = players;
}

// Getter and setter for totalAttackers
int User_Team::getTotalAttackers() {
	return totalAttackers;
}

void User_Team::setTotalAttackers(int attackers) {
	totalAttackers = attackers;
}

// Getter and setter for totalDefenders
int User_Team::getTotalDefenders() {
	return totalDefenders;
}

void User_Team::setTotalDefenders(int defenders) {
	totalDefenders = defenders;
}

// Getter and setter for totalMidfielders
int User_Team::getTotalMidfielders() {
	return totalMidfielders;
}

void User_Team::setTotalMidfielders(int midfielders) {
	totalMidfielders = midfielders;
}

// Getter and setter for isGoalKeeper
bool User_Team::getIsGoalKeeper() {
	return isGoalKeeper;
}

void User_Team::setIsGoalKeeper(bool is_goalkeeper) {
	isGoalKeeper = is_goalkeeper;
}

// Getter and setter for totalBudget
int User_Team::getTotalBudget() {
	return totalBudget;
}

void User_Team::setTotalBudget(int budget) {
	totalBudget = budget;
}


vector<int> User_Team::getTotalPointsPerWeek() {
	return totalPointsPerWeek;
}
void User_Team::setTotalPointsPerWeek(vector<int> t) {
	totalPointsPerWeek = t;
}
void User_Team::updateTotalPointsPerWeek(int points) {
	totalPointsPerWeek.push_back(points);
}

map<string, int> User_Team::getTeamCount()
{
	return teamCount;
}

void User_Team::setTeamCount(map<string, int>teams)
{
	teamCount = teams;
}

void User_Team::displaySquad()
{
	int points = totalPointsPerWeek.back();

	cout << "Total Points: " << points << endl<<endl;
	for (auto& t : Squad) {
		cout << "----- " << t.first << " ------" << endl;

		for (auto& p : t.second) {
			cout << p.second->getFullname() << "\t" << p.second->getPlayer_History().back().getTotal_points_gameweek()<<" Points\n";
		}
	}
}
