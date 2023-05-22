#include "System.h"
#include "iostream"
#include <algorithm>
#include <typeinfo>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <stdio.h>   
#include <fstream>
#include <string>
#include <signal.h>
#include <sstream>  
#include "Defender.h"
#include "Midfielder.h"
#include "Attacker.h"
#include "GoalKeeper.h"
#include"User_Team.h"

using namespace std;

string const System::choice_error = "\tPlease enter your choice here --->\t";
vector<string>  System::domains= { "gmail.com","outlook.com","yahoo.com","hotmail.com","icloud.com","cis.asu.edu.eg" } ;
string  System::startchoice="",
        System:: registerChoice = "",
        System::loginChoice = "",
        System::menuChoice = "";
User* System::CurrUser ;
Admin* System::CurrAdmin;
int System::CurrGameWeek = 37;
unordered_map<int,User*> System::AllUsers;
unordered_map<int,Admin*> System::AllAdmins;
unordered_map<string, Club*> System::AllClubs; //name,club object
unordered_map < string, unordered_map<int, Player*>> System::AllPlayers;
unordered_map <int, User_Team*> System::AllUsersTeams;
unordered_map<int, League*> System::AllLeagues; //League id, League object
unordered_map<int, unordered_map<int, Fixture*>>System::AllFixtures;

void System::printSeprator() {
    cout << "-------------------------------------------------------------------------------------\n";
    cout << "\033[2J\033[1;1H";
}

void System::printSeprator_for_errors() {
    cout << "\n-------------------------------------------------------------------------------------\n";

}

void System::InputFaliure(string& choice, string message) {
    while (cin.fail()) {
        cin.clear();
        printSeprator_for_errors();
        cout << "\t\t\t\tInvalid entry\n ";
        printSeprator_for_errors();
        cout << message;
        getline(cin, choice);

        if (cin.fail()) {
            cin.ignore(INT_MAX, '\n');
            continue;
        }
        else
            break;
    }
}

void System::Start_menu() {

    loginChoice = "";
    cout << "\t------------Welcome to Premier League Fantasy !----------\n"
        << "\tWould you like to register or Login\n"
        << "\t\t1 - Login\t2 - Register\t3 - Quit\n";
    do {

        cout << "\tPlease enter your choice here --->\t";
        cin >> startchoice;
        if (cin.fail())
            InputFaliure(startchoice, choice_error);
        if (startchoice.size() == 1 && isdigit(startchoice[0])) {
            break;
        }
        else {
            printSeprator_for_errors();
            cout << "\t\tPlease enter a digit\n";
            printSeprator_for_errors();
        }
    } while (true);
    printSeprator();

}

void System::RegisterMenu() {
    cout << "\t\t\t\tRegister as : \n \t\t1 - Admin\t2 - User\t3 - Back to Main menu\t0 - To Exit\n";

    //TO prevent the user from entering any charcter that is not a number
    do {
        cout << "\tPlease enter your choice here --->\t";
        cin >> registerChoice;
        if (cin.fail())
            InputFaliure(registerChoice, choice_error);
        if (registerChoice.size() == 1 && isdigit(registerChoice[0])) {
            break;
        }
        else {
            printSeprator_for_errors();
            cout << "\t\tPlease enter a digit\n";
            printSeprator_for_errors();
        }
    } while (true);
    printSeprator();

}

bool System::Check_Name(string& Name) {

    /*Here we validate that the name should be at least three letters*/
    if (Name.size() < 3) {
        return false;
        cout << "Please enter a real name\n";

    }

    for (int i = 0; i < Name.size(); i++) {
        char c = Name[i];
        /*Here it checks if the string has number or not*/
        if (islower(c) || isupper(c) || isspace(c)) {

            continue;
        }
        else {
            cout << "Invalid entry\nPlease ";
            return false;
            break;
        }
    }
    return true;
}

bool System::Check_Database(string&username) {
    string org2 = "";
    for (int j = 0; j < username.size(); j++) {
        if (isalpha(username[j]))
            org2 += char(tolower(username[j]));
        else {
            org2 += username[j];
        }
    }
    username = org2;

    //lowering user or admin email and comparing
    for (auto& x : AllUsers) {
        if (x.second->getUsername() == org2) {
            cout << "Username Exists\n";
            return false;
        }
    }
    for (auto& x : AllAdmins) {
        if (x.second->getUsername() == org2) {
            cout << "Username Exists\n";
            return false;
        }
    }
    return true;
}
bool System::Check_Username(string& Username) {

    if (Username.size() < 2) {
        return false;
        cout << "Please enter a real name\n";

    }
    for (int i = 0; i < Username.size(); i++) {
        char c = Username[i];
        if (isalnum(c)) {
            continue;
        }
        else {
            cout << "Invalid entry\nPlease ";
            return false;
            break;
        }
    }
    return true;
}

bool System::Check_Password(string& Password)
{
    bool capital = false;
    bool special_char = false;
    bool number = false;

    if (Password.length() > 7) {
        for (int i = 0; i < Password.length(); i++)
        {
            if (!isalnum(Password[i]))
                special_char = true;
            else if (Password[i] >= 'A' && Password[i] <= 'Z')
                capital = true;
            else if (Password[i] >= '0' && Password[i] <= '9')
                number = true;


        }
        if (number && capital && special_char)
            return true;

    }
    else
        return false;


}

bool System::Check_PhoneDatabase(string phone) {

    for (auto& it : AllUsers) {
        if (it.second->getPhoneNumber() == phone)
        {
            cout << "This phone number is already used\n";
            return false;
        }
    }
    for (auto& it : AllAdmins) {
        if (it.second->getPhoneNumber() == phone)
        {
            cout << "This phone number is already used\n";
            return false;
        }
    }

    return true;
}
bool System::Check_Phone(string& Phone) {
    if (Phone.size() != 11) {
        cout << "Kindly Enter 11 Numbers\n";
        return false;

    }
    for (int i = 0; i < Phone.size(); i++) {
        if (!isdigit(Phone[i])) {
            cout << "Kindly Enter Numbers only!! \n";
            return false;
        }
    }

    if (Phone[0] != '0' || Phone[1] != '1' || (Phone[2] != '1' && Phone[2] != '2' && Phone[2] != '0' && Phone[2] != '5')) {
        cout << "Invalid phone number\nPlease ";
        return false;
    }
    return Check_PhoneDatabase(Phone);

}

bool System::Check_EmailDatabase(string &Email) {
    

    //lowering user or admin email and comparing
    for (auto & x: AllUsers) {
        if (x.second->getEmail() == Email) {
            cout << "Email Exists\n";
            return false;
        }
    }
    for (auto& x : AllAdmins) { 
        if (x.second->getEmail() == Email) {
            cout << "Email Exists\n";
            return false;
        }
    }
    return true;
}
bool System::Check_Email(string& Email) {

    //Lowering Email written by user or admin
    string org2 = "";
    for (int j = 0; j < Email.size(); j++) {
        if (isalpha(Email[j]))
            org2 += char(tolower(Email[j]));
        else {
            org2 += Email[j];
        }
    }
    Email = org2;

    int at_index = 0;
    at_index = Email.find("@");

    // check Email domain
    for (int i = 0; i < domains.size(); i++) {
        if (Email.find(domains[i], at_index) == -1) {
            while (i == domains.size() - 1) {
                cout << "Enter valid domain after (@)\n";
                return false;
            }
        }
        else
            break;
    }
    // check Email username
    string email_username = Email.substr(0, at_index);
    for (int i = 0; i < at_index; i++)
    {
        if (email_username[0] == '.' || email_username[at_index - 1] == '.') {
            cout << "(.) can't be first character or the character before (@)\n";
            return false;
        }

        if (email_username[i] != '.' && !isalnum(email_username[i]))
        {
            cout << "Invalid part before (@)\n";
            return false;

        }
    }
    return Check_EmailDatabase(Email);
}

void System::RegisterUser() {
    cout << "Now Registering as an User\n";
    string Name;
    string Username;
    string Phone;
    string Email;
    string TeamName;
    vector<string>leagues;
    string domains[6] = { "gmail.com","outlook.com","yahoo.com","hotmail.com","icloud.com","cis.asu.edu.eg" };
    string Password, conpass;         //For entering and checking password before sending it to database "Vector"
    int at_index = 1;
    bool test_name = true;       //A boolean to check if the name has numbers or not
    bool vUsername = true;
    bool Check_Password = true;
    bool vPhone = true;
    bool vEmail = true;
    cin.ignore();
    /*Input of Name*/
    do {
        cout << "Enter your Full name: ";
        getline(cin, Name);
        if (cin.fail())
            InputFaliure(Name, "Please Enter your Full name:");
        test_name = Check_Name(Name);
    } while (test_name != true);

    /*Input of username*/
    do {
        do {
            cout << "Enter Username: ";
            getline(cin, Username);
            if (cin.fail())
                InputFaliure(Username, "Please Enter your Username:");
            test_name = Check_Username(Username);
        } while (test_name != true);


        vUsername = Check_Database(Username);
        if (vUsername) {
            // input password
            do {
                cout << "Enter Password: ";
                do {
                    cin >> Password;
                    if (cin.fail())
                        InputFaliure(Password, "Please enter your Password:");
                    if (Password == Username) {
                        Check_Password = false;
                        cout << "The password is the same as your username\nPlease enter another password:";
                    }
                    else
                        Check_Password = true;
                } while (Check_Password != true);
                cout << "Renter password: ";
                cin >> conpass;
                if (cin.fail())
                    InputFaliure(conpass, "Please renter password: ");
                if (Password != conpass)
                    cout << "Password doesn't match\nPlease enter the password again\n";
            } while (Password != conpass);
            // input Phone
            do {
                cout << "Enter Phone Number: ";
                cin >> Phone;
                if (cin.fail())
                    InputFaliure(Phone, "Please enter Phone Number:");
                vPhone = Check_Phone(Phone);
            } while (!vPhone);
            // input Email
            do {
                cout << "Enter Your email: ";
                cin >> Email;
                if (cin.fail())
                    InputFaliure(Email, "Please enter Email:");
                vEmail = Check_Email(Email);
            } while (!vEmail);
            cout << "Enter Team Name: ";
            cin.ignore();
            getline(cin, TeamName);
            int id = AllUsers.size() + 1;
            
            AllUsers.insert({id, (new User(id, Name, Email, Username, Password, Phone, 0, TeamName )) });
            CurrUser = AllUsers[id];
        }
        else {
            cout << "this username is already taken, Please enter another username.\n";
        }
    } while (vUsername != true);
    cout << "\t\tThank You for registering on our system!\n";
    printSeprator();
    loginChoice = "2";
    startchoice = "1";
}

