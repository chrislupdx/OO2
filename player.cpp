//this is the implementation of player.h
#include "player.h"
#include <iostream>

player::player()
{
    name = NULL; 
}

player::player(char * nametoadd )
{
    name = NULL;
    name = new char[strlen(nametoadd) + 1];
    strcpy(name, nametoadd);
}

player::player(const player & player_toadd)
{
    if(player_toadd.name)
    {
    name = new char[strlen(player_toadd.name) + 1];
    strcpy(name, player_toadd.name);
    }
    else
    {
    name = NULL; 
    }
}

player::~player()
{
    name = NULL; 
}

//display
int player::displayP()
{
    if(name)
    {    
        std::cout << "Player " << name << std::endl;
    }
    else
    {
        std::cout << "no name" << std::endl;
    }

    return 1;
}

//delete?

//insert
