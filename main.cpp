//thiS is the implementation of main it likely talks to the game system
#include "sys.h"
#include <iostream>
int main()
{
    sys sys;
    bool done = false;
    bool done2 = false;
    bool done3 = false; 
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
    while(done2 == false)
    {
        std::cout << "retrieving" << std::endl;
        char name1[20];
        std::cin >>name1;
        std::cin.ignore(100,'\n');
        sys.retrievePlayer(name1);

        std::cout << "retrieve another? y/n " << std::endl;
        char yna;
        std::cin >> yna;
        std::cin.ignore(100,'\n');
        if(yna == 'n')
        {
            done2 = true;
        }
    }
    while(done3 == false)
    {
        std::cout << "deleting" << std::endl;
        sys.displayPlayers();
        std::cout << "enter name to delete: " << std::endl;
        char name2[20];
        std::cin >>name2;
        std::cin.ignore(100,'\n');
        sys.deletePlayer(name2);
        sys.displayPlayers(); 

        std::cout << "delete another? y/n " << std::endl;

        char ynd;
        std::cin >> ynd;
        std::cin.ignore(100,'\n');
        if(ynd == 'n')
        {
            done3 = true;
        }
    }

    return 1;
}
