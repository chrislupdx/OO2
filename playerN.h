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
    int compW(playerN * Ptcp); //if calling class has more wins, return 1
   
    //which displays summed win scores?
    int displayplayerstats();
    int displayPGList(); //displays the gamelist

    int play(); //not sure what args this needs
    int addGame(game * gametoadd); //wrapper 
    int deleteGame(int option);
    int updateWins();
    int set_wins(int value);
    protected:
    player * playerData; //player is a derived class of gamesL
    playerN * next;
};
