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
	Transfers_left = 0;
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
	return 0 <= (totalBudget - p->getPlayer_History().back().getValue());
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
	while (totalPlayers != MAX_PLAYERS) {
		cout << "\nPick a Position\n1.Goalkeeper\n2.Defender\n3.Midfielder\n4.Attacker\n5.Quit\n";
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
			if (canAddPlayerPosition(position_picked)) {

				System::displayPlayers(position_picked);
				cout << "Current Budget available: " << (float)totalBudget / 10 << endl;
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
				if (!Player_Exist(stoi(id))) {

					System::displayPlayers(System::AllPlayers[position_picked][stoi(id)], false, "\n");
					string Player_Option;
					cout << "Are you sure you want to pick " << System::AllPlayers[position_picked][stoi(id)]->getFullname() << " ?\n";
					cin >> Player_Option;

					if (Player_Option == "Y" || Player_Option == "y") {

						if (canAddPlayerPrice(System::AllPlayers[position_picked][stoi(id)])) {

							if (canAddPlayerCount(System::AllPlayers[position_picked][stoi(id)])) {

								pickPlayer(System::AllPlayers[position_picked][stoi(id)]);
								
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
				cout << "You have reached the maximum number of players from this position to choose from\n";
			}
		
	}
}
void User_Team::pickPlayer(Player*p) {
	/// <summary>
	/// this function updates all User_Team variables
	/// </summary>
	/// <param name="p">Player object</param>
	totalBudget -= p->getPlayer_History().back().getValue();

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
	totalBudget += p->getPlayer_History().back().getValue();

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


unordered_map<int, pair<vector<pair<string, int>>, int >> User_Team::getTotalPointsPerWeek() {
	/*vector<int> totalPointsPerWeek;
	for (auto weekPoints : squadPerweek) {
		totalPointsPerWeek.push_back(weekPoints.second.second);
	}*/
	return squadPerweek;
}
void User_Team::setTotalPointsPerWeek(unordered_map<int, pair<vector<pair<string, int>>, int >> squad_points_Hist) {
	squadPerweek = squad_points_Hist;
}
void User_Team::updateTotalPointsPerWeek(int points=0) {
	
	vector<pair<string, int>> emptySqaud;
	if (squadPerweek.empty())
		squadPerweek.insert({System::CurrGameWeek,make_pair(emptySqaud ,points)});
	else
		squadPerweek[System::CurrGameWeek].second = points;
}

void User_Team::StartNewtTotalPointsPerWeek() {
	vector<pair<string, int>> emptySqaud;
	squadPerweek.insert({ System::CurrGameWeek,make_pair(emptySqaud ,0) });
}

map<string, int> User_Team::getTeamCount()
{
	return teamCount;
}

void User_Team::setTeamCount(map<string, int>teams)
{
	teamCount = teams;
}

void User_Team::displaySquad() /// Last Gameweek squad
{
	int points;
	if (!squadPerweek.empty())
		points = squadPerweek[System::CurrGameWeek].second;
	else points = 0;

	cout << "Total Points: " << points << endl<<endl;
	for (auto& player : squadPerweek[System::CurrGameWeek].first) {
		cout << "----- " << player.first << " ------" << endl; /// postion

		//System::AllPlayers[player.first][player.second]

		if (points != 0)
		cout<< player.second<<" - "
			<< System::AllPlayers[player.first][player.second]->getFullname() << "\t" 
			<< System::AllPlayers[player.first][player.second]->getPlayer_History().back().getTotal_points_gameweek() 
			<< " Points\n";
		else {
			cout << player.second << " - " 
				<< System::AllPlayers[player.first][player.second]->getFullname() << "\t 0 Points\n";
		}
		
	}
}
void User_Team::displaySquadPrice()
{
	cout << "Remaining Budget: " << (float)totalBudget/10 << endl<<endl;

	for (auto& t : Squad) {
		cout << "----- " << t.first << " ------" << endl;
		for (auto& p : t.second) {
			cout << p.second->getID()<<" - "<< p.second->getFullname() << "\t" << (float)p.second->getPlayer_History().back().getValue() / 10 << " Price\n";
		}
	}
}

int User_Team::getTransfers() {
	return Transfers_left;
}

void User_Team::setTransfers(int t) {
	Transfers_left = t;	
}

void User_Team::increaseTransfers() {
	Transfers_left++;
}
void User_Team::decreaseTransfers() {
	Transfers_left--;
}

void User_Team::PunishTransfers()
{
	if (squadPerweek.empty()) updateTotalPointsPerWeek(-4);
	else squadPerweek[System::CurrGameWeek].second -= 4;
}

unordered_map<string, unordered_map<int, Player*>> User_Team::getCurrentSquad()
{
	return Squad;
}

void User_Team::setSquad(unordered_map<string, unordered_map<int, Player*>> s) {

	Squad = s;

}

vector<pair<string, int>> User_Team::getLastSquad()
{
	
		return squadPerweek[System::CurrGameWeek-1].first;
}

void User_Team::StartNewGameWeek()
{
	vector<pair<string, int>> squadIds;
	for (auto& player : Squad) {
		for (auto& x : player.second)
			squadIds.push_back({ player.first,x.first});

	}
	squadPerweek.insert({ System::CurrGameWeek,{squadIds,0} });
}
