#include "gameWeek.h"
#include "System.h"
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
	this->minutes_played = 0;
	this->penalties_missed = 0;
	this->bonus = 0;
	this->goals_conceded = 0;
	this->own_goals = 0;
	this->penalties_saved = 0;
}

gameWeek::gameWeek(
	string status,
	int r,
	int value,
	int total_points_gameweek,
	int goals_scored_gameweek,
	int assists_gameweek, 
	int clean_sheets_gameweek,
	int red_cards_gameweek,
	int yellow_cards_gameweek,
	int saves_gameweek,
	int minutes_played,
	int penalties_missed,
	int bonus,
	int goals_conceded,
	int own_goals,
	int penalties_saved,
	int matchID
	)
{
	this->round = r;
	this->status = status;
	this->value = value;
	this->total_points_gameweek = total_points_gameweek;
	this->goals_scored_gameweek = goals_scored_gameweek;
	this->assists_gameweek = assists_gameweek;
	this->clean_sheets_gameweek = clean_sheets_gameweek;
	this->red_cards_gameweek = red_cards_gameweek;
	this->yellow_cards_gameweek = yellow_cards_gameweek;
	this->saves_gameweek = saves_gameweek;
	this->minutes_played = minutes_played;
	this->penalties_missed = penalties_missed;
	this->bonus = bonus;
	this->goals_conceded = goals_conceded;
	this->own_goals = own_goals;
	this->penalties_saved = penalties_saved;
	this->match_ID = matchID;
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

void gameWeek::setClean_sheets_gameweek()
{

	if(minutes_played >=60 && getFixtureCleansheet())
		clean_sheets_gameweek = 1;
	else
		clean_sheets_gameweek = 0;
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

// Getter for minutes_played
int gameWeek::getMinutesPlayed(){
	return minutes_played;
}

// Setter for minutes_played
void gameWeek::setMinutesPlayed(int minutes) {
	minutes_played = minutes;
}

// Getter for penalties_missed
int gameWeek::getPenaltiesMissed() {
	return penalties_missed;
}

// Setter for penalties_missed
void gameWeek::setPenaltiesMissed(int penalties) {
	penalties_missed = penalties;
}

// Getter for bonus
int gameWeek::getBonus() {
	return bonus;
}

// Setter for bonus
void gameWeek::setBonus(int bonus_value) {
	bonus = bonus_value;
}

// Getter for goals_conceded
int gameWeek::getGoalsConceded() {
	return goals_conceded;
}

// Setter for goals_conceded
void gameWeek::setGoalsConceded() {
	goals_conceded = getFixtureGoalConceded();
}

// Getter for own_goals
int gameWeek::getOwnGoals() {
	return own_goals;
}

// Setter for own_goals
void gameWeek::setOwnGoals(int own) {
	own_goals = own;
}

int gameWeek::getPenaltiesSaved() {
	return penalties_saved;
}

// Setter for own_goals
void gameWeek::getPenaltiesSaved(int saved) {
	penalties_saved = saved;
}


void gameWeek::increaseValue() {
	value += 1;
}
void gameWeek::decreaseValue() {
	value -= 1;
}
void gameWeek::setWashome(bool wh){
	wasHome = wh;
}

bool gameWeek::WasHome(){
	return wasHome;
}

void gameWeek::updatePenaltiesSaved(int val) {
	penalties_saved += val;
}

void gameWeek::updateOwnGoals(int val) {
	own_goals += val;
	updateFixture(val, true);
}
void gameWeek::updatePenaltiesMissed(int val) {
	penalties_missed += val;
}

void gameWeek::updateGoals_scored_gameweek(int goals) {
	goals_scored_gameweek += goals;
	updateFixture(goals,false);
}

void gameWeek::updateYellow_Cards_gameweek(int val) {
	yellow_cards_gameweek += val;
}

void gameWeek::updateAssists_gameweek(int assists) {
	assists_gameweek += assists;
}

void gameWeek::updateSaves_gameweek(int saves) {
	saves += saves;
}

int gameWeek::getmatchID()
{
	return match_ID;
}

void gameWeek::setmatchID(int matchID)
{
	match_ID = matchID;
}

void gameWeek::setRound(int r)
{
	this->round = r;
}

int gameWeek::getRound()
{
	return this->round;
}

void gameWeek::displayGameweek(string pos)
{
		
	cout << "Total Points: " << total_points_gameweek
		<< "\nBouns: " << bonus
		<< "\nMinutes Played: " << minutes_played
		<< "\nGoals Scored: " << goals_scored_gameweek
		<< "\nAssists: " << assists_gameweek
		<< "\nRed Cards: " << red_cards_gameweek
		<< "\nYellow Cards: " << yellow_cards_gameweek
		<< "\nPenalties Missed: " << penalties_missed
		<< "\nOwn goals: " << own_goals;
	if (pos != "FWD")
		cout<< "\nClean Sheet"<<clean_sheets_gameweek;
	if (pos == "GKP" || pos == "DEF")
		cout << "\nGoals Conceded:" << goals_conceded;
	if (pos == "GKP")
		cout<< "\nSaves: "<<saves_gameweek;



		
		
}





void gameWeek::updateFixture( int Score,bool Own){
	Fixture* match = System::AllFixtures[System::CurrGameWeek - 1][match_ID];
	if (!Own) {
		if (wasHome)
			match->updateHomescore(Score);
		else
			match->updateAwayscore(Score);
	}
	else {
		if (!wasHome)
			match->updateHomescore(Score);
		else
			match->updateAwayscore(Score);
	}
}
bool gameWeek::getFixtureCleansheet(){
	Fixture* match = System::AllFixtures[System::CurrGameWeek-1][match_ID];
	if (wasHome)
		return match->getHomescore()==0;
	else
		return match->getAwayscore()==0;
}
int gameWeek::getFixtureGoalConceded() {
	Fixture* match = System::AllFixtures[System::CurrGameWeek - 1][match_ID];
	if (wasHome)
		return match->getHomescore();
	else
		return match->getAwayscore();
}
Fixture* gameWeek::getFixture(){
	return System::AllFixtures[System::CurrGameWeek - 1][match_ID];
}
