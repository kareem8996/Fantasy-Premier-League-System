#include "Attacker.h"
Attacker::Attacker(int id, string PlayerName, string PlayerTeam, int PlayerTotalPoints, string PlayerPosition, string PlayerStatus)
	:Player(id, PlayerName, PlayerTeam, PlayerTotalPoints, PlayerPosition, PlayerStatus)
{
}
int Attacker::CalculatePoints() {
	int points = 0;
	points += this->getPlayer_History().back().getGoals_scored_gameweek() * 4;
	points += this->getPlayer_History().back().getAssists_gameweek() * 3;
	points -= this->getPlayer_History().back().getYellow_cards_gameweek();
	points -= this->getPlayer_History().back().getRed_cards_gameweek()*3;

	if (this->getPlayer_History().back().getMinutesPlayed()< 60) points += 1;
	else points += 2;

	points -= this->getPlayer_History().back().getPenaltiesMissed() * 2;
	points += this->getPlayer_History().back().getBonus();
	points -= this->getPlayer_History().back().getOwnGoals() * 2;
	return points;
}