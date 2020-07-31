//playerN.cpp
//chris lu
//cs202
//thsi is the implemntation of the player node
#include "playerN.h"
#include <iostream>
//#include "player.h"

//default constructor
playerN::playerN()
{
    playerData = NULL;
}

//copy constructor
playerN::playerN(player & playerToadd)
{
    playerData = new player(playerToadd);
    next = NULL; 
}

int playerN::haswins()
{
    if(playerData->has_wins() == 1)
    {
    return 1;
    }
    return 0;
}

//default destructor
playerN::~playerN()
{
    playerData = NULL;
    next = NULL; 
} 

//copmare function
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
    if(playerData->has_wins() == 1)//if we have valuesgreater than zero
    {
    return playerData->get_wins();
    }
    return 0;
}


//sets wins
int playerN::set_wins(int value)
{
    playerData->set_wins(value);
    return 1;
}

//calls the player data node play function
int playerN::play()
{
    return playerData->play();
}

//wrapper for a delete function
int playerN::deleteGame(int option)
{
    return playerData->delGame(option);
}

//wrapper for adding a game
int playerN::addGame(game * gametoadd)
{
    return playerData->add(gametoadd);
}

//displays the gamelist
int playerN::displayPGList()
{
    return playerData->display();
}

//to next
playerN *& playerN::to_next() {return next; }

//this is for displaying One player's games + other data
int playerN::displayplayerstats()
{
    if(playerData)
    {
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
