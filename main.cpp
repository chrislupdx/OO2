//thiS is the implementation of main it likely talks to the game system
#include "sys.h"
#include <iostream>
int main()
{
    sys sys;
    std::cout << "create a player " << std::endl;
    char name[20];
    std::cin >> name;
    std::cin.ignore(100, '\n');

    player temp_player(name);

    sys.createPlayer(temp_player); //takes a player(makes it into a node) inserts into LLL
    //sys.createPlayer(name); 
    sys.displayPlayers(); 
    
    return 1;
}
