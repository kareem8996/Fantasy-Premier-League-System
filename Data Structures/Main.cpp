#include <iostream>
#include "System.h"
int main()
{

    
    System::ReadSystemconfig();
    System::readClub();
    System::readPlayers();
    System::readUsers();
    System::readAdmins();
    System::readLeagues();
    System::readUserTeams();
    System::readFixtures();
    System::RunSys();
}