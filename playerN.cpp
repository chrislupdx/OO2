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
    if(playerData->compP(name_tocp) == 0)
    {
        return 0;
    }
    return 1;
}

