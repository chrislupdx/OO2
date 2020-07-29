//playerN.cpp
#include "playerN.h"
#include <iostream>
//#include "player.h"

playerN::playerN()
{
    playerData = NULL;
}

playerN::playerN(player & playerToadd)
{
    playerData = new player(playerToadd);
    next = NULL; 
}

playerN::~playerN()
{
    playerData = NULL;
    next = NULL; 
} 


int playerN::addGame(game * gametoadd)
{
    //we are banking on the fact that playerData should have access to the cll
    return playerData->add(gametoadd);
}

int playerN::displayPData()
{
    return playerData->display();
}

playerN *& playerN::to_next() {return next; }

int playerN::displayN()
{
    if(playerData)
    {
        playerData->displayP();
    }
    else
    {
        std::cout << "no playerdata" << std::endl;
    }
    return 1;
}

//returns 0 if match
int playerN::compare(char * name_tocp)
{
    return playerData->compP(name_tocp);
}

