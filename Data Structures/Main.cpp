#include <iostream>
#include "System.h"
int main()
{

    
    /*System::RunSys();*/
    System::readClub();
    System::readPlayers();
    for (auto& it : System::AllClubs) {
        // Do stuff
        cout << it.first<<"\t";
        cout << it.second->getLeaguePoints() << endl;
        for (auto& player : it.second->getSquad()) {
            cout << player.second->getFullname() << endl;
        }
    }
    System::RunSys();
    
}