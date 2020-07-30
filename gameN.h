//this is the implementation of the game node file
//gameN.h
#include "game.h"
class gameN
{
    public:
        gameN(); //default constructor
        gameN(game * gametoadd); //RTTI shennanigans
        gameN(gameN * nodetcp);  //copy constructor
        ~gameN(); //default constructor

        int play(); //where is this used
        int display(); //calls the display playerdat member display function
        int gatherWin(); //returns wins as integers
        int get_name(); //gets name (names == numbers in this project)
        gameN *& to_next(); //gets next

    protected:
        int delGame(int * todel, gameN *& rear); //recursive call
        gameN * next; //the next pointer
        game * aGame; //each gameN houses one instance of a game
};
