#include "System.h"
#include "iostream"
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
using namespace std;

string const System::choice_error = "\tPlease enter your choice here --->\t";
vector<string> const System::domains = { "gmail.com","outlook.com","yahoo.com","hotmail.com","icloud.com","cis.asu.edu.eg" };
string  System::startchoice="",
        System:: registerChoice = "",
        System::loginChoice = "",
        System::menuChoice = "";
User System::CurrUser;
Admin System::CurrAdmin;
vector<User> System::Allusers;
vector<Admin> System::AllAdmins;
unordered_map<string, Club> System::AllClubs; //name,club object
unordered_map < string, unordered_map<int, Player*>> System::AllPlayers;
void System::printSeprator() {
    cout << "-------------------------------------------------------------------------------------\n";
    cout << "\033[2J\033[1;1H";
}

void System::printSeprator_for_errors() {
    cout << "-------------------------------------------------------------------------------------\n";

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

bool System::Check_Database(string username) {
    for (int i = 0; i < Allusers.size(); i++) {

        if (Allusers[i].getUsername() == username) {
            return false;
        }
    }
    /*for (int i = 0; i<AllAdmins.size(); i++) {
        if (AllAdmins[i].username == username) {
            return false;
        }
    }*/
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

    for (int i = 0; i < Allusers.size(); i++) {
        if (Allusers[i].getPhoneNumber() == phone) {
            cout << "This Phone already used before";
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



bool System::Check_EmailDatabase(string Email) {
    for (int i = 0; i < Allusers.size(); i++) {
        if (Allusers[i].getEmail() == Email) {
            cout << "This email is already used by another user.";
            return false;
        }
    }
    return true;
}
bool System::Check_Email(string& Email) {
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
                cout << "Enter Your email";
                cin >> Email;
                if (cin.fail())
                    InputFaliure(Email, "Please enter Email:");
                vEmail = Check_Email(Email);
            } while (!vEmail);
            cout << "Enter your team name";
            cin >> TeamName;
            if (cin.fail())
                InputFaliure(TeamName, "Please Enter your team name");
            User user = { Name, Email, Username, Password, Phone, 0, 0, TeamName, leagues };
            Allusers.push_back(user);
            CurrUser = Allusers.back();
        }
        else {
            cout << "this username is already taken, Please enter another username.\n";
        }
        cout << "\t\tThank You for registering on our system!\n";
        printSeprator();
        loginChoice = "2";
        startchoice = "1";
    } while (vUsername != true);
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
                cout << "Enter Your email";
                cin >> Email;
                if (cin.fail())
                    InputFaliure(Email, "Please enter Email:");
                vEmail = Check_Email(Email);
            } while (!vEmail);
            Admin admin = { Name, Email, Username, Password, Phone};
            AllAdmins.push_back(admin);
            CurrAdmin = AllAdmins.back();
        }
        else {
            cout << "this username is already taken, Please enter another username.\n";
        }
        cout << "\t\tThank You for registering on our system!\n";
        printSeprator();
        loginChoice = "1";
        startchoice = "1";
    } while (vUsername != true);
}

bool System::userLogin(vector<User>allusers, string attemptedUsername, string attemptedPassword) {
    for (int i = 0; i < allusers.size(); i++) {
        if (allusers[i].getUsername() == attemptedUsername) {
            if (allusers[i].getPassword() == attemptedPassword) {
                CurrUser = allusers[i];
                return true;
            }
        }
    }
    return false;
}
bool System::AdminLogin(vector<Admin>AllAdmins, string attemptedUsername, string attemptedPassword) {
    for (int i = 0; i < AllAdmins.size(); i++) {
        if (AllAdmins[i].getUsername() == attemptedUsername) {
            if (AllAdmins[i].getPassword() == attemptedPassword) {
                CurrAdmin = AllAdmins[i];
                return true;
            }
        }
    }
    return false;
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

        cout << "Enter password: \n";
        
        Pass_Encode(attemptedPassword);
        if (userLogin(Allusers, attemptedUserName, attemptedPassword)) {
            loginChoice = '2';
            tAgain = "N";
        }
        else if (AdminLogin(AllAdmins, attemptedUserName, attemptedPassword))
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
            } while (tAgain != "Y" || tAgain != "y" || tAgain != "N" || tAgain != "n");

        }
        printSeprator();

    } while (tAgain!= "N" && tAgain != "n");
    printSeprator();
}

