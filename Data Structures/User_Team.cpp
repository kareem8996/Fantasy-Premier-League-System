#include "User_Team.h"
#include "System.h"
User_Team::User_Team() {
	totalPlayers = 0;
	totalAttackers = 0;
	totalDefenders = 0;
	totalMidfielders = 0;
	isGoalKeeper = 0;
	totalBudget = MAX_BUDGET;
}
bool User_Team::canAddPlayerPosition(string pos) {
	if (pos == "GoalKeeper" && !isGoalKeeper) {
		return true;
	}
	else if(pos == "Defender" && totalDefenders!=MAX_DEFENDERS){
		return true;
	}
	else if (pos == "Midfielder" && totalMidfielders != MAX_MIDFIELDERS) {
		return true;
	}
	else if (pos == "Attacker" && totalAttackers != MAX_ATTACKERS) {
		return true;
	}
}

bool User_Team::canAddPlayerPrice(Player p) {
	return 0 <= (totalBudget - p.getPrice()); 
}

bool User_Team::canAddPlayerCount(Player p) {
	return teamCount[p.getClub()] !=3;
}

void User_Team::pickSquad() {
	/// <summary>
	/// This is the main menu for picking squad
	/// </summary>
	int current_totalPlayers = totalPlayers;
	string position_picked;
	while(totalPlayers!=MAX_PLAYERS) {
		cout << "Pick a Position\n1.Goalkeeper\n2.Defender\n3.Midfielder\n4.Attacker\n5.Quit";
		cin >> position_picked;
		
		if (position_picked == "1") {
			if (canAddPlayerPosition("Goalkeeper")) {
				displayPlayers("Goalkeeper");
				int id;
				cout << "Enter the player ID\n";
				cin >> id;
				if (canAddPlayerPrice(System::AllPlayers["Goalkeeper"][id])) {
					if (canAddPlayerCount(System::AllPlayers["Goalkeeper"][id])) {
						pickPlayer(System::AllPlayers["Goalkeeper"][id]);
						continue;
					}
					else {
						cout<<"Players limit from the same team exceeded\n";
					}
				}
				else {
					cout << "Player Price exceeds budget\n";
				}
			}
			else {
				cout << "You have reached the maximum number of GoalKeepers to choose from\n";
			}
		}
		else if (position_picked == "2") {
			if (canAddPlayerPosition("Defender")) {
				displayPlayers("Defender");
				int id;
				cout << "Enter the player ID\n";
				cin >> id;
				if (canAddPlayerPrice(System::AllPlayers["Defender"][id])) {
					if (canAddPlayerCount(System::AllPlayers["Defender"][id])) {
						pickPlayer(System::AllPlayers["Defender"][id]);
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
			else {
				cout << "You have reached the maximum number of Defenders to choose from\n";
			}
		}
		else if (position_picked == "3") {
			if (canAddPlayerPosition("Midfielder")) {
				displayPlayers("Midfielder");
				int id;
				cout << "Enter the player ID\n";
				cin >> id;
				if (canAddPlayerPrice(System::AllPlayers["Midfielder"][id])) {
					if (canAddPlayerCount(System::AllPlayers["Midfielder"][id])) {
						pickPlayer(System::AllPlayers["Midfielder"][id]);
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
			else {
				cout << "You have reached the maximum number of Midfielders to choose from\n";
			}
		}
		else if (position_picked == "4") {
			if (canAddPlayerPosition("Attacker")) {
				displayPlayers("Attacker");
				int id;
				cout << "Enter the player ID\n";
				cin >> id;
				if (canAddPlayerPrice(System::AllPlayers["Attacker"][id])) {
					if (canAddPlayerCount(System::AllPlayers["Attacker"][id])) {
						pickPlayer(System::AllPlayers["Attacker"][id]);
						continue;
					}
					else {
						cout<<"Players limit from the same team exceeded\n";
					}
				}
				else {
					cout << "Player Price exceeds budget\n";
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

void User_Team::pickPlayer(Player p) {
	/// <summary>
	/// this function updates all User_Team variables
	/// </summary>
	/// <param name="p">Player object</param>
	totalBudget -= p.getPrice();

	teamCount[p.getClub()]++;

	if (p.getPosition() == "Goalkeeper") {
		isGoalKeeper = true;
	}
	else if (p.getPosition() == "Defender") {
		totalDefenders++;
	}
	else if (p.getPosition() == "Midfielder") {
		totalMidfielders++;
	}
	else if (p.getPosition() == "Attacker") {
		totalAttackers++;
	}
	totalPlayers++;
	Squad.insert({ p.getID(),p });
}
void User_Team::RemovePlayer(Player p) {
	/// <summary>
	/// this function removes player from squad and updates User_Team variables
	/// </summary>
	/// <param name="p">Player object</param>
	totalBudget += p.getPrice();

	teamCount[p.getClub()]--;

	if (p.getPosition() == "Goalkeeper") {
		isGoalKeeper = false;
	}
	else if (p.getPosition() == "Defender") {
		totalDefenders--;
	}
	else if (p.getPosition() == "Midfielder") {
		totalMidfielders--;
	}
	else if (p.getPosition() == "Attacker") {
		totalAttackers--;
	}
	totalPlayers--;
	Squad.erase(p.getNumber());
}

void User_Team::displayPlayers(Player p,bool flag=false,string delim="\n") {
	/// <summary>
	/// displays only one player
	/// </summary>
	/// <param name="p">player obkect</param>
	/// <param name="flag">This is used so we can use the same code twice</param>
	/// <param name="delim"> the delimiter can either be enter or tab</param>
	System::printSeprator_for_errors();
	cout << "ID: " << p.getID() << delim;
	cout << "Name: " << p.getFullname() << delim;
	cout << "Club: " << p.getClub() << delim;
	cout << "Price: " << p.getPrice() << delim;
	cout << "Current Week Points: " << p.getPoints() << delim;
	cout << "Total Points: " << p.getTotalPoints() << delim;
	if (!flag) {
	cout << "Name: " << p.getFullname() << delim;
	cout << "Position: " << p.getPosition() << delim;
	cout << "Status: " << p.getStatus() << delim;
	cout << "Tshirt Number: " << p.getNumber() << delim;
	cout << "Current Week Goals: " << p.getGoals() << delim;
	cout << "Total Goals: " << p.getTotalGoals() << delim;
	cout << "Current Week Assists: " << p.getAssists() << delim;
	cout << "Total Assists: " << p.getTotalAssists() << delim;
	cout << "Current Week Yellow Cards: " << p.getYellowCards() << delim;
	cout << "Total Yellow Cards: " << p.getTotalYellowCards() << delim;
	cout << "Current Week Red Card: " << p.getRedCards() << delim;
	cout << "Total Red Cards: " << p.getTotalRedCards()<<delim;

	if (p.getPosition() != "Attacker") {
		cout << "Current Week Cleensheet: " << p.getCurrentCleanSheet() << delim;
		cout << "Current Week Cleensheet: " << p.getTotalCleanSheets() << delim;
	}
	}
	System::printSeprator_for_errors();
}
void User_Team::displayPlayers(string position) {
	/// <summary>
	/// Displays all players who play in a certain position
	/// </summary>
	/// <param name="position"></param>
	for (auto& it : System::AllPlayers[position]) {
		displayPlayers(it.second, true,"\t||\t");
	}
}