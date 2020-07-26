//this is the imeplmentation for the gameN.cpp
//gameN.cpp
#include "gameN.h"
#include <cstring>

gameN::gameN()
{
    next = NULL;
}

gameN::gameN(game * gameToadd)
{
    //check how else blocks play with RTTI
    rngGame * r_test = dynamic_cast<rngGame*>(gameToadd);
    if(r_test)
    {
        aGame = new rngGame;
    }
}

gameN::~gameN()
{
    next = NULL;
    aGame = NULL;
}

gameN *& gameN::to_next() {return next; } 
