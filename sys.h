//this is the implementation of the .h for the game system
//chris lu
//program 2
//cs202
//sys.h
#include "playerN.h" 
#include <cstddef>
class sys
{
    public:
    sys(); //default constructor
    ~sys(); //default destructor
    int createPlayer(player name); //hopefully calls player's parameterized cosntructor
    
    int insertsortP(playerN * sortedPlayer, playerN *& emptylist); //insert for sort

    int displaySorted(); //displays sorted

    int displayPlayers(); //displays players
    
    int displayPData(char * player_name); //display player data
    
    int retrievePlayer(char * player_name); //retrieve player
    
    int addGame(char * player_name, int option, int nam);  //add a game
    
    int deletePlayer(char * name); //delete player
   
    int deleteGame(char * name, int option); //delete game wrapper
    
    int playGame(char * name); //plays the top game of that person, then rotates    

    int sortList(); //sort wrapper
    
    int updateWins();  //sort wins

    int removeAll(); //removes all players
  
    int removesh(); //removes the scoreboard
    protected:

    int addGame(playerN * head, char * name_tf, game *& gameta); //this call passes the player by re
    int deletePlayer(playerN *& head, char * player_name); //recursive delete player
    int sortList(playerN *& empty, playerN * tocopy); //goes through the list of players and inserting them in sorted order to sortH (recursively)
    int retrievePlayer(playerN * head, char * name_tf);  //recursive call
    int insertPlayerN(player player_toadd, playerN *& head); //recursive insert
    int displaySorted(playerN *& head); //recursive display
    int updateWins(playerN *& head); //recursive update wins
    int playGame(playerN * head, char * player_name);  //recurisve play games
    int deleteGame(playerN * head, char * nametf, int option); //recursive delete games
    int addGame(char * player_name, game * gametoa);  //add game
    int displayPlayers(playerN *& head); //could we do this without a mfing reference
    int removeAll(playerN *& head); //recursive remove all
    
    playerN * head; //this is an LLL of players
    playerN * sortH; //this is the sorted one
};
