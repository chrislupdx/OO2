//this is the implementation fo the game system
#include "playerN.h" 
#include <cstddef>
class sys
{
    public:
    sys();
    ~sys();
    int createPlayer(player name); //hopefully calls player's parameterized cosntructor
    int insertPlayerN(player player_toadd, playerN *& head);
    int displayPlayers();
    int displayPData(char * player_name);
    int retrievePlayer(char * player_name);
    int retrievePlayer(playerN * head, char * name_tf);  //recursive call
    int addGame(char * player_name, int option, int nam); 
    int addGame(playerN * head, char * name_tf, game *& gameta); //this call passes the player by re
    int deletePlayer(char * name);
    int deletePlayer(playerN *& head, char * player_name);
    int playGame(char * name); //plays the top game of that person, then rotates    
    int deleteGame(char * name, int option);
    int sortList(playerN *& empty, playerN *& tocp); //goes through the list of players and inserting them in sorted order to sortH
    int displaySorted(); 
    int updateWins();
    protected:
    int updateWins(playerN *& head);
    int playGame(playerN * head, char * player_name); 
    int deleteGame(playerN * head, char * nametf, int option);
    int addGame(char * player_name, game * gametoa); 
    //sort vs copysort
    //have a function that does a sort
    //(set a pointer to head(oldlist)), then set head to null, rebuilding head and temp
    playerN * head; //this is an LLL of players
    playerN * sortH; //this is the sorted one
    int removeAll(playerN *& head);
    int removeAll();
    int displayPlayers(playerN *& head); //could we do this without a mfing reference
};