void System::RegisterAdmin() {
    cout << "Now Registering as an Admin\n";
    string Name;
    string Username;
    string Phone;
    string Email;
    
    string Password, conpass;         //For entering and checking password before sending it to database "Vector"
    int at_index = 1;
    bool test_name = true;       //A boolean to check if the name has numbers or not
    bool vUsername = true;
    bool Check_Password = true;
    bool vPhone = true;
    bool vEmail = true;
    cin.ignore();
    /*Input of Name*/
    do {
        cout << "Enter your Full name: ";
        getline(cin, Name);
        if (cin.fail())
            InputFaliure(Name, "Please Enter your Full name: ");
        test_name = Check_Name(Name);
    } while (test_name != true);

    /*Input of username*/
    do {
        do {
            cout << "Enter Username: ";
            getline(cin, Username);
            if (cin.fail())
                InputFaliure(Username, "Please Enter your Username: ");
            test_name = Check_Username(Username);
        } while (test_name != true);


        vUsername = Check_Database(Username);
        if (vUsername) {
            // input password
            do {
                cout << "Enter Password: ";
                do {
                    cin >> Password;
                    if (cin.fail())
                        InputFaliure(Password, "Please enter your Password: ");
                    if (Password == Username) {
                        Check_Password = false;
                        cout << "The password is the same as your username\nPlease enter another password: ";
                    }
                    else
                        Check_Password = true;
                } while (Check_Password != true);
                cout << "Renter password: ";
                cin >> conpass;
                if (cin.fail())
                    InputFaliure(conpass, "Please renter password: ");
                if (Password != conpass)
                    cout << "Password doesn't match\nPlease enter the password again\n";
            } while (Password != conpass);
            // input Phone
            do {
                cout << "Enter Phone Number: ";
                cin >> Phone;
                if (cin.fail())
                    InputFaliure(Phone, "Please enter Phone Number: ");
                vPhone = Check_Phone(Phone);
            } while (!vPhone);
            // input Email
            do {
                cout << "Enter Your email: ";
                cin >> Email;
                if (cin.fail())
                    InputFaliure(Email, "Please enter Email: ");
                vEmail = Check_Email(Email);
            } while (!vEmail);
            int id = AllAdmins.size() + 1;
            AllAdmins.insert({ id,(new Admin({id, Name, Email, Username, Password, Phone}))});
            CurrAdmin = AllAdmins[id];
        }
        else {
            cout << "this username is already taken, Please enter another username.\n";
        }
    } while (vUsername != true);
    cout << "\t\tThank You for registering on our system!\n";
    printSeprator();
    loginChoice = "1";
    startchoice = "1";
}

bool System::userLogin( string attemptedUsername, string attemptedPassword) {
    for (auto& it : AllUsers) {
        if (it.second->getUsername() == attemptedUsername && it.second->getPassword()==attemptedPassword) {
            CurrUser = it.second;
            return true;
        }
    }
    return false;
}

bool System::AdminLogin( string attemptedUsername, string attemptedPassword) {
    for (auto& it : AllAdmins) {
        if (it.second->getUsername() == attemptedUsername && it.second->getPassword() == attemptedPassword) {
            CurrAdmin = it.second;
            return true;
        }
    }
    return false;
}

User_Team& System::getsquad(int id)
{    
    unordered_map <int, User_Team*> ::const_iterator got = AllUsersTeams.find(id);
   

    if (got == AllUsersTeams.end()) {
        User_Team* newUserTeam = new User_Team(id);
        AllUsersTeams.insert({ id, newUserTeam });
       
        return *AllUsersTeams[id];
    
    }
    
        
    else
        return *got->second;
    

}

User* System::getUser(int id)
{
    return AllUsers[id];
}

void System::Pass_Encode(string& pass) {
    char input = '0';
    while (input != '\r') {
        input = _getch();
        if (input == '\b') {
            if (pass.size() > 0) {
                pass.pop_back();
                cout << "\b \b";
            }
        }
        else {
            pass += input;
            cout << "*";
        }
    }
    pass.pop_back();
}
void System::loginInput() {
    string tAgain="Y";
    do{
        string attemptedUserName, attemptedPassword;

        cout << "Enter username: \n";
        cin >> attemptedUserName;
        if (cin.fail())
            InputFaliure(attemptedUserName, "Try to enter Your username");
        string org2 = "";
        for (int j = 0; j < attemptedUserName.size(); j++) {
            if (isalpha(attemptedUserName[j]))
                org2 += char(tolower(attemptedUserName[j]));
            else {
                org2 += attemptedUserName[j];
            }
        }
        attemptedUserName = org2;

        cout << "Enter password: \n";
        
        Pass_Encode(attemptedPassword);
        if (userLogin( attemptedUserName, attemptedPassword)) {
            loginChoice = '2';
            tAgain = "N";
        }
        else if (AdminLogin( attemptedUserName, attemptedPassword))
        {
            loginChoice = '1';
            tAgain = "N";
        }
        else {
            cout << "Invalid Username or Password\n";
            do{
                cout << "Would you like to Try again?? (Y/N)";
                cin >> tAgain;
                if (cin.fail())
                    InputFaliure(tAgain, "Please enter your choice correctly");
            } while ((tAgain != "Y" && tAgain != "y") && (tAgain != "N" && tAgain != "n"));

            if(tAgain == "N" || tAgain == "n") loginChoice[0] = '3';

        }
        printSeprator();

    } while (tAgain!= "N" && tAgain != "n");
    printSeprator();
}
void System::printAdminMenu() {
    string Logout_choice = "";
    string Quit_choice = "";
    do {
        cout << "Hello " << CurrAdmin->getName() << endl;
        cout << "\t\tWhat would you like to do ??\n"
            << "\t\t1 - Edit Users\n"
            << "\t\t2 - Edit Leagues\n"
            << "\t\t3 - Edit Fixtures\n"
            << "\t\t4 - Edit Club\n"
            << "\t\t5 - Edit Player\n"
            << "\t\t6 - Start New Gameweek\n"
            << "\t\t7 - Change Account Info\n"
            << "\t\t8 - To Logout\n"
            << "\t\t9 - To Quit the System\n";
        do {
            cout << "\tPlease enter your choice here --->\t";
            cin >> menuChoice;
            if (cin.fail())
                InputFaliure(menuChoice, choice_error);
            if (menuChoice.size() == 1 && isdigit(menuChoice[0])) {
                break;
            }
            else {
                printSeprator_for_errors();
                cout << "\t\t\tPlease enter a digit\n";
                printSeprator_for_errors();
            }
        } while (true);
        switch (menuChoice[0])
        {
        case '1':
            printSeprator();
            CurrAdmin->edit_user();
            printSeprator();
            break;
        case '2':
            printSeprator();
            CurrAdmin->edit_leagues();
            Sleep(5000);
            printSeprator();
            break;
        case '3':
            printSeprator();
            CurrAdmin->edit_fixture_menu();
            Sleep(5000);
            printSeprator();
            break;
        case '4':
            printSeprator();
            //CurrAdmin->edit_team_menu();
            Sleep(5000);
            printSeprator();
            break;
        case '5':
            printSeprator();
            CurrAdmin->edit_player_menu();
            Sleep(5000);
            printSeprator();
            break;
        case '6':
            printSeprator();
            CurrAdmin->startNewGameweek();
            Sleep(3000);
            printSeprator();
            break;

        case '7':
            ChangeAccountSettings(CurrAdmin);
            break;

        case '8':

            do {
                cout << "Are you sure you want to logout? (Y/N)\n";
                cin >> Logout_choice;
                if (Logout_choice.size() == 1 && isalpha(Logout_choice[0])) {
                    if (Logout_choice[0] == 'Y' || Logout_choice[0] == 'y') {
                        cout << "Logging you out";
                        for (int i = 0; i < 3; i++) {
                            Sleep(1000);
                            cout << ". ";
                        }
                        loginChoice = "3";
                        cout << "\n--------------------Thank You for using our system!--------------------\n";
                        Sleep(1000);
                        return;
                        break;
                    }
                    else if (Logout_choice[0] == 'N' || Logout_choice[0] == 'n') {
                        Sleep(1000);
                        printSeprator();
                        break;
                    }
                    else {

                        printSeprator_for_errors();
                        cout << "\t\tPlease enter a (Y/N)\n";
                        printSeprator_for_errors();
                    }
                }
                else {
                    printSeprator_for_errors();
                    cout << "\t\tPlease enter a (Y/N)\n";
                    printSeprator_for_errors();
                }

            } while (Logout_choice[0] != 'Y' || Logout_choice[0] != 'y' || Logout_choice[0] == 'N' || Logout_choice[0] == 'n');
            break;
        case '9':
            cout << "Are you Sure you want to Quit?\n";
            do {
                cin >> Quit_choice;
                if (Quit_choice.size() == 1 && isalpha(Quit_choice[0])) {
                    if (Quit_choice[0] == 'Y' || Quit_choice[0] == 'y') {
                        cout << "Exiting the system";

                        for (int i = 0; i < 3; i++) {
                           Sleep(1000);
                            cout << ". ";
                        }
                        cout << "\n--------------------Thank You for using our system!--------------------\n";
                        writeAdmins();
                        writeUsers();
                        writeUserTeams();
                        writeLeagues();
                        writeClub();
                        writeFixtures();
                        writeSystemconfig();
                        Sleep(1000);
                        exit(0);
                        break;
                    }
                    else if (Quit_choice[0] == 'N' || Quit_choice[0] == 'n') {
                        Sleep(1000);
                        printSeprator();
                        break;
                    }
                    else {

                        printSeprator_for_errors();
                        cout << "\t\tPlease enter (Y/N)\n";
                        printSeprator_for_errors();
                    }
                }
                else {
                    printSeprator_for_errors();
                    cout << "\t\tPlease enter (Y/N)\n";
                    printSeprator_for_errors();
                }

            } while (Quit_choice[0] != 'Y' || Quit_choice[0] != 'y' || Quit_choice[0] == 'N' || Quit_choice[0] == 'n');
            break;
        
        default:
            printSeprator();
            cout << "\tSorry this is an invalid choice please enter again.\n";
            printSeprator();
            break;
        }

    } while (menuChoice != "8");

}
void System::printUserMenu() {
    string Logout_choice = "";
    string Quit_choice = "";
    do{

    cout << "Hello " << CurrUser->getName()<<endl;
    cout << "\t\tWhat would you like to do ??\n"
        << "\t\t1 - Manage Squad\n"
        << "\t\t2 - Create League\n"
        << "\t\t3 - Join League\n"
        << "\t\t4 - Manage League\n"
        << "\t\t5 - Change Account Info\n"
        << "\t\t6 - Show players\n"
        << "\t\t7 - To Logout\n"
        << "\t\t8 - To Quit the System\n";
    do {
        cout << "\tPlease enter your choice here --->\t";
        cin >> menuChoice;
        if (cin.fail())
            InputFaliure(menuChoice, choice_error);
        if (menuChoice.size() == 1 && isdigit(menuChoice[0])) {
            break;
        }
        else {
            printSeprator_for_errors();
            cout << "\t\t\tPlease enter a digit\n";
            printSeprator_for_errors();
        }
    } while (true);
    switch (menuChoice[0])
    {
    case '1':
        printSeprator();
        ManageSqaudMenu(getsquad(CurrUser->getID()));
        printSeprator();
        break;
    case '2':
        printSeprator();
        createLeague();
        Sleep(5000);
        printSeprator();
        break;
    case '3':
        printSeprator();
        joinLeague();
        Sleep(5000);
        printSeprator();
        break;
    case '4':
        printSeprator();
        manageLeagues();
        Sleep(5000);
        printSeprator();
        break;
    case '5':
        printSeprator();
        ChangeAccountSettings(CurrUser);
        Sleep(3000);
        printSeprator();
        break;

    case '6': {
        string id;
        string position_picked;
        cout << "\nPick a Position\n"
            << "1.Goalkeeper " 
            << "\n2.Defender " 
            << "\n3.Midfielder " 
            << "\n4.Attacker "
            << "\n0.To go back\n";
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
        displayPlayers(position_picked);
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
        DisplayPlayerGameweek(AllPlayers[position_picked][stoi(id)]);
        
        }
        break;
    case '7':
            
        do {
            cout << "Are you sure you want to logout? (Y/N)\n";
            cin >> Logout_choice;
            if (Logout_choice.size() == 1 && isalpha(Logout_choice[0])) {
                if (Logout_choice[0] == 'Y' || Logout_choice[0] == 'y') {
                    cout << "Logging you out";
                    for (int i = 0; i < 3; i++) {
                        Sleep(1000);
                        cout << ". ";
                    }
                    loginChoice = "3";
                    cout << "\n--------------------Thank You for using our system!--------------------\n";
                    Sleep(1000);
                    return;
                    break;
                }
                else if (Logout_choice[0] == 'N' || Logout_choice[0] == 'n') {
                    Sleep(1000);
                    printSeprator();
                    break;
                }
                else {

                    printSeprator_for_errors();
                    cout << "\t\tPlease enter a (Y/N)\n";
                    printSeprator_for_errors();
                }
            }
            else {
                printSeprator_for_errors();
                cout << "\t\tPlease enter a (Y/N)\n";
                printSeprator_for_errors();
            }

        } while (Logout_choice[0] != 'Y' || Logout_choice[0] != 'y' || Logout_choice[0] == 'N' || Logout_choice[0] == 'n');
        break;
    case '8':
        cout << "Are you Sure you want to Quit?\n";
        do {
            cin >> Quit_choice;
            if (Quit_choice.size() == 1 && isalpha(Quit_choice[0])) {
                if (Quit_choice[0] == 'Y' || Quit_choice[0] == 'y') {
                    cout << "Exiting the system";

                    for (int i = 0; i < 3; i++) {
                        Sleep(1000);
                        cout << ". ";
                    }
                    cout << "\n--------------------Thank You for using our system!--------------------\n";
                    writeAdmins();
                    writeUsers();
                    writeUserTeams();
                    writeLeagues();
                    writeClub();
                    writeFixtures();
                    writeSystemconfig();
                    Sleep(1000);
                    exit(0);
                    break;
                }
                else if (Quit_choice[0] == 'N' || Quit_choice[0] == 'n') {
                    Sleep(1000);
                    printSeprator();
                    break;
                }
                else {

                    printSeprator_for_errors();
                    cout << "\t\tPlease enter (Y/N)\n";
                    printSeprator_for_errors();
                }
            }
            else {
                printSeprator_for_errors();
                cout << "\t\tPlease enter (Y/N)\n";
                printSeprator_for_errors();
            }

        } while (Quit_choice[0] != 'Y' || Quit_choice[0] != 'y' || Quit_choice[0] == 'N' || Quit_choice[0] == 'n');
        break;
    default:
        printSeprator();
        cout << "\tSorry this is an invalid choice please enter again.\n";
        printSeprator();
        break;
    }


    } while (menuChoice != "5");
    
}




