//thiS is the implementation of main it likely talks to the game system
#include "sys.h"
#include <iostream>
int main()
{
    sys sys;
    bool done = false;

    while(done == false)
    {
    std::cout << "create a player " << std::endl;
    char name[20];
    std::cin >> name;
    std::cin.ignore(100, '\n');

    player temp_player(name);

    sys.createPlayer(temp_player); //takes a player(makes it into a node) inserts into LLL
    sys.displayPlayers(); 

    std::cout << "insesrt another? y/n " << std::endl;
    char yn;
    std::cin >> yn;
    std::cin.ignore(100,'\n');
    if(yn == 'n')
    {
        done = true;
    }
    };




    return 1;
}
