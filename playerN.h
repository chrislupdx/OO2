//playerN.h
//this is a node 
#include "gamesList.h"

//#include "player.h"

class playerN 
{
    public:
    playerN();
    playerN(playerN & playerToadd); //takes a NODE
    playerN(player & playerToadd); //takes a PLAYER 
    playerN *& to_next(); 
    ~playerN();
    int copyN(playerN * playerN_tocopy);
    int compare(char * name_tocp);

    int displayN();
    //setplayerN();
    //playgame
    //displaywins

    protected:
    player * playerData; //player is a derived class of gamesL
    playerN * next;
};
