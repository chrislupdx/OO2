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

//can we just touch the cll?
int playerN::play()
{
    return playerData->play();
}

int playerN::deleteGame(int option)
{
    return playerData->delGame(option);
}

int playerN::addGame(game * gametoadd)
{
    //we are banking on the fact that playerData should have access to the cll
    return playerData->add(gametoadd);
}

//displays the gamelist
int playerN::displayPGList()
{
    return playerData->display();
}

playerN *& playerN::to_next() {return next; }

//this is for displaying player games + other data
int playerN::displayN()
{
    if(playerData)
    {
        playerData->displayP();

        std::cout << "now printing games" << std::endl;
        playerData->display();
        std::cout << std::endl;
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

