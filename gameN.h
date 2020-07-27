//this is the implementation of the game node file
//gameN.h
#include "game.h"

class gameN
{
    public:
    gameN();
    gameN(game * gametoadd); //RTTI shennanigans
    gameN(gameN * nodetcp);
    ~gameN();
    //add a game into this

    int play(); //does this actually work
    int setTag();
    int quit();
    int taketurn();
    int display();
    int gatherWin(); //checks if win rreturn 1 else return 0

    //int copyGame();
    //copy constructor?
   
    //int gameN *& get_winData();
    gameN * to_next();    
    void set_next(gameN * next);
    game * r_game();
    protected:
    gameN * next;
    game * aGame; //each gameN houses one instance of a game
};
