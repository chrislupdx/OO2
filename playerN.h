//playerN.h
//chris Lu
//program 2
//this is a node  for players
//cs202
#include "gamesList.h"
class playerN 
{
    public:
    playerN(); //default constructor
    playerN(playerN & playerToadd); //takes a NODE
    playerN(player & playerToadd); //takes a PLAYER 
    playerN *& to_next();  //to next
    ~playerN(); //default destructor
    int copyN(playerN * playerN_tocopy); //copy function
    int compare(char * name_tocp); //compare function
    int compW(playerN * Ptcp); //if calling class has more wins, return 1

    int haswins();  //returns 1 if has more than 1 win
    int displayplayerstats(); //display function 
    int displayPGList(); //displays the gamelist
    int play(); //not sure what args this needs
    int addGame(game * gametoadd); //add wrapper
    int deleteGame(int option); //delete wrapper
    int updateWins(); //updates wins
    int set_wins(int value); //setter
    protected:
    player * playerData; //player is a derived class of gamesL
    playerN * next; 
};
