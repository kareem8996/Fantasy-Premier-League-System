#include "Admin.h"
#include "System.h"
#include "Player.h"
#include "string"
using namespace std;

Admin::Admin(int id, string& name, string& email, string& Adminname, string& password, string& phoneNumber) {
	id = id;
	name = name;
	phoneNumber = phoneNumber;
	email = email;
	Adminname = Adminname;
	password = password;

}
Admin::Admin() {}

void Admin::setId(int id) {
	this->id = id;
}

int Admin::getId() {
	return id;
}

bool Admin::setPhoneNumber(string phone_number) {
	bool vPhone;
	System checker;
	vPhone = checker.Check_Phone(phone_number);
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
	System checker;
	VName = checker.Check_Name(name);
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
	System checker;
	vEmail = checker.Check_Email(email);
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
	System checker;
	vUserName = checker.Check_Username(username);
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
	return Adminname;
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