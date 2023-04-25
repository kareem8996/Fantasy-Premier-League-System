#include "gameWeek.h"

gameWeek::gameWeek()
{
	this->status = "";
	this->value = 0;
	this->total_points_gameweek = 0;
	this->goals_scored_gameweek = 0;
	this->assists_gameweek = 0;
	this->clean_sheets_gameweek = 0;
	this->red_cards_gameweek = 0;
	this->yellow_cards_gameweek = 0;
	this->saves_gameweek = 0;
}

gameWeek::gameWeek(string status, int value, int total_points_gameweek, int goals_scored_gameweek, int assists_gameweek, int clean_sheets_gameweek, int red_cards_gameweek, int yellow_cards_gameweek, int saves_gameweek)
{
	this->status = status;
	this->value = value;
	this->total_points_gameweek = total_points_gameweek;
	this->goals_scored_gameweek = goals_scored_gameweek;
	this->assists_gameweek = assists_gameweek;
	this->clean_sheets_gameweek = clean_sheets_gameweek;
	this->red_cards_gameweek = red_cards_gameweek;
	this->yellow_cards_gameweek = yellow_cards_gameweek;
	this->saves_gameweek = saves_gameweek;
}

void gameWeek::setStatus(string s)
{
	status = s;
}

void gameWeek::setValue(int n)
{
	value = n;
}

void gameWeek::setTotal_points_gameweek(int n)
{
	total_points_gameweek = n;
}

void gameWeek::setGoals_scored_gameweek(int n)
{
	goals_scored_gameweek = n;
}

void gameWeek::setAssists_gameweek(int n)
{
	assists_gameweek = n;
}

void gameWeek::setClean_sheets_gameweek(int n)
{
	clean_sheets_gameweek = n;
}

void gameWeek::setRed_cards_gameweek(int n)
{
	red_cards_gameweek = n;
}

void gameWeek::setYellow_cards_gameweek(int n)
{
	yellow_cards_gameweek = n;
}

void gameWeek::setSaves_gameweek(int n)
{
	saves_gameweek = n;
}

string gameWeek::getStatus()
{
	return status;
}

int gameWeek::getValue()
{
	return value;
}

int gameWeek::getTotal_points_gameweek()
{
	return total_points_gameweek;
}

int gameWeek::getGoals_scored_gameweek()
{
	return goals_scored_gameweek;
}

int gameWeek::getAssists_gameweek()
{
	return assists_gameweek;
}

int gameWeek::getClean_sheets_gameweek()
{
	return clean_sheets_gameweek;
}

int gameWeek::getRed_cards_gameweek()
{
	return red_cards_gameweek;
}

int gameWeek::getYellow_cards_gameweek()
{
	return yellow_cards_gameweek;
}

int gameWeek::getSaves_gameweek()
{
	return saves_gameweek;
}