void System::RunSys() {
    printSeprator();
    do {
        /*
        Start Menu
        -------------
        1-It is the menu where the program starts
        2-It is the menu where the program should go to when the user choose to Logout
        -------------------------------------------------------------------------------
        Form
        ----
        1-Login
        2-Register
        3-Exit the program
        -------------------------------------------------------------------------------
        Suggestion
        -----------
        We can make a 4th choice (Forgot Password)
        */
        if (startchoice == "") {

            Start_menu();

        }
        /*
        Login Menu
        -------------------
        1-It starts when the user enters 1
        2-It will always start with Login Input function
        */
        if (startchoice == "1") {
            do {
                if (loginChoice == "") {
                    if (AllUsers.size() != 0||AllAdmins.size()!=0) {
                        /*
                        LoginInput is the function that the user enter his username and password
                        ==========================================================================
                        REMEMBER:
                        A- Edit this function so that when the user enter his username and password
                           the system will check the database and when it knows who he is (Doc or patient)

                        B- When you finish it tell me so that I can make it access
                           the required menu (Doc_Menu or Patient_menu)
                        C- we need to make a counter so that when the user enter his username and pss more than 3 times
                           The program will ask to reset the passwords
                        */
                        loginInput();
                    }
                    else {
                        cout << "There is no registered Accounts\n";
                        startchoice = "";
                        Sleep(3000);
                        printSeprator();
                        break;
                    }
                }
                /*
                These are the keys of the cases, they depend on the end of the Login input
                ---------------------------------------------------------------------------
                1- For doctors Menu
                2- For Patient menu
                3- Is the case that makes the step back to the Start menu
                ==============================================================================
                To make it clear this do...while loop ends when the login choice is 3
                ==============================================================================
                */
                switch (loginChoice[0]) {
                case '1':
                    printAdminMenu();
                    break;
                case '2':
                    printUserMenu();
                    break;
                case '3': { {
                        startchoice = "";
                        cout << "\t\tHEADING\t BACK\t TO\t MAIN MENU\n";
                        Sleep(3000);
                        printSeprator(); }}
                        break;
                default:
                    loginChoice[0] = '\0';
                    break;
                }
            } while (loginChoice[0] != '3');
        }
        /*
        Register Menu
        -------------------
        1-It starts when the user enters 2
        2-It will always start with RegisterMenu function
        */
        if (startchoice == "2") {
            do {
                /*
                This is the Register Menu
                ----------------------------
                1- Doctor
                2- Patient
                3- Go back to start menu
                4- Exit the program
                */
                RegisterMenu();
                switch (registerChoice[0]) {
                case '1':
                    /*Doctor Registeration
                    displa
                    1-Full Name
                    2-Username
                    3-Password
                    4-Phone number
                    */
                    RegisterAdmin();
                    break;
                case '2':
                    /*Patient Registeration
                    ------------------------
                    1-Full Name
                    2-Username
                    3-Password
                    4-Age
                    5-Gender
                    */
                    RegisterUser();
                    break;
                case '3':
                    startchoice = "";
                    cout << "\t\tHEADING BACK TO MAIN MENU\n";
                    Sleep(3000);
                    printSeprator();
                    break;
                case '0':
                    cout << "--------------------Thank You for using our system!--------------------\n";
                    
                    writeAdmins();
                    writeUsers();
                    writeUserTeams();
                    writeLeagues();
                    writeClub();
                    writeFixtures();
                    writeSystemconfig();
                    exit(0);
                    break;
                default:
                    cout << "\t\tSorry this is an invalid choice please enter again.\n";
                    Sleep(5000);
                    printSeprator();
                    break;
                }
            } while (startchoice == "2");
        }
        //Here is to exit the program
        else if (startchoice == "3") {
            cout << "--------------------Thank You for using our system!--------------------\n";
            
            writeAdmins();
            writeUsers();
            writeUserTeams();
            writeLeagues();
            writeClub();
            writeFixtures();
            writeSystemconfig();
            exit(0);

        }
        //This is a default answer if the user enter a strange number
        else {
            startchoice = "";
            printSeprator_for_errors();
            /*cout << "\t\tSorry this is an invalid choice please enter again.\n";*/
            Sleep(3000);
            printSeprator();
        }
    } while (true);

}


