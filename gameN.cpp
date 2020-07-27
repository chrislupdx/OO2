//this is the imeplmentation for the gameN.cpp
//gameN.cpp
#include "gameN.h"
#include <cstring>
gameN::gameN()
{
    next = NULL;
}
//figure out if you're consting
gameN::gameN(game * gameToadd) 
{
    rngGame * r_test = dynamic_cast<rngGame*>(gameToadd);
    if(r_test) //check if the dynamic cast succeeded
    {
        aGame = new rngGame; //set the node's game to game type rng
        aGame->copy(gameToadd);  //thoughts on a dynamically bound copy 
    }

    yum * y_test = dynamic_cast<yum*>(gameToadd);
    if(y_test)
    {
        aGame = new yum;
        aGame->copy(gameToadd);
    }

    blackjack *b_test = dynamic_cast<blackjack*>(gameToadd);
    if(b_test)
    {
        aGame = new blackjack;
        aGame->copy(gameToadd);
    }
    
    next = NULL;
}

//i hope to god this copy constructor works with dynamic binding
gameN::gameN(gameN * nodetcp)
{
    next = NULL; 
    //aGame = new game(nodetcp->r_game());// ugh this getter doesn't work
}

gameN::~gameN()
{
    next = NULL;
    aGame = NULL;
}

int gameN::play()
{
    return aGame->play(); //well, let's see if it can dynamically bind right
}

int gameN::display()
{
    return aGame->display();
}

//gameN *& gameN::to_next() {return next; } 
gameN * gameN::to_next() {return next; }
void gameN::set_next(gameN * next) {this->next = next;}
game * gameN::r_game() {return aGame; }
