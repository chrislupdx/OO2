//this is the imeplmentation for the gameN.cpp
//gameN.cpp
#include "gameN.h"
#include <cstring>

gameN::gameN()
{
    next = NULL;
}

//figure out if you're consting
gameN::gameN(game * gameToadd, int choice) 
{
    //if(choice == 1)
    //{
    rngGame * r_test = dynamic_cast<rngGame*>(gameToadd);
    //}
    if(r_test) //check if the dynamic cast succeeded
    {
        aGame = new rngGame; //set the node's game to game type rng
    }
}

gameN::~gameN()
{
    next = NULL;
    aGame = NULL;
}

gameN *& gameN::to_next() {return next; } 