void System::displayPlayers(Player* p, bool flag = false, string delim = "\n") {
    /// <summary>
    /// displays only one player
    /// </summary>
    /// <param name="p">player object</param>
    /// <paramname="flag">This is used so we can use the same code twice</param>
    /// <param name="delim"> the delimiter can either be enter or tab</param>
    System::printSeprator_for_errors();
    cout << "ID: " << p->getID() << delim;
    cout << "Name: " << p->getFullname() << delim;
    cout << "Club: " << p->getClub() << delim;
    cout << "Price: " << (float)p->getPlayer_History().back().getValue() / 10 << delim;
    cout << "Current Week Points: " << p->getPlayer_History().back().getTotal_points_gameweek() << delim;
    cout << "Total Points: " << p->getTotalPoints() << delim;
    if (!flag) {
        cout << "Position: " << p->getPosition() << delim;
        cout << "Status: " << p->getPlayer_History().back().getStatus() << delim;
        cout << "Current Week Goals: " << p->getPlayer_History().back().getGoals_scored_gameweek() << delim;
        cout << "Total Goals: " << p->getTotalGoals() << delim;
        cout << "Current Week Assists: " << p->getPlayer_History().back().getAssists_gameweek() << delim;
        cout << "Total Assists: " << p->getTotalAssists() << delim;
        cout << "Current Week Yellow Cards: " << p->getPlayer_History().back().getYellow_cards_gameweek() << delim;
        cout << "Total Yellow Cards: " << p->getTotalYellowCards() << delim;
        cout << "Current Week Red Card: " << p->getPlayer_History().back().getRed_cards_gameweek() << delim;
        cout << "Total Red Cards: " << p->getTotalRedCards() << endl;



        if (p->getPosition() == "MID") {
            Midfielder* m = (Midfielder*)p;
            cout << "Current Week Cleansheet: " << m->getPlayer_History().back().getClean_sheets_gameweek() << delim;
            cout << "Total Cleansheet: " << m->getTotalCleanSheets() << delim;
        }
        else if (p->getPosition() == "DEF") {
            Defender* d = (Defender*)(p);
            cout << "Current Week Cleansheet: " << d->getPlayer_History().back().getClean_sheets_gameweek() << delim;
            cout << "Total Cleansheet: " << d->getTotalCleanSheets() << endl;
        }
        else if (p->getPosition() == "GKP") {
            GoalKeeper* g = (GoalKeeper*)p;
            cout << "Current Week Saves: " << g->getPlayer_History().back().getSaves_gameweek() << delim;
            cout << "Total Saves: " << g->getTotalSaves() << delim;
            cout << "Current Week Cleansheet: " << g->getPlayer_History().back().getClean_sheets_gameweek() << delim;
            cout << "Total Cleansheet: " << g->getTotalCleanSheets() << endl;
        }

    }
}

void System::DisplayPlayerGameweek(Player *p) {
        System::printSeprator_for_errors();
    EnterGameweekTodisplay:
        cout << "Player Played Fixtures\n";
        System::printSeprator_for_errors();
        vector<gameWeek>playerHist = p->getPlayer_History();
        for (auto& match : playerHist) {

            Fixture* f = AllFixtures[match.getRound()][match.getmatchID()];
            cout << "Gameweek " << match.getRound() << " : " << getClubByID(f->getHomeTeam()) << "\tVS\t" << getClubByID(f->getAwayTeam()) << endl;
        }
        string gameweekNo;
        cout << "Select Match to display its stats (or hit 0 to go back)\n";
        cin >> gameweekNo;
        if (cin.fail())
            System::InputFaliure(gameweekNo, "write a suitable number ");
        if (gameweekNo == "0")
            return;
        if (System::isNumber(gameweekNo) && (stoi(gameweekNo) < 38 && stoi(gameweekNo) > 0)) {
            for (auto& match : playerHist) {
                if (match.getRound() == stoi(gameweekNo)) {
                    Fixture* f = AllFixtures[match.getRound()][match.getmatchID()];
                    cout << "\t\t" << getClubByID(f->getHomeTeam()) << "\tVS\t" << getClubByID(f->getAwayTeam()) << endl;
                    match.displayGameweek(p->getPosition());
                    printSeprator_for_errors();
                }
            }

            goto EnterGameweekTodisplay;
        }
        else {
            cout << "Invalid Choice\n Please choose again\n";
        }
        string anything;
        cout << "Press anything to exit\n";
        cin >> anything;
    printSeprator_for_errors();
}



void System::displayClubs()
{

    for (auto club : System::AllClubs) {
        cout << club.first << endl;
    }

}

void System::displayPlayers(string position) {

    /// <summary>
    /// Displays all players who play in a certain position
    /// </summary>
    /// <param name="position"></param>
    for (auto& it : System::AllPlayers[position]) {
        if(it.second!=nullptr)
             displayPlayers(it.second, true, "\t||\t");
    }
}
string System::getClubByID(int id) {
    for (auto& club : AllClubs) {
        if (club.second->getClubID() == id) return club.second->getName();
    }
}
void System::readFixtures() {

    unordered_map<string, vector<string>>row;
    string line, cellData;
    fstream file("Fixtures.csv", ios::in);
    int row_counter = -1;
    Player* p = nullptr;
    int player_id;
    if (file.is_open())
    {
        vector<string> column_names;
        while (getline(file, line))
        {
            stringstream str(line);
            int column_counter = 0;
            //Getting columns headers
            while (getline(str, cellData, ',')) {
                if (row_counter == -1) {
                    row.insert({ cellData,vector<string>{} });
                    column_names.push_back(cellData);
                    continue;
                }
                else {
                    row[column_names[column_counter]].push_back(cellData);
                }
                column_counter++;
            }
            if (row_counter > -1) {
                bool finish = row["finished"][row_counter] == "TRUE";
                int h_score = finish ? stoi(row["team_h_score"].at(row_counter)) : 0;
                int a_score = finish ? stoi(row["team_a_score"].at(row_counter)) : 0;
                
                Fixture* match = new Fixture(stoi(row["id"].at(row_counter)),
                    h_score,
                    a_score,
                    stoi(row["team_h"].at(row_counter)),
                    stoi(row["team_a"].at(row_counter)),
                    stoi(row["team_h_difficulty"].at(row_counter)),
                    stoi(row["team_a_difficulty"].at(row_counter)),
                    finish);
                match->updateWinnerPoints();
                AllClubs[getClubByID(stoi(row["team_h"].at(row_counter)))]->updateFixtures(stoi(row["event"].at(row_counter)),stoi(row["id"].at(row_counter)));
                AllClubs[getClubByID(stoi(row["team_a"].at(row_counter)))]->updateFixtures(stoi(row["event"].at(row_counter)),stoi(row["id"].at(row_counter)));
                AllFixtures[stoi(row["event"].at(row_counter))].insert({ stoi(row["id"].at(row_counter)),match });
            }
            row_counter++;
        }
    }
}



