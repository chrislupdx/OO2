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
    int insertsortP(playerN * sortedPlayer, playerN *& emptylist);
    //insertPlayerN(sortedPlayer, empty);  //eol insetion
    
    int displaySorted();
    int displaySorted(playerN *& head);

    //note: if playerN and player are switched at any point night of 7/29: 02 dep is terrible

    int displayPlayers();
    int displayPData(char * player_name);
    
    int retrievePlayer(char * player_name);
    int retrievePlayer(playerN * head, char * name_tf);  //recursive call
    
    int addGame(char * player_name, int option, int nam); 
    int addGame(playerN * head, char * name_tf, game *& gameta); //this call passes the player by re
    
    int deletePlayer(char * name);
    int deletePlayer(playerN *& head, char * player_name);
    int deleteGame(char * name, int option);
    
    int playGame(char * name); //plays the top game of that person, then rotates    

    int sortList();
    int sortList(playerN *& empty, playerN * tocopy); //goes through the list of players and inserting them in sorted order to sortH
    
    int updateWins();
   
    protected:
    int updateWins(playerN *& head);
    int playGame(playerN * head, char * player_name); 
    int deleteGame(playerN * head, char * nametf, int option);
    int addGame(char * player_name, game * gametoa); 
   
    //have a function that does a sort
    //(set a pointer to head(oldlist)), then set head to null, rebuilding head and temp
    playerN * head; //this is an LLL of players
    playerN * sortH; //this is the sorted one
    int removeAll(playerN *& head);
    int removeAll();
    int displayPlayers(playerN *& head); //could we do this without a mfing reference
};
