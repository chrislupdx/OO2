//playerN.h
//this is a node 
#include "player.h"

class playerN
{
    public:
    playerN();
    playerN(playerN * playerToadd); //takes a NODE
    playerN(player * playerToadd); //takes a PLAYER 
    playerN *& to_next(); 
    ~playerN();
    int copyN(playerN * playerN_tocopy);
   
    int displayN();
    //delete?

    protected:
    player * playerData;
    playerN * next;
};
