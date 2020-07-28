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
    //int retrievePlayer(player * player_tf); //takes a player, needs getter
    int retrievePlayer(char * player_name); //takes a char
    int retrievePlayer(playerN * head, char * name_tf);  //recursive call
    //delete a player by name
    int deletePlayer(char * name);
    int deletePlayer(playerN *& head, char * player_name);



    //int sortList();
    protected:
    playerN * head; //this is an LLL of players
    //playerN * sortH; //this is the sorted one
    int removeAll(playerN *& head);
    int removeAll();
    int displayPlayers(playerN *& head); //could we do this without a mfing reference
};
