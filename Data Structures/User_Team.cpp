#include "User_Team.h"
bool User_Team::canAddPlayerPosition(Player p) {
	if (p.getPosition() == "GoalKeeper" && !isGoalKeeper) {
		return true;
	}
	else if(p.getPosition() == "Defender" && totalDefenders!=MAX_DEFENDERS){
		return true;
	}
	else if (p.getPosition() == "Midfielder" && totalMidfielders != MAX_MIDFIELDERS) {
		return true;
	}
	else if (p.getPosition() == "Attacker" && totalAttackers != MAX_ATTACKERS) {
		return true;
	}
}

bool User_Team::canAddPlayerPrice(Player p) {
	return MAX_BUDGET >= (totalPrice + p.getPrice()); 
}

bool User_Team::canAddPlayerCount(Player p) {
	return teamCount[p.getClub()] !=3;
}