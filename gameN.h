//this is the implementation of the game node file
//gameN.h
#include "game.h"

class gameN
{
    public:
    gameN();
    //paramterized constructor uses dynamic binding to produce either game 1/2/3
    ~gameN();
    gameN(game * gametoadd); //RTTI shennanigans
    //add a game into this

    int play();
    int setTag();
    int quit();
    int taketurn();
   
    //int gameN *& get_winData();
    gameN *& to_next();    
    protected:
    gameN * next;
    game * aGame; //each gameN houses one instance of a game
};
