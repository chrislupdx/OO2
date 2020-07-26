//gamesList.cpp
#include "gamesList.h"
#include "cstddef"
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

//how do you want to add a node
//populate the node/w relevant game
//the work of deiciding the derived class is not here
int gamesL::add(game * newgame)
{
    //super boring cll insertion algorithmn
    if(!rear)
    {
        rear = new gameN(newgame);
    }
    return 1;
}
