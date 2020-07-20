//this is the implementation of player.h
#include "player.h"
#include <iostream>

player::player()
{
    name = NULL; 
}

player::player(char * nametoadd )
{
   name = nametoadd; 
}

player::~player()
{
    name = NULL; 
}

//deepcopies the arg into the member vlas
int player::copyP(player * player_tocopy)
{
    name = new char[strlen(player_tocopy->name) + 1];
    strcpy(name, player_tocopy->name);

    
    return 1;
}

//display
int player::displayP()
{
    std::cout << "Player " << name << std::endl;

    return 1;
}

//delete?

//insert
