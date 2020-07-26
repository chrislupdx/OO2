//gamesList.cpp
#include "gamesList.h"
#include "cstddef"
#include <iostream>
gamesL::gamesL()
{
    wins = 0;
    rear = NULL; 
}

gamesL::~gamesL()
{
    wins = 0;
    if(rear)
    {
        removeAll();
    }
}

int gamesL::removeAll()
{
    return 0;
}

int gamesL::add(game * newgame)
{
    //super boring cll insertion algorithmn
    if(!rear)
    {
        std::cout << "!rear: input a game type (1,2,3)" << std::endl;
        int num;
        std::cin >> num;
        std::cin.ignore(100,'\n');
        rear = new gameN(newgame, num); //the constructor does the work
    }
    return 1;
}
