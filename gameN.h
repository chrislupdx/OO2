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

        int play(); //does this actually work
        int setTag();
        int quit();
        int taketurn();
        int display();
        int gatherWin(); //returns wins as integers
        void set_next(gameN * next);
        game * r_game();
        int get_name();
        gameN *& to_next();    

    protected:
        int delGame(int * todel, gameN *& rear);
        gameN * next;
        game * aGame; //each gameN houses one instance of a game
};