void System::readPlayers() {
    /// <summary>
    /// Reads AllPlayers
    /// First while loop loops on row
    /// Second While loop loops on column
    /// First iteration gathers column names
    /// Rest iterations gathers player data and stores them in AllPlayers
    /// </summary>
    unordered_map<string, vector<string>>row;
    string line, cellData;
    fstream file("total_players.csv", ios::in);
    int row_counter = -1;
    Player* p=nullptr;
    int player_id;
    if (file.is_open())
    {
        vector<string> column_names;
        while (getline(file, line))
        {
            stringstream str(line);
            int column_counter = 0;
            while (getline(str, cellData, ',')) {
                if (row_counter == -1) {
                    row.insert({ cellData,vector<string>{} });
                    column_names.push_back(cellData);
                    continue;
                }
                else {
                        row[column_names[column_counter]].push_back(cellData);
                    }
                column_counter++;
            }
            if (row_counter>-1) {
                if (p==nullptr||stoi(row["id_player"].at(row_counter)) != p->getID()) {//initializing
                    if (row["position"].at(row_counter) == "MID") {
                        Midfielder* m = new Midfielder(stoi(row["id_player"].at(row_counter)),
                            row["first_name"].at(row_counter) + " " + row["second_name"].at(row_counter),
                            row["name"].at(row_counter),
                            stoi(row["gameweek_points"].at(row_counter)),
                            row["position"].at(row_counter),
                            stoi(row["total_clean_sheets"].at(row_counter)));
                      
                        
                        m->updatePlayer_History({
                            row["status"].at(row_counter),
                            stoi(row["round"].at(row_counter)),
                            stoi(row["value"].at(row_counter)),
                            stoi(row["gameweek_points"].at(row_counter)),
                            stoi(row["gameweek_goals"].at(row_counter)),
                            stoi(row["gameweek_assists"].at(row_counter)),
                            stoi(row["gameweek_clean_sheets"].at(row_counter)),
                            stoi(row["gameweek_red_cards"].at(row_counter)),
                            stoi(row["gameweek_yellow_cards"].at(row_counter)),
                            stoi(row["gameweek_saves"].at(row_counter)),
                            stoi(row["minutes"].at(row_counter)),
                            stoi(row["penalties_missed"].at(row_counter)),
                            stoi(row["bonus"].at(row_counter)),
                            stoi(row["goals_conceded"].at(row_counter)),
                            stoi(row["own_goals"].at(row_counter)),
                            stoi(row["penalties_saved"].at(row_counter)),
                           stoi(row["fixture"].at(row_counter))

                            });
                        
                        p = m;
                    }
                    else if (row["position"].at(row_counter) == "DEF") {
                        Defender* d = new Defender(stoi(row["id_player"].at(row_counter)),
                            row["first_name"].at(row_counter) + " " + row["second_name"].at(row_counter),
                            row["name"].at(row_counter),
                            stoi(row["gameweek_points"].at(row_counter)),
                            row["position"].at(row_counter),
                            stoi(row["total_clean_sheets"].at(row_counter)));


                        d->updatePlayer_History({
                            row["status"].at(row_counter),
                            stoi(row["round"].at(row_counter)),
                            stoi(row["value"].at(row_counter)),
                            stoi(row["gameweek_points"].at(row_counter)),
                            stoi(row["gameweek_goals"].at(row_counter)),
                            stoi(row["gameweek_assists"].at(row_counter)),
                            stoi(row["gameweek_clean_sheets"].at(row_counter)),
                            stoi(row["gameweek_red_cards"].at(row_counter)),
                            stoi(row["gameweek_yellow_cards"].at(row_counter)),
                            stoi(row["gameweek_saves"].at(row_counter)),
                            stoi(row["minutes"].at(row_counter)),
                            stoi(row["penalties_missed"].at(row_counter)),
                            stoi(row["bonus"].at(row_counter)),
                            stoi(row["goals_conceded"].at(row_counter)),
                            stoi(row["own_goals"].at(row_counter)),
                            stoi(row["penalties_saved"].at(row_counter)),
                           stoi(row["fixture"].at(row_counter))

                            });
                        
                        p = d;
                    }
                    else if (row["position"].at(row_counter) == "FWD") {
                        Attacker* a = new Attacker(
                            stoi(row["id_player"].at(row_counter)),
                            row["first_name"].at(row_counter) + " " + row["second_name"].at(row_counter),
                            row["name"].at(row_counter), stoi(row["gameweek_points"].at(row_counter)), 
                            row["position"].at(row_counter));

                        a->updatePlayer_History({
                            row["status"].at(row_counter),
                            stoi(row["round"].at(row_counter)),
                            stoi(row["value"].at(row_counter)),
                            stoi(row["gameweek_points"].at(row_counter)),
                            stoi(row["gameweek_goals"].at(row_counter)),
                            stoi(row["gameweek_assists"].at(row_counter)),
                            stoi(row["gameweek_clean_sheets"].at(row_counter)),
                            stoi(row["gameweek_red_cards"].at(row_counter)),
                            stoi(row["gameweek_yellow_cards"].at(row_counter)),
                            stoi(row["gameweek_saves"].at(row_counter)),
                            stoi(row["minutes"].at(row_counter)),
                            stoi(row["penalties_missed"].at(row_counter)),
                            stoi(row["bonus"].at(row_counter)),
                            stoi(row["goals_conceded"].at(row_counter)),
                            stoi(row["own_goals"].at(row_counter)),
                            stoi(row["penalties_saved"].at(row_counter)),
                            stoi(row["fixture"].at(row_counter))

                            });
                        p = a;
                    }
                    else if (row["position"].at(row_counter) == "GKP") {
                        GoalKeeper* g = new GoalKeeper(
                            stoi(row["id_player"].at(row_counter)),
                            row["first_name"].at(row_counter) + " " + row["second_name"].at(row_counter),
                            row["name"].at(row_counter), stoi(row["gameweek_points"].at(row_counter)), 
                            row["position"].at(row_counter), 
                            stoi(row["total_saves"].at(row_counter)),  
                            stoi(row["total_clean_sheets"].at(row_counter)));

                        g->updatePlayer_History({
                           row["status"].at(row_counter),
                           stoi(row["round"].at(row_counter)),
                           stoi(row["value"].at(row_counter)),
                           stoi(row["gameweek_points"].at(row_counter)),
                           stoi(row["gameweek_goals"].at(row_counter)),
                           stoi(row["gameweek_assists"].at(row_counter)),
                           stoi(row["gameweek_clean_sheets"].at(row_counter)),
                           stoi(row["gameweek_red_cards"].at(row_counter)),
                           stoi(row["gameweek_yellow_cards"].at(row_counter)),
                           stoi(row["gameweek_saves"].at(row_counter)),
                           stoi(row["minutes"].at(row_counter)),
                           stoi(row["penalties_missed"].at(row_counter)),
                           stoi(row["bonus"].at(row_counter)),
                           stoi(row["goals_conceded"].at(row_counter)),
                           stoi(row["own_goals"].at(row_counter)),
                           stoi(row["penalties_saved"].at(row_counter)),
                           stoi(row["fixture"].at(row_counter))
                            });
                        p = g;
                    }
                    if (AllClubs[p->getClub()]->isSquadEmpty()) {
                        
                        player_id = p->getID();

                    }
                    AllClubs[p->getClub()]->insertPlayer(p);
                    /*AllClubs[p->getClub()]->updateFixtures(stoi(row["opponent_team"].at(row_counter)));*/
                    p->setTotalPoints(stoi(row["total_points"].at(row_counter)));
                    p->setTotalGoals(stoi(row["total_goals_scored"].at(row_counter)));
                    p->setTotalAssists(stoi(row["total_assists"].at(row_counter)));
                    p->setTotalYellowCards(stoi(row["total_yellow_cards"].at(row_counter)));
                    p->setTotalRedCards(stoi(row["total_red_cards"].at(row_counter)));
                    System::AllPlayers[p->getPosition()].insert({ p->getID(),p });
                }
                else {//updating

                /*AllClubs[p->getClub()]->updateFixtures(stoi(row["opponent_team"].at(row_counter)));
                if (p->getID()==player_id) {
                    if (stoi(row["team_h_score"].at(row_counter)) == stoi(row["team_a_score"].at(row_counter))) {
                        AllClubs[p->getClub()]->draw_UpdatePoints();
                    }
                    else {
                        if (stoi(row["team_h_score"].at(row_counter)) > stoi(row["team_a_score"].at(row_counter)) && row["was_home"].at(row_counter) == "TRUE") {
                            AllClubs[p->getClub()]->win_UpdatePoints();
                        }
                        if (stoi(row["team_h_score"].at(row_counter)) < stoi(row["team_a_score"].at(row_counter)) && row["was_home"].at(row_counter) == "FALSE") {
                            AllClubs[p->getClub()]->win_UpdatePoints();
                        }
                    }
                }*/

                    p->updatePlayer_History({
                            row["status"].at(row_counter),
                            stoi(row["round"].at(row_counter)),
                            stoi(row["value"].at(row_counter)),
                            stoi(row["gameweek_points"].at(row_counter)),
                            stoi(row["gameweek_goals"].at(row_counter)),
                            stoi(row["gameweek_assists"].at(row_counter)),
                            stoi(row["gameweek_clean_sheets"].at(row_counter)),
                            stoi(row["gameweek_red_cards"].at(row_counter)),
                            stoi(row["gameweek_yellow_cards"].at(row_counter)),
                            stoi(row["gameweek_saves"].at(row_counter)),
                            stoi(row["minutes"].at(row_counter)),
                            stoi(row["penalties_missed"].at(row_counter)),
                            stoi(row["bonus"].at(row_counter)),
                            stoi(row["goals_conceded"].at(row_counter)),
                            stoi(row["own_goals"].at(row_counter)),
                            stoi(row["penalties_saved"].at(row_counter)),
                            stoi(row["fixture"].at(row_counter))

                        });
                }
            }
            row_counter++;
        }
    }
        cout << "Reading successful\n";
}

void System::readClub()
{
    unordered_map<string, vector<string>>row;
    string line, cellData;
    fstream file("teams.csv", ios::in);
    int row_counter = -1;
    // Read the header row to find the Club_ID and Club ShortName columns
    vector<string> column_names;

    if (file.is_open())
    {
        while (getline(file, line))
        {
            stringstream str(line);
            int column_counter = 0;
            while (getline(str, cellData, ',')) {
                if (row_counter == -1) {
                    row.insert({ cellData,vector<string>{} });
                    column_names.push_back(cellData);
                    continue;
                }
                else {
                    row[column_names[column_counter]].push_back(cellData);
                }
                column_counter++;
            }
            if (row_counter > -1) {
                
                Club*club = new  Club(
                    stoi(row["id"].at(row_counter)),
                    row["name"].at(row_counter)
                );
                AllClubs.insert({ club->getName(), club });
            }
            row_counter++;
        }
    }
}
string System::space2underscore(string text) {
    for (int i = 0; i < text.size(); i++) {
        if (text[i] == ' ')
            text[i] = '_';
    }
    return text;

}

string System::underscore2space(string text) {
    for (int i = 0; i < text.size(); i++) {
        if (text[i] == '_')
            text[i] = ' ';
    }
    return text;
}

void System::readUsers()
{
    fstream UsersFile;
    UsersFile.open("Users.txt", ios::in);

    if (UsersFile.is_open())
    {
        string DataLine;
        while (UsersFile >> DataLine)
        {
            User* user = new User();
            user->setID(stoi(DataLine));
            UsersFile >> DataLine;
            user->setName(underscore2space(DataLine));
            UsersFile >> DataLine;
            user->setUsername(DataLine);
            UsersFile >> DataLine;
            user->setPassword(DataLine);
            UsersFile >> DataLine;
            user->setPhoneNumber(DataLine);
            UsersFile >> DataLine;
            user->setEmail(DataLine);
            UsersFile >> DataLine;
            user->setTotalPoints(stoi(DataLine));
            UsersFile >> DataLine;
            user->setTeamName(underscore2space(DataLine));
            
            // user->setBirthdate(DataLine);
            AllUsers.insert(make_pair(user->getID(), user));
        }
        UsersFile.close();
    }
}

void System::readAdmins()
{
    fstream AdminsFile;
    AdminsFile.open("Admins.txt", ios::in);

    if (AdminsFile.is_open())
    {
        string DataLine;
        while (AdminsFile >> DataLine)
        {
            Admin* admin = new Admin();
            admin->setID(stoi(DataLine));
            AdminsFile >> DataLine;
            admin->setName(underscore2space(DataLine));
            AdminsFile >> DataLine;
            admin->setUsername(DataLine);
            AdminsFile >> DataLine;
            admin->setPassword(DataLine);
            AdminsFile >> DataLine;
            admin->setEmail(DataLine);
            AdminsFile >> DataLine;
            admin->setPhoneNumber(DataLine);
            AllAdmins.insert(make_pair(admin->getID(), admin));
        }
        AdminsFile.close();
    }
}


