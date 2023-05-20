#include "Attacker.h"
#include "System.h"
Attacker::Attacker(int id, string PlayerName, string PlayerTeam, int PlayerTotalPoints, string PlayerPosition)
	:Player(id, PlayerName, PlayerTeam, PlayerTotalPoints, PlayerPosition)
{
}
int Attacker::CalculatePoints(int week) {
	int points = 0;
	for (auto& game : getPlayer_History()) {
		if (game.getRound() == week) {
			points += game.getGoals_scored_gameweek() * 4;
			points += game.getAssists_gameweek() * 3;
			points -= game.getYellow_cards_gameweek();
			points -= game.getRed_cards_gameweek() * 3;

			if (game.getMinutesPlayed() < 60&& game.getMinutesPlayed() > 0) points += 1;
			else if (game.getMinutesPlayed() >=60)points += 2;

			points -= game.getPenaltiesMissed() * 2;
			points += game.getBonus();
			points -= game.getOwnGoals() * 2;

		}
	}
	return points;
}
int Attacker::CalculatePoints() {
	return CalculatePoints(System::CurrGameWeek);
}

int Attacker::CalculateMatchPoints(int matchid) {
	int points = 0;
	for (auto& game : getPlayer_History()) {
		if (game.getmatchID() == matchid) {
			points += game.getGoals_scored_gameweek() * 4;
			points += game.getAssists_gameweek() * 3;
			points -= game.getYellow_cards_gameweek();
			points -= game.getRed_cards_gameweek() * 3;

			if (game.getMinutesPlayed() < 60 && game.getMinutesPlayed() > 0) points += 1;
			else if (game.getMinutesPlayed() >= 60)points += 2;

			points -= game.getPenaltiesMissed() * 2;
			points += game.getBonus();
			points -= game.getOwnGoals() * 2;
			return points;
		}
	}
}
