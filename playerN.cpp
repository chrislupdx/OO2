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