void System::readUserTeams()
{
    fstream UserTeamsFile;
    string line, cellData;

    UserTeamsFile.open("UserTeams.txt", ios::in);

    if (UserTeamsFile.is_open())
    {
        string DataLine;
        while (UserTeamsFile >> DataLine)
        {
            int UserID = stoi(DataLine);
            User_Team* team = new User_Team();
            UserTeamsFile >> DataLine;
            team->setTotalPlayers(stoi(DataLine));
            UserTeamsFile >> DataLine;
            team->setTotalAttackers(stoi(DataLine));
            UserTeamsFile >> DataLine;
            team->setTotalDefenders(stoi(DataLine));
            UserTeamsFile >> DataLine;
            team->setTotalMidfielders(stoi(DataLine));
            UserTeamsFile >> DataLine;
            team->setIsGoalKeeper(stoi(DataLine));
            UserTeamsFile >> DataLine;
            team->setTotalBudget(stoi(DataLine));
            UserTeamsFile >> DataLine;
            UserTeamsFile >> DataLine;
            map<string, int> teamCount;

            while (DataLine != "==========CurrentSquad==============") { //Reading Team clubs counts
                int count = 0;
                string team_name;
                stringstream str(DataLine);
                while (getline(str, cellData, ':')) {
                    if (count == 0) {
                        team_name = cellData;
                        count++;
                    }
                    else {
                        teamCount.insert({ team_name,stoi(cellData) });
                    }
                }
                UserTeamsFile >> DataLine;
            }
            unordered_map<string, unordered_map<int, Player*>> currsquad;
            currsquad.insert({ "GKP", {  } });
            currsquad.insert({ "FWD", {  } });
            currsquad.insert({ "DEF", {  } });
            currsquad.insert({ "MID", {  } });
            while (DataLine != "==========EndCurrentSquad===============") { //Reading Current squad
                int count = 0;
                string postion;
                stringstream str(DataLine);
                while (getline(str, cellData, ':')) {
                    if (count == 0) {
                        postion = cellData;
                        count++;
                    }
                    else  {
                        currsquad[postion].insert({{stoi(cellData),AllPlayers[postion][stoi(cellData)]}});
                    }
                }
                UserTeamsFile >> DataLine;
            }

            UserTeamsFile >> DataLine;          //Reading ==========Gameweeks==============
            UserTeamsFile >> DataLine;         //Reading Gameweek:20:points:100

            

            unordered_map<int, pair<vector < pair<string, int>>, int >> SquadHistory;
            string weekNum;
            string ponits;
            vector < pair<string, int>> weeksqaud;
            bool weekPointsExtracted = false;
            bool SquadExtracted = false;

            while (DataLine != "==========EndGameweeks==============") { //Reading Current squad
                int count = 0;

                string _;
                stringstream str2(DataLine);
                while (getline(str2, cellData, ':')&& !weekPointsExtracted) {
                    if (count  == 1) {
                        weekNum= cellData;
                        count++;
                    }
                    else if (count == 4) {
                        ponits= cellData;
                        count++;
                        weekPointsExtracted = true;
                    }
                    count++;
                }
                while (weekPointsExtracted && DataLine != "==========EndSquad===============") {
                    UserTeamsFile >> DataLine;     //GKP:10
                    string postion;
                    string playerId;
                    int count = 0;
                    stringstream str3(DataLine);
                    while (getline(str3, cellData, ':')) {
                        if (count == 0) {
                            postion = cellData;
                            count++;
                        }
                        else {
                            playerId = cellData;
                            weeksqaud.push_back({ postion,stoi(playerId) });
                            
                        }

                    }

                }
                if (DataLine == "==========EndSquad===============") {
                    weekPointsExtracted = false;
                    SquadHistory.insert({ stoi(weekNum),{weeksqaud,stoi(ponits)} });
                }

                UserTeamsFile >> DataLine;     //==========Squad===============
            }
                UserTeamsFile >> DataLine;     //==========EndUser==============
                team->setTeamCount(teamCount);
                team->setSquad(currsquad);
                team->setTotalPointsPerWeek(SquadHistory);
                
                AllUsersTeams.insert({ UserID, team });
        }
            UserTeamsFile.close();
    }
}



void System::readLeagues()
{
    fstream UserTeamsFile;
    string line, cellData;

    UserTeamsFile.open("Leagues.txt", ios::in);

    if (UserTeamsFile.is_open())
    {
        string DataLine;
        while (UserTeamsFile >> DataLine)
        {
            League* league = new League();
            league->setId(stoi(DataLine));
            UserTeamsFile >> DataLine;
            league->setname(System::underscore2space(DataLine));
            UserTeamsFile >> DataLine;
            league->setIsPublic((bool)stoi(DataLine));
            UserTeamsFile >> DataLine;
            league->setCode(stoi(DataLine));
            UserTeamsFile >> DataLine;//==========LeaderBoard==============
            league->setLeagueCreator(System::getUser(stoi(DataLine)));
            AllUsers[stoi(DataLine)]->updateLeagues(league->getId());
            UserTeamsFile >> DataLine;

            UserTeamsFile >> DataLine;//==========LeaderBoard============== skip

            while (DataLine != "==========EndLeague==============") {
                int count = 0;
                int score;
                stringstream str(DataLine);
                while (getline(str, cellData, ',')) {
                    if (count == 0) {
                        score = stoi(cellData);
                        count++;
                    }
                    else {
                        User* u = new User();
                        u = System::getUser(stoi(cellData));

                        league->insertUser(score, u);
                    }

                }

                UserTeamsFile >> DataLine;
            }
            AllLeagues.insert({ league->getId(),league });
            
        }
    }
    UserTeamsFile.close();

}

void System::writeUsers()
{
    fstream UsersFile;
    UsersFile.open("Users.txt", ios::out);

    if (UsersFile.is_open())
    {
        unordered_map<int, User*>::iterator it;
        it = AllUsers.begin();
        while (it != AllUsers.end())
        {
            UsersFile << it->second->getID() << endl;
            UsersFile << space2underscore(it->second->getName()) << endl;
            UsersFile << it->second->getUsername() << endl;
            UsersFile << it->second->getPassword() << endl;
            UsersFile << it->second->getPhoneNumber() << endl;
            UsersFile << it->second->getEmail() << endl;
            UsersFile << it->second->getTotalPoints() << endl;
            UsersFile << it->second->getTeamName() << endl;
            it++;
        }


    }

    UsersFile.close();
}

void System::writeAdmins()
{

    fstream adminsFile;
    adminsFile.open("Admins.txt", ios::out);

    if (adminsFile.is_open())
    {

        unordered_map<int, Admin*>::iterator it;
        it = AllAdmins.begin();
        while (it != AllAdmins.end())
        {
            adminsFile << it->second->getID() << endl;
            adminsFile << space2underscore(it->second->getName()) << endl;
            adminsFile << it->second->getUsername() << endl;
            adminsFile << it->second->getPassword() << endl;
            adminsFile << it->second->getEmail() << endl;
            adminsFile << it->second->getPhoneNumber() << endl;
            it++;
        }
    }
    adminsFile.close();
}

void System::writeUserTeams()
{
    fstream UserTeams;
    UserTeams.open("UserTeams.txt", ios::out); //write data
    if (UserTeams.is_open()) {
        for (auto team = AllUsersTeams.begin(); team != AllUsersTeams.end(); team++) {
            UserTeams << team->first<<endl; // User ID
            UserTeams << team->second->getTotalPlayers() << endl;
            UserTeams << team->second->getTotalAttackers() << endl;
            UserTeams << team->second->getTotalDefenders() << endl;
            UserTeams << team->second->getTotalMidfielders() << endl;
            UserTeams << team->second->getIsGoalKeeper() << endl;
            UserTeams << team->second->getTotalBudget() << endl;
            map<string, int> teamCount = team->second->getTeamCount();
            UserTeams << "==========UserTeamClubsCount=============="<<endl;
            for (auto PlayersTeam = teamCount.begin(); PlayersTeam != teamCount.end(); PlayersTeam++) {
                UserTeams << PlayersTeam->first << ":" << PlayersTeam->second<<endl;
            }
            
            UserTeams << "==========CurrentSquad=============="<<endl;

            unordered_map<string, unordered_map<int, Player*>> currsquad=team->second->getCurrentSquad();
            for (auto Squad : currsquad) {                     /// Getting all Current Squad
                for(auto player:Squad.second)
                    UserTeams <<  Squad.first << ":" << player.first<< endl;
            }
            UserTeams << "==========EndCurrentSquad===============\n";
            UserTeams << "==========Gameweeks=============="<<endl;
            unordered_map<int, pair<vector<pair<string, int>>, int >> gameweeksPoints = team->second->getSquadPerWeek();
            for (auto weeksquad: gameweeksPoints) {                     /// Getting all gameweeks for the team 
                
                UserTeams <<"GameWeek:"<<weeksquad.first<<":Points:"<< weeksquad.second.second<< endl;
                UserTeams << "==========Squad===============\n";
                for (auto player:weeksquad.second.first) {
                    
                    UserTeams << player.first << ":" << player.second<<endl;

                }
                UserTeams << "==========EndSquad===============\n";
            }
            UserTeams << "==========EndGameweeks=============="<<endl;
            UserTeams << "==========EndUser=============="<<endl;


        }
    }
    UserTeams.close();

}

void System::writeLeagues()
{
    fstream Leagues;
    Leagues.open("Leagues.txt", ios::out); //write data
    if (Leagues.is_open()) {
        for (auto league = AllLeagues.begin(); league != AllLeagues.end(); league++) {
            Leagues << league->first << endl; // League ID
            Leagues << System::space2underscore(league->second->getName()) << endl;
            Leagues << league->second->IsPublic() << endl;
            Leagues << league->second->getcode() << endl;
            Leagues << league->second->getLeagueCreatorID() << endl;
            priority_queue<pair<int, pair<int, User*>>> playersLeaderBoard;
            Leagues << "==========LeaderBoard==============\n";
            playersLeaderBoard = league->second->getLeaderBoard();
            int Leaderboard_count = playersLeaderBoard.size();
            /// Score,UserID
            for (int i = 0; i < Leaderboard_count; i++)
            {
                Leagues << playersLeaderBoard.top().first << "," << playersLeaderBoard.top().second.first << endl;
                playersLeaderBoard.pop();

            }
            Leagues << "==========EndLeague==============\n";


        }
    }
    Leagues.close();

}

void System::createLeague() {
    string League_Name;
    int id = AllLeagues.size() + 1;
    string public_option;
    bool isPublic;

    cout << "Enter League Name: ";
    cin >> League_Name;
    if (cin.fail())
        InputFaliure(League_Name, "Enter League Name");
    cout << "Will the league be public? (Y/N)\n";
    cin >> public_option;
    if (cin.fail())
        InputFaliure(public_option, "Write Y or N");

    if (public_option == "y" || public_option == "Y") {
        isPublic = true;
    }
    else {
        isPublic = false;
    }
    League* NL = new League(id, League_Name,CurrUser ,isPublic);
    AllLeagues.insert({ id,NL });
    CurrUser->updateLeagues(id);
    cout << "League created\n";

}

