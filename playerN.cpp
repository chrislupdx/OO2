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

int playerN::compW(playerN * Ptcp)
{
    if(playerData->compareWins(Ptcp->playerData) == 1)
    {
        return 1;
    }
    return 0;
}

//gets all the wins for one person
int playerN::updateWins()
{
    if(playerData)
    {
    return playerData->get_wins();
    }
    return 0;
}

int playerN::set_wins(int value)
{
    playerData->set_wins(value);
    return 1;
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
    return playerData->add(gametoadd);
}

//displays the gamelist
int playerN::displayPGList()
{
    return playerData->display();
}

playerN *& playerN::to_next() {return next; }

//this is for displaying One player's games + other data
int playerN::displayplayerstats()
{
    if(playerData)
    {
        //trying to aggregate wins through these
        playerData->displayPlayername(); 
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