void System::printUserMenu() {
    string Logout_choice = "";
    string Quit_choice = "";
    do{

    cout << "Hello " << CurrUser.getName();
    cout << "\t\tWhat would you like to do ??\n"
        << "\t\t1 - Manage Squad\n"
        << "\t\t2 - Create League\n"
        << "\t\t3 - Join League\n"
        << "\t\t4 - Change Account Info\n"
        << "\t\t5 - To Logout\n"
        << "\t\t6 - To Quit the System\n";
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
        ManageSqaudMenu(CurrUser.getSquad());
        printSeprator();
        break;
    case '2':

        Sleep(5000);
        printSeprator();
        break;
    case '3':

        Sleep(5000);
        printSeprator();
        break;
    case '4':

        Sleep(3000);
        printSeprator();
        break;
    case '5':

        do {
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
    case '6':
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
void System::printAdminMenu() {
    cout << "Hello " << CurrAdmin.getName();
    cin >> loginChoice;
}


void System::RunSys() {
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
                    if (Allusers.size() != 0||AllAdmins.size()!=0) {
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
                    -----------------------
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
                    /*writeAllPatients(allPatients);
                    writeAllDiseases(allDiseases);
                    writeAllDoctors(allDoctors);*/
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
            /*writeAllPatients(allPatients);
            writeAllDiseases(allDiseases);
            writeAllDoctors(allDoctors);*/
            exit(0);

        }
        //This is a default answer if the user enter a strange number
        else {
            startchoice = "";
            printSeprator_for_errors();
            cout << "\t\tSorry this is an invalid choice please enter again.\n";
            Sleep(3000);
            printSeprator();
        }
    } while (true);

}

void System::ManageSqaudMenu(User_Team& c) {
    
    if (c.getTotalPlayers() != 0) {
        cout << "\t\tWhat would you like to do ??\n"
            << "\t\t1 - Manage Squad\n"
            << "\t\t2 - Create League\n"
            << "\t\t3 - Join League\n"
            << "\t\t4 - Change Account Info\n"
            << "\t\t7 - To Logout\n"
            << "\t\t8 - To Quit the System\n";
    }
    else {
        c.pickSquad();
    }
    

}
void System::displayPlayers(Player*p, bool flag=false, string delim="\n") {
    /// <summary>
    /// displays only one player
    /// </summary>
    /// <param name="p">player obkect</param>
    /// <param name="flag">This is used so we can use the same code twice</param>
    /// <param name="delim"> the delimiter can either be enter or tab</param>
    System::printSeprator_for_errors();
    cout << "ID: " << p->getID() << delim;
    cout << "Name: " << p->getFullname() << delim;
    cout << "Club: " << p->getClub() << delim;
    cout << "Price: " << (float)p->getPrice()/10 << delim;
    cout << "Current Week Points: " << p->getPlayer_History().back().getTotal_points_gameweek() << delim;
    cout << "Total Points: " << p->getTotalPoints() << delim;
    if (!flag) {
        cout << "Position: " << p->getPosition() << delim;
        cout << "Status: " << p->getStatus() << delim;
        cout << "Current Week Goals: " << p->getPlayer_History().back().getGoals_scored_gameweek() << delim;
        cout << "Total Goals: " << p->getTotalGoals() << delim;
        cout << "Current Week Assists: " << p->getPlayer_History().back().getAssists_gameweek() << delim;
        cout << "Total Assists: " << p->getTotalAssists() << delim;
        cout << "Current Week Yellow Cards: " << p->getPlayer_History().back().getYellow_cards_gameweek() << delim;
        cout << "Total Yellow Cards: " << p->getTotalYellowCards() << delim;
        cout << "Current Week Red Card: " << p->getPlayer_History().back().getRed_cards_gameweek() << delim;
        cout << "Total Red Cards: " << p->getTotalRedCards() <<endl;
        
 

            if (p->getPosition()=="MID") {
                Midfielder* m = (Midfielder*)p;
                cout << "Current Week Cleansheet: " << m->getPlayer_History().back().getClean_sheets_gameweek() << delim;
                cout << "Total Cleansheet: " << m->getTotalCleanSheets() << delim;
            } 
            else if (p->getPosition() == "DEF") {
                Defender* d =(Defender*)(p);
                cout << "Current Week Cleansheet: " << d->getPlayer_History().back().getClean_sheets_gameweek() << delim;
                cout << "Total Cleansheet: " << d->getTotalCleanSheets() <<endl;
            }
            else if (p->getPosition() == "GKP") {
                GoalKeeper* g =(GoalKeeper*)p;
                cout << "Current Week Saves: " << g->getPlayer_History().back().getSaves_gameweek() << delim;
                cout << "Total Saves: " << g->getTotalSaves()<<delim;
                cout << "Current Week Cleansheet: " << g->getPlayer_History().back().getClean_sheets_gameweek() << delim;
                cout << "Total Cleansheet: " <<g->getTotalCleanSheets() <<endl;
            }
            
        
    }
    System::printSeprator_for_errors();
}
void System::displayPlayers(string position) {

    /// <summary>
    /// Displays all players who play in a certain position
    /// </summary>
    /// <param name="position"></param>
    for (auto& it : System::AllPlayers[position]) {
        displayPlayers(it.second, true, "\t||\t");
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
    fstream file("D:\\Uni Projects\\Data Structure\\Data\\total_players.csv", ios::in);
    int row_counter = -1;
    Player* p=nullptr;
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
                            stoi(row["value"].at(row_counter)),
                            row["position"].at(row_counter),
                            row["status"].at(row_counter),
                            stoi(row["total_clean_sheets"].at(row_counter)));
                      
                        
                        m->updatePlayer_History({
                            row["status"].at(row_counter),
                            stoi(row["value"].at(row_counter)),
                            stoi(row["gameweek_points"].at(row_counter)),
                            stoi(row["gameweek_goals"].at(row_counter)),
                            stoi(row["gameweek_assists"].at(row_counter)),
                            stoi(row["gameweek_clean_sheets"].at(row_counter)),
                            stoi(row["gameweek_red_cards"].at(row_counter)),
                            stoi(row["gameweek_yellow_cards"].at(row_counter)),
                            stoi(row["gameweek_saves"].at(row_counter))
                            });
                    
                        p = m;
                    }
                    else if (row["position"].at(row_counter) == "DEF") {
                        Defender* d = new Defender(stoi(row["id_player"].at(row_counter)),
                            row["first_name"].at(row_counter) + " " + row["second_name"].at(row_counter),
                            row["name"].at(row_counter),
                            stoi(row["gameweek_points"].at(row_counter)),
                            stoi(row["value"].at(row_counter)),
                            row["position"].at(row_counter),
                            row["status"].at(row_counter),
                            stoi(row["total_clean_sheets"].at(row_counter)));


                        d->updatePlayer_History({
                            row["status"].at(row_counter),
                            stoi(row["value"].at(row_counter)),
                            stoi(row["gameweek_points"].at(row_counter)),
                            stoi(row["gameweek_goals"].at(row_counter)),
                            stoi(row["gameweek_assists"].at(row_counter)),
                            stoi(row["gameweek_clean_sheets"].at(row_counter)),
                            stoi(row["gameweek_red_cards"].at(row_counter)),
                            stoi(row["gameweek_yellow_cards"].at(row_counter)),
                            stoi(row["gameweek_saves"].at(row_counter))
                            });
                        
                        p = d;
                    }
                    else if (row["position"].at(row_counter) == "FWD") {
                        Attacker* a = new Attacker(
                            stoi(row["id_player"].at(row_counter)),
                            row["first_name"].at(row_counter) + " " + row["second_name"].at(row_counter),
                            row["name"].at(row_counter), stoi(row["gameweek_points"].at(row_counter)), 
                            stoi(row["value"].at(row_counter)), row["position"].at(row_counter),
                            row["status"].at(row_counter));

                        a->updatePlayer_History({
                            row["status"].at(row_counter),
                            stoi(row["value"].at(row_counter)),
                            stoi(row["gameweek_points"].at(row_counter)),
                            stoi(row["gameweek_goals"].at(row_counter)),
                            stoi(row["gameweek_assists"].at(row_counter)),
                            stoi(row["gameweek_clean_sheets"].at(row_counter)),
                            stoi(row["gameweek_red_cards"].at(row_counter)),
                            stoi(row["gameweek_yellow_cards"].at(row_counter)),
                            stoi(row["gameweek_saves"].at(row_counter))
                            });
                        p = a;
                    }
                    else if (row["position"].at(row_counter) == "GKP") {
                        GoalKeeper* g = new GoalKeeper(
                            stoi(row["id_player"].at(row_counter)),
                            row["first_name"].at(row_counter) + " " + row["second_name"].at(row_counter),
                            row["name"].at(row_counter), stoi(row["gameweek_points"].at(row_counter)), 
                            stoi(row["value"].at(row_counter)), row["position"].at(row_counter), 
                            row["status"].at(row_counter), stoi(row["total_saves"].at(row_counter)),  
                            stoi(row["total_clean_sheets"].at(row_counter)));

                        g->updatePlayer_History({
                           row["status"].at(row_counter),
                           stoi(row["value"].at(row_counter)),
                           stoi(row["gameweek_points"].at(row_counter)),
                           stoi(row["gameweek_goals"].at(row_counter)),
                           stoi(row["gameweek_assists"].at(row_counter)),
                           stoi(row["gameweek_clean_sheets"].at(row_counter)),
                           stoi(row["gameweek_red_cards"].at(row_counter)),
                           stoi(row["gameweek_yellow_cards"].at(row_counter)),
                           stoi(row["gameweek_saves"].at(row_counter))
                            });
                        p = g;
                    }
                    p->setTotalPoints(stoi(row["total_points"].at(row_counter)));
                    p->setTotalGoals(stoi(row["total_goals"].at(row_counter)));
                    p->setTotalAssists(stoi(row["total_assists"].at(row_counter)));
                    p->setTotalYellowCards(stoi(row["total_yellow_cards"].at(row_counter)));
                    p->setTotalRedCards(stoi(row["total_red_cards"].at(row_counter)));
                    System::AllPlayers[p->getPosition()].insert({ p->getID(),p });
                }
                else {//updating

                    p->updatePlayer_History({
                            row["status"].at(row_counter),
                            stoi(row["value"].at(row_counter)),
                            stoi(row["gameweek_points"].at(row_counter)),
                            stoi(row["gameweek_goals"].at(row_counter)),
                            stoi(row["gameweek_assists"].at(row_counter)),
                            stoi(row["gameweek_clean_sheets"].at(row_counter)),
                            stoi(row["gameweek_red_cards"].at(row_counter)),
                            stoi(row["gameweek_yellow_cards"].at(row_counter)),
                            stoi(row["gameweek_saves"].at(row_counter))
                        });
                }
            }
            row_counter++;
        }
    }
        cout << "Reading successful\n";
}
