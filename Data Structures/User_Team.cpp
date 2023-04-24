#include "User_Team.h"
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
	return MAX_BUDGET >= (totalPrice + p.getPrice()); 
}

bool User_Team::canAddPlayerCount(Player p) {
	return teamCount[p.getClub()] !=3;
}

void User_Team::pickSquad() {
	/// <summary>
	/// This is the main menu for picking squad
	/// </summary>
	int current_totalPlayers = totalPlayers;
	int position_picked;
	while(totalPlayers!=MAX_PLAYERS) {
		cout << "Pick a Position\n1.Goalkeeper\n2.Defender\n3.Midfielder\n4.Attacker\n";
		cin >> position_picked;
		
		if (position_picked == 1) {
			if (canAddPlayerPosition("GoalKeeper")) {
				//show goalkeepers to choose from
			}
			else {
				cout << "You have reached the maximum number of GoalKeepers to choose from\n";
			}
		}
		else if (position_picked == 2) {
			if (canAddPlayerPosition("Defender")) {
				//show Defender to choose from
			}
			else {
				cout << "You have reached the maximum number of Defenders to choose from\n";
			}
		}
		else if (position_picked == 3) {
			if (canAddPlayerPosition("Midfielder")) {
				//show Midfielders to choose from
			}
			else {
				cout << "You have reached the maximum number of Midfielders to choose from\n";
			}
		}
		else if (position_picked == 4) {
			if (canAddPlayerPosition("Attacker")) {
				//show Attackers to choose from
			}
			else {
				cout << "You have reached the maximum number of Attackers to choose from\n";
			}
		}
		else {
			cout << "Invalid Option\n";
		}
	}
}

void User_Team::pickPlayer(Player p) {
	/// <summary>
	/// this function updates all User_Team variables
	/// </summary>
	/// <param name="p">Player object</param>
	totalPrice += p.getPrice();

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