void System::joinLeague(){
    string choice;
    string leagueID;
    cout << "\t\tWhat would you like to do ??\n"
        << "\t\t1 - Join Public League\n"
        << "\t\t2 - Join Private League \n";
    Enterchoice:
    cin >> choice;
    if (cin.fail())
        InputFaliure(choice, "Please enter your choice");

    switch (choice[0]) {
    case'1':
        displayLeagues(false);
        cout << "Choose League ID or 0 to go back\n";
        cin >> leagueID;
            if (cin.fail())
                InputFaliure(leagueID, "Please write a valid league id");

            if (isNumber(leagueID)) {
                
                for (auto& league : AllLeagues) {
                    if (league.second->getId() == stoi(leagueID)) {
                        if (!league.second->userExists(CurrUser->getID())) {
                            league.second->insertUser(CurrUser);
                            cout << "You are now member of " << league.second->getName() << " League.";
                               
                        }


                        else
                            cout << "You are already a member of this league\n";
                    }
                }
            }
            else goto Enterchoice;
        break;
    case'2': {

        string code; /// Insert League code
        while (true) {
            cout << "Enter Invitation Code you received";
            cin >> code;
            if (cin.fail())
                InputFaliure(code, "write a suitable code consisting of only numbers");
            if (isNumber(code)) {
                break;
            }
            else {
                cout << "Please write a code consisting of only numbers\n";
            }
        }
        bool found = false;

        for (auto& league : AllLeagues) {
            if (league.second->getcode() == stoi(code)) {
                if (!league.second->userExists(CurrUser->getID())) {
                    league.second->insertUser(CurrUser);
                    cout << "You are now member of " << league.second->getName() << " League.";
                }


                else
                    cout << "You are already a member of this league\n";
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "No league found with the code you wrote\n";
        }
        break;
    
    }

    default:
        cout << "Invalid Choice";
        goto Enterchoice;
        break;

    }
    
    
    
    
}

void System::writeClub()
{
    fstream clubFile;
    clubFile.open("C:\\writeClub\\writeClub.csv", ios::out); //write data
    if (clubFile.is_open())
    {
        clubFile << "ClubID,clubName,TotalPoints\n";
        for (auto& x : System::AllClubs)
        {
            clubFile << x.second->getClubID() << "," << x.first << "," << x.second->getLeaguePoints() << endl;
        }
        clubFile.close();
    }
}

void System::manageLeagues() {
    string League_option;
    string User_option;

    //Display Personal Leagues
    vector<int> personalLeagues = CurrUser->getLeagues();
   
    if (personalLeagues.size() != 0) {
        for (int i = 0; i < personalLeagues.size(); i++) {
            League* currentLeague = AllLeagues[personalLeagues[i]];
            cout << currentLeague->getId() << " - " << currentLeague->getName() << endl;
        }

        cout << "Choose League ID or 0 to go back\n";
        while (true) {
            cin >> League_option;
            if (cin.fail())
                InputFaliure(League_option, "Please write a valid league id");

            if (isNumber(League_option)) {
                if (stoi(League_option) == 0) return;
                if (find(personalLeagues.begin(), personalLeagues.end(),stoi( League_option)) != personalLeagues.end()) {
                    break;
                }
                else {
                    cout << "You do not have access to the league you have written its code\nWrite League ID";
                }
                if (stoi(League_option) == 0) return;
            }
            else {
                cout << "Please write a code that consists of numbers only\n";
            }

        }

        cout << AllLeagues[stoi(League_option)]->getName() << endl;
        cout << "\t\tWhat would you like to do ??\n"
            << "\t\t1 - View Leaderboard\n";


        if (AllLeagues[stoi(League_option)]->getLeagueCreatorID() == CurrUser->getID()) {
        }
        else {
            cout << "\t\t2 - Leave League\n";
        }
        cout << "\t\t3 - Back\n";
        cout << "Invitation Code is: " << AllLeagues[stoi(League_option)]->getcode() << endl;
        while (true) {
            cin >> User_option;
            if (cin.fail())
                InputFaliure(User_option, "Please write a suitable option");

            if (isNumber(User_option)) {
                if (stoi(User_option) == 1 || stoi(User_option) == 2 || stoi(User_option) == 3) {
                    break;
                }
                else {
                    cout << "Please write a suitable option";
                }
            }
            else {
                cout << "Please write a number\n";
            }

        }

        League* currentLeague = AllLeagues[stoi(League_option)];
        switch (stoi(User_option))
        {
        case 1:
            
            currentLeague->displayLeaderboard();
            cout << "Choose Manager you want to view or 0 to go back\n";
            while (true) {
                cin >> User_option;
                if (cin.fail())
                    InputFaliure(User_option, "Please write a suitable option");

                if (isNumber(User_option)) {
                    if (stoi(User_option) == 0) {
                        manageLeagues();
                        break;
                    }
                     else if (currentLeague->getLeaderBoard().size() >= stoi(User_option)) {
                        break;
                    }
                    else {
                        cout << "Please write a suitable option";
                    }
                }
                else {
                    cout << "Please write a number\n";
                }

            }
        
            currentLeague->displayUser(stoi(User_option) - 1);
            cout << "\n\n\n";
            AllUsersTeams[CurrUser->getID()]->displaySquad();
            break;

        case 2:
            if (currentLeague->getLeagueCreatorID() == CurrUser->getID()) {
                //Invite
                cout << "Invalid please choose again\n";
                manageLeagues();
            }
            else {
                //Leave
                currentLeague->removeUser(CurrUser->getID());
            }
            break;
        case 3:
            manageLeagues(); //return to start of manageLeagues
            break;

        default:
            break;
        }
    }
    else {
        cout << "You are not a member in any of the leagues\n";
    }
}

void System::displayLeagues(bool displayAll) {
    for (auto& t : AllLeagues) {
        if(t.second->IsPublic() && !displayAll)
            cout << t.second->getId() << " - " << t.second->getName() << endl;
        else
            cout << t.second->getId() << " - " << t.second->getName() << endl;
    }
}

bool System::isNumber(string s)
{
    for (char & ch : s) {
        if (isdigit(ch) == 0)
            return false;
    }
    return true;
}

void System::ChangeAccountSettings(User* CurrUser) {
    string option;
    string changing;
    string reenter_password;
    CurrUser->displaydata();
    cout << "\n\t\tWhat would you like to change ??\n"
        << "\t\t1 - Name\n"
        << "\t\t2 - Username\n"
        << "\t\t3 - Password\n"
        << "\t\t4 - Email\n"
        << "\t\t5 - Phone number\n"
        << "\t\t6 - Team name\n"
        << "\t\t7 - Go back\n";

    do {
        cout << "\tPlease enter your choice here --->\t";
        cin >> option;
        if (cin.fail())
            InputFaliure(option, choice_error);
        if (option.size() == 1 && isdigit(option[0])) {
            break;
        }
        else {
            printSeprator_for_errors();
            cout << "\t\t\tPlease enter a digit\n";
            printSeprator_for_errors();
        }
    } while (true);


    switch (stoi(option))
    {

    case 1:
        do {
            cout << "Write new name\n";
            cin >> changing;
            if (cin.fail())
                InputFaliure(changing, "Please enter new name ");
        } while (!Check_Name(changing));
        CurrUser->setName(changing);

        break;
    case 2:
        do {
            cout << "Write new username\n";
            cin >> changing;
            if (cin.fail())
                InputFaliure(changing, "Please enter new username ");

            if (!Check_Database(changing)) {
                cout << "this username already exists\n";
            }
        } while (!Check_Username(changing) && !Check_Database(changing));
        CurrUser->setUsername(changing);
        break;

    case 3:
        do {
            cout << "Write new password \n";
            cin >> changing;
            if (cin.fail())
                InputFaliure(changing, "Please enter your Password: ");
            if (changing != CurrUser->getUsername()) {
                break;
            }
            else
                cout << "The password is the same as your username\nPlease enter another password: ";
        } while (true);
        do {
            cout << "Renter password: ";
            cin >> reenter_password;
            if (cin.fail())
                InputFaliure(reenter_password, "Please renter password: ");
            if (reenter_password == changing)
                break;
            else
                cout << "Password doesn't match\nPlease enter the password again\n";
        } while (true);
        CurrUser->setPassword(changing);
        break;

    case 4:
        do {
            cout << "Enter Your email: ";
            cin >> changing;
            if (cin.fail())
                InputFaliure(changing, "Please enter Email: ");
        } while (!Check_Email(changing));
        CurrUser->setEmail(changing);
        break;

    case 5:
        do {
            cout << "Enter Phone Number: ";
            cin >> changing;

            if (cin.fail())
                InputFaliure(changing, "Please enter Phone Number: ");

            if (!Check_PhoneDatabase(changing)) {
                cout << "this phone already exists\n";
            }
        } while (!Check_Phone(changing) && !Check_PhoneDatabase(changing));
        CurrUser->setPhoneNumber(changing);
        break;

    case 6:
        cout << "Enter your team name: ";
        cin >> changing;
        CurrUser->setTeamName(changing);
        break;
    case 7:
        return;
    default:
        cout << "invalid input\n";
        break;
    }

}

void System::ChangeAccountSettings(Admin *CurrAdmin)
{
    string changing;
    string reenter_password;
    string option;
    CurrAdmin->displaydata();
    cout << "\n\t\tWhat would you like to change ??\n"
        << "\t\t1 - Name\n"
        << "\t\t2 - Username\n"
        << "\t\t3 - Password\n"
        << "\t\t4 - Email\n"
        << "\t\t5 - Phone number\n"
        << "\t\t6 - Team name\n"
        << "\t\t7 - Go back\n";

    do {
        cout << "\tPlease enter your choice here --->\t";
        cin >> option;
        if (cin.fail())
            InputFaliure(option, choice_error);
        if (option.size() == 1 && isdigit(option[0])) {
            break;
        }
        else {
            printSeprator_for_errors();
            cout << "\t\t\tPlease enter a digit\n";
            printSeprator_for_errors();
        }
    } while (true);
    switch (stoi(option))
    {

    case 1:

        cout << "Enter your Name\n";
        cin >> changing;
        if (cin.fail())
            InputFaliure(changing, "Please enter new name ");
        CurrAdmin->setName(changing);

        break;
    case 2:
        cout << "Write new username\n";
        cin >> changing;
        if (cin.fail())
            InputFaliure(changing, "Please enter new username ");
        CurrAdmin->setUsername(changing);
        break;

    case 3:

        cout << "Write new password\n";
        cin >> changing;
        if (cin.fail())
            InputFaliure(changing, "Please enter your Password: ");

        cout << "Renter password: ";
        cin >> reenter_password;
        if (cin.fail())
            InputFaliure(reenter_password, "Please renter password: ");

        CurrAdmin->setPassword(changing, reenter_password);
        break;

    case 4:

        cout << "Enter Your email: ";
        cin >> changing;
        if (cin.fail())
            InputFaliure(changing, "Please enter Email: ");
        CurrAdmin->setEmail(changing);
        break;

    case 5:

        cout << "Enter Phone Number: ";
        cin >> changing;

        if (cin.fail())
            InputFaliure(changing, "Please enter Phone Number: ");

        CurrAdmin->setPhoneNumber(changing);
        break;
    case 7:

        return;
        break;

    default:
        cout << "invalid input\n";
        break;
    }
}

void System::Transfers() {
    User_Team* Current_Team = AllUsersTeams[CurrUser->getID()];
    Current_Team->displaySquadPrice();

    int totalBudget = (float)Current_Team->getTotalBudget()/10;
    int Transfers_left = Current_Team->getTransfers();
    cout << "Remaining Transfers: " << Transfers_left << endl << endl;
    cout << "Please write id of the player you want to replace:\n";
    string user_option;
    string position;
    bool flag = false;
    while (true) {
        cin >> user_option;
        if (cin.fail())
            System::InputFaliure(user_option, "write a suitable number ");
        if (System::isNumber(user_option)) {
            for (auto& s : Current_Team->getCurrentSquad()) {
                for (auto& x : s.second) {
                    if (x.second->getID() == stoi(user_option)) {
                        if (Transfers_left == 0) {
                            string option;
                            cout << "Are you sure you want to replace player, you will lose 4 points. (Y/N)\n";
                            cin >> option;
                            if ((option == "Y" || option == "y")) {
                                Current_Team->RemovePlayer(x.second);
                                position = x.second->getPosition();
                                // Reduce Points
                                Current_Team->PunishTransfers();
                                flag = true;
                            }
                                break;
                            
                        }
                        else {
                            Current_Team->RemovePlayer(x.second);
                            position = x.second->getPosition();
                            Current_Team->decreaseTransfers();
                            flag = true;
                            break;
                        }
                        
                        
                    }

                }
                if (flag) break;
            }
            if (flag) break;
            else "Invalid Choice please choose someone in your team\n";
        }
        else {
            cout << "Please choose a suitable option\n";
        }
    }
    while (true) {
        displayPlayers(position);
        cout << "Budget: " << (float)Current_Team->getTotalBudget() / 10 << endl;
        cout << "Remaining Transfers: " << Current_Team->getTransfers() << endl<<endl;
        cout << "Choose Player Id: ";
        string id;
        while (true) {
            cin >> id;
            if (cin.fail())
                System::InputFaliure(id, "write a suitable number ");
            if (System::isNumber(id)) {
                if (System::AllPlayers[position].find(stoi(id)) != System::AllPlayers[position].end()) {
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
        if (!Current_Team->Player_Exist(stoi(id))) {

            System::displayPlayers(System::AllPlayers[position][stoi(id)], false, "\n");
            string Player_Option;
            cout << "Are you sure you want to pick " << System::AllPlayers[position][stoi(id)]->getFullname() << " ?\n";
            cin >> Player_Option;

            if (Player_Option == "Y" || Player_Option == "y") {

                if (Current_Team->canAddPlayerPrice(AllPlayers[position][stoi(id)])) {

                    if (Current_Team->canAddPlayerCount(AllPlayers[position][stoi(id)])) {

                        Current_Team->pickPlayer(AllPlayers[position][stoi(id)]);
                        return;
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
        Sleep(3000);
    }
}

void System::ManageSqaudMenu(User_Team& c) {

    if (c.getTotalPlayers() == 11) {
        while (true) {
            cout << "\t\tWhat would you like to do ??\n"
                << "\t\t1 - Transfers \n"
                << "\t\t2 - Veiw Players \n"
                << "\t\t3 - Back \n";
            string user_option;
            int User_option;
            while (true) {
                cin >> user_option;
                if (cin.fail())
                    System::InputFaliure(user_option, "write a suitable number ");
                if (System::isNumber(user_option)) {
                    User_option = stoi(user_option);
                    if (User_option == 0) {
                        return;
                    }
                    else if (User_option <= 3) {
                        break;
                    }
                }
                else {
                    cout << "Please write a suitable option\n";
                }
            }
            if (User_option == 1) {
                Transfers();
            }
            else if (User_option == 2) {
                ViewPlayers();
            }
            else if (User_option == 3) return;

            else {
                cout << "Invalid Option\n\n";
            }
        }

    }
    else {
        c.pickSquad();
    }



}

void System::ViewPlayers() { // Last gameweek SQUAD
    User_Team* Current_Team = AllUsersTeams[CurrUser->getID()];
    int weekNo;
    
    weekNo = Current_Team->displayGameweeks();
    while (true) {
        Current_Team->displaySquad(weekNo);
        string id,user_option;
        bool flag = false;
        while (true) {
        cout << "Choose Player to view or press 0 to go back: ";
            cin >> id;
            if (cin.fail())
                System::InputFaliure(id, "write a suitable number ");
            if (System::isNumber(id)) {
                int ID = stoi(id);
                if (ID == 0) return;
                
                for (auto& s : Current_Team->getWeekSquad(weekNo)) {
                    
                        if (s.second== ID) {
                            displayPlayers(AllPlayers[s.first][s.second]);
                            cout << "Press anything to go back\n";
                            flag = true;
                            break;
                        }
                    
                    if (flag) break;
                }

                if (!flag)
                    cout << "Player does not exist\n";
                else break;
            }
            else {
                cout << "Please write a code consisting of only numbers\n";
            }
        }
        cin >> user_option;
    }
    
}
void System::displayFixtures(int week) {

    unordered_map<int, string>clubs = getClubsByID();
    //displayFixtures();
    string choice;
    string teamName;
    for (auto& match : AllFixtures[week]) {

        cout << match.first <<" - " << clubs[match.second->getHomeTeam()] << "\tVS\t" << clubs[match.second->getAwayTeam()] << endl;
    }
    
}
int System::ChooseFixture(bool&goBack) {
    string choice;
    displayFixtures(CurrGameWeek-1);
Enter_FixtureID:
    cout << "Enter Fixture ID";
    cin >> choice;
    if (cin.fail())
        InputFaliure(choice, "Please enter a valid Fixture ID");
    if (!isNumber(choice)) {
        cout << "Please enter Fixture ID in NUMBERS!!\n";
        goto Enter_FixtureID;
    }
    if (choice!="0" && AllFixtures[CurrGameWeek - 1].find(stoi(choice)) == AllFixtures[CurrGameWeek - 1].end())
    {
        cout << "Please enter a valid Fixture ID";
        goto Enter_FixtureID;
    }
    goBack = stoi(choice) == 0;
    return stoi(choice);
}
string System::ChooseFixtureClub(int fixtureID,bool& goBack) {
    string TeamName;
    unordered_map<int, string>clubs = getClubsByID();
    Fixture* CurrFixture = AllFixtures[CurrGameWeek - 1][fixtureID];
    cout << "Which team do you want to update\n";
    cout << "1 - " << clubs[CurrFixture->getHomeTeam()] << endl;
    cout << "2 - " << clubs[CurrFixture->getAwayTeam()] << endl;
    cout << "0 - To go back to Fixture Selection " << endl;
    cin.ignore();
    EnterHomeOrAway:
    cout << "Enter Team Name";
    getline(cin,TeamName);
    if (cin.fail())
        InputFaliure(TeamName, "Please enter a valid Team name");
    if (TeamName!="0"&& AllClubs.find(TeamName) == AllClubs.end()) {
        cout << "Enter Squad Name correctly\n";
        goto EnterHomeOrAway;
    }
    goBack = TeamName == "0";

    return TeamName;
}

Player* System::ChooseFixturePlayer(string teamName,bool &goBack)
{
    EnterPlayerId:
        string choice;
        AllClubs[teamName]->DisplaySquad();
        cout << "Enter player you want to edit his fixture data (OR 0 To go back and select the club)";
        cin >> choice;
	    if (cin.fail())
		    InputFaliure(choice, "Please enter a valid Team name");
	    if (!isNumber(choice)) {
		    cout << "Please enter player ID in NUMBERS!!\n";
			    goto EnterPlayerId;
	    }
    
        goBack = choice == "0";
    
    unordered_map<int, Player*> ClubSquad = AllClubs[teamName]->getSquad();
	if (choice !="0"&&ClubSquad.find(stoi(choice)) == ClubSquad.end()) {
		cout << "Enter Player ID Not found please enter it correctly\n";
		goto EnterPlayerId;
	}
    if (choice != "0") {
        string player_postion = ClubSquad[stoi(choice)]->getPosition();
        return AllPlayers[player_postion][stoi(choice)];
    }
}
unordered_map<int, string>System::getClubsByID() {
    unordered_map<int, string>clubs;
    for (auto& x : AllClubs) {
        clubs.insert({ x.second->getClubID(), x.first });
    }
    return clubs;
}

void System::writeFixtures(){

	fstream FixtureFile;
	FixtureFile.open("FixtureSave.csv", ios::out); //write data
	if (FixtureFile.is_open())
	{
		FixtureFile << "Gameweek,id,team_h_difficulty,homeTeam,homeScore,awayScore,awayTeam,team_a_difficulty,finished\n";
		for (auto& GameweekMatches : System::AllFixtures)
		{
            for(auto& match: GameweekMatches.second){

                FixtureFile << GameweekMatches.first << ","
                    << match.first << ","
                    << match.second->getHomeTeamDif() << ","
                    << match.second->getHomeTeam() << ","
                    << match.second->getHomescore() << ","
                    << match.second->getAwayscore() << ","
                    << match.second->getAwayTeam() << ","
                    << match.second->getAwayTeamDif() << ","
                    << match.second->IsFinished() << endl;
            }
            
                        
		}
		FixtureFile.close();
	}

}

void System::writeSystemconfig()
{
    fstream SystemFile;
    SystemFile.open("Config.txt", ios::out);

    if (SystemFile.is_open())
    {
        SystemFile << CurrGameWeek<<endl;
        SystemFile << "================StartDomains==================\n";
        for (auto& domain : domains)
            SystemFile << domain << endl;
        SystemFile << "================EndDomains==================\n";
    }

    SystemFile.close();
}
void System::ReadSystemconfig()
{
    vector<string> d;
    fstream Systemfile("Config.txt", ios::in);
    
    if (Systemfile.is_open())
    {
        string DataLine;
        while (Systemfile >> DataLine)
        {
            
            CurrGameWeek = stoi(DataLine);
            Systemfile >> DataLine;//"================StartDomains==================\n"
            Systemfile >> DataLine;
            while (DataLine != "================EndDomains==================") {
                d.push_back(DataLine);
                Systemfile >> DataLine;
            }
            domains = d;
        }
        Systemfile.close();
        
    }

}