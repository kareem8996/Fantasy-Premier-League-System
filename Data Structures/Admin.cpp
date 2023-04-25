#include "Admin.h"
#include "System.h"
#include "Player.h"
#include "string"
using namespace std;

Admin::Admin(string& name, string& email, string& Adminname, string& password, string& phoneNumber) {

	this-> name = name;
	this->phoneNumber = phoneNumber;
	this->email = email;
	this->userName = Adminname;
	this-> password = password;

}
Admin::Admin() {}



bool Admin::setPhoneNumber(string phone_number) {
	bool vPhone;
	
	vPhone =System::Check_Phone(phone_number);
	if (vPhone) {
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
void Admin::setName(string name) {
	bool VName;
	
	VName = System::Check_Name(name);
	if (VName) {
		cout << "Your Phone number changed Successfully";
		this->name = name;
	}

	else {
		cout << "Couldn't change your pohne number";

	}
}
void Admin::setEmail(string email)
{
	bool vEmail;
	
	vEmail = System::Check_Email(email);
	if (vEmail) {
		cout << "Your Phone number changed Successfully";

	}

	else {
		cout << "Couldn't change your pohne number";

	}

}
void Admin::setUsername(string username)
{
	bool vUserName;
	
	vUserName = System::Check_Username(username);
	if (vUserName) {
		cout << "Your Phone number changed Successfully";

	}

	else {
		cout << "Couldn't change your pohne number";

	}

}
string Admin::getName() {
	return name;
}
string Admin::getEmail()
{
	return email;
}
void Admin::setPassword(string password) {
}

string Admin::getUsername()
{
	return userName;
}

string Admin::getPassword() {
	return password;
}



//===================== Update Player Data=========================
void Admin::edit_player_menu() {}

//===================== Update Team Data=========================
void Admin::edit_team_menu() {}

//===================== Update User Account Data=========================
void Admin::edit_account() {}
//===================== Update League Data=========================
void Admin::edit_leagues() {}