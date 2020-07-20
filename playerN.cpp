//playerN.cpp
#include "playerN.h"
//#include "player.h"

playerN::playerN()
{
    playerData = NULL;
}

playerN::playerN(playerN * playerToadd)
{
    playerData->copyP(playerToadd->playerData);
    next = NULL;
}

playerN::playerN(player * playerToadd)
{
    playerData->copyP(playerToadd);
    next = NULL; 
}

playerN::~playerN()
{
    playerData = NULL;
    next = NULL; 
} 

playerN *& playerN::to_next() {return next; }

//just displays the internal
int playerN::displayN()
{
    if(playerData)
    {
        playerData->displayP();
    }
    return 1;
}
