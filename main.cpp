//thiS is the implementation of main it likely talks to the game system
#include "sys.h"
//#include "game.h"
//#include "gamesList.h"
#include <iostream>
int main()
{
    sys sys;
    //gameN * node(1, rngGame); //might need to test
    //gamesL * gamel; //we're gonna want to write+test a fancy add function that takes prompts from user to decide how to build stuff

   
    game * rng;
    rng = new rngGame; //trying to upcast
    rng->play(); //this works;
   
    //where what does the player do
    //what state do we want to add games to gameN?


    //if(typeid(*rng) == typeid(rngGame))
    //{
    //    std::cout << "this is an rnggame " << std::endl;
    //}


    //bool done = false;
    //bool done2 = false;

    //SYS tests
    //while(done == false) //testing creating players in
    //{
    //    std::cout << "create a player " << std::endl;
    //    char name[20];
    //    std::cin >> name;
    //    std::cin.ignore(100, '\n');
    //    player temp_player(name);
    //    sys.createPlayer(temp_player); //takes a player(makes it into a node) inserts into LLL
    //    sys.displayPlayers(); 
    //    std::cout << "insesrt another? y/n " << std::endl;
    //    char yn;
    //    std::cin >> yn;
    //    std::cin.ignore(100,'\n');
    //    if(yn == 'n')
    //    {
    //        done = true;
    //    }
    //};
    //while(done2 == false) //testing retriving players
    //{
    //    std::cout << "retrieving" << std::endl;
    //    char name1[20];
    //    std::cin >>name1;
    //    std::cin.ignore(100,'\n');
    //    sys.retrievePlayer(name1);
    //    std::cout << "retrieve another? y/n " << std::endl;
    //    char yna;
    //    std::cin >> yna;
    //    std::cin.ignore(100,'\n');
    //    if(yna == 'n')
    //    {
    //        done2 = true;
    //    }
    //}
    //while(done3 == false) //testing deleting players
    //{
    //    std::cout << "deleting" << std::endl;
    //    sys.displayPlayers();
    //    std::cout << "enter name to delete: " << std::endl;
    //    char name2[20];
    //    std::cin >>name2;
    //    std::cin.ignore(100,'\n');
    //    sys.deletePlayer(name2);
    //    sys.displayPlayers(); 
    //    std::cout << "delete another? y/n " << std::endl;
    //    char ynd;
    //    std::cin >> ynd;
    //    std::cin.ignore(100,'\n');
    //    if(ynd == 'n')
    //    {
    //        done3 = true;
    //    }
    //}

    return 1;
}
