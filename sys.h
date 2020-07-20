//this is the implementation fo the game system
#include "playerN.h"
#include <cstddef>
class sys
{
    public:
    sys();
    ~sys();
        
    //create is insert
    int createPlayer(player name); //hopefully calls player's parameterized cosntructor
    
    //inserts a plyaer into a LLL
    int insertPlayerN(player player_toadd, playerN *& head);

    //displayPlayerList
    int displayPlayers();

    //retrieve a player by name
    //int retreiveP(char * name);
 
    //delete a player by name
    //int deleteP(char * name);
    
    protected:
    playerN * head; //this is an LLL
    int removeAll(playerN *& head);
    int removeAll();
    int displayPlayers(playerN *& head); //could we do this without a mfing reference
};
