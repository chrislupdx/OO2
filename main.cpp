//thiS is the implementation of main it likely talks to the game system
#include "sys.h"
//#include "game.h"
//#include "gamesList.h"
#include <iostream>
int main()
{
    sys sys;
    bool done = false;
    bool done2 = false;
    //bool done3 = false; 
    while(done == false) //testing creating players
    {
        std::cout << "create a player " << std::endl;
        char name[20];
        std::cin >> name;
        std::cin.ignore(100, '\n');
        player temp_player(name);
        sys.createPlayer(temp_player); //takes a player(makes it into a node) inserts into LLL
        sys.displayPlayers(); 
        std::cout << "insesrt another? y/n " << std::endl;
        char yn;
        std::cin >> yn;
        std::cin.ignore(100,'\n');
        if(yn == 'n')
        {
            done = true;
        }
    };
    while(done2 == false) //testing retriving players
    {
        std::cout << "retrieving" << std::endl;
        std::cout << "enter name to retrieve " << std::endl;
        sys.displayPlayers(); 
        char name1[20];
        std::cin >>name1;
        std::cin.ignore(100,'\n');
        sys.retrievePlayer(name1);
        std::cout << "retrieve another? y/n " << std::endl;
        char yna;
        std::cin >> yna;
        std::cin.ignore(100,'\n');
        if(yna == 'n')
        {
            done2 = true;
        }
    }
    //while(done3 == false) //testing deleting players
    //{
    //    std::cout << "deleting" << std::endl;
    //    sys.displayPlayers();
    //    std::cout << "enter name to delete: " << std::endl;
    //    char name2[20];
    //    std::cin >>name2;
    //    std::cin.ignore(100,'\n');
    //    sys.deletePlayer(name2);
    //    sys.displayPlayers(); 
    //    std::cout << "delete another? y/n " << std::endl;
    //    char ynd;
    //    std::cin >> ynd;
    //    std::cin.ignore(100,'\n');
    //    if(ynd == 'n')
    //    {
    //        done3 = true;
    //    }
    //}

    std::cout << "Making games: Select a player" << std::endl;
    std::cout << "enter name to retrieve " << std::endl;
    sys.displayPlayers(); 
    char name1[20];
    std::cin >> name1;
    std::cin.ignore(100,'\n');

    bool done4 = false;
    while(done4 == false) //this loop is for making games for specific players
    {
        std::cout << "Select a game to create (1 rngGame /2 matching /3 blackjack)" << std::endl;
        std::cout << "Input choice : " << std::endl;
        int option; 
        std::cin >> option;
        std::cin.ignore(100,'\n');

        std::cout << "number your game " << std::endl;
        int nam;
        std::cin >> nam;
        std::cin.ignore(100,'\n');

        //this iso ur create game loop
        sys.addGame(name1, option, nam);  //its iether only writing over head instead of pushing into it
        sys.retrievePlayer(name1); //its' either only displaying one

        std::cout << "add another game to this player? y/n " << std::endl;
        char yndi;
        std::cin >> yndi;
        std::cin.ignore(100,'\n');
        if(yndi == 'n')
        {
            done4 = true;
        }
    } 

    bool done5 = false;
    std::cout << std::endl;
    std::cout << "Playing games: Select a player" << std::endl;
    while(done5 == false) //game playing loop for players (this is for getting wins for players
    {
        std::cout << "select a player " << std::endl;
        sys.displayPlayers(); 
        char name2[20];
        std::cin >> name2;
        std::cin.ignore(100,'\n');
        sys.retrievePlayer(name1);
        sys.playGame(name2);

        std::cout << "player another gamey/n " << std::endl;
        //display player win score
        char ugh;
        std::cin >> ugh;
        std::cin.ignore(100,'\n');
        if(ugh == 'n')
        {
            done4 = true;
        }


    }

    //play games 
    //cycle through games



    //bool done3 = false; 
    ////player * np = new player;
    ////gamesL * gamel = new gamesL;
    //while(done3 == false) //testing creating games
    //{
    //    std::cout << "create a game " << std::endl;
    //    std::cout << "what game would you like to create" << std::endl; 
    //    std::cout << "1: rngGame, 2: yum, 3: blackjack " <<std::endl;
    //    std::cout << "input choice : " << std::endl;
    //    int option; 
    //    std::cin >> option;
    //    std::cin.ignore(100,'\n');

    //    std::cout << "number your game " << std::endl;
    //    int nam;
    //    std::cin >> nam;
    //    std::cin.ignore(100,'\n');
    //    if(option == 1)
    //    {
    //        std::cout << "making a rngGame"<< std::endl;
    //        game * rng = new rngGame(nam);
    //        np->add(rng);
    //    }
    //    if(option == 2)
    //    {
    //        std::cout << "making a yum" << std::endl;
    //        game * y = new yum(nam);
    //        np->add(y);
    //    }
    //    if(option == 3)
    //    {
    //        std::cout << "making a blackjack" << std::endl;
    //        game * bj = new blackjack(nam);
    //        np->add(bj);
    //    }
    //    np->display();
    //    std::cout << "insesrt another? y/n " << std::endl;
    //    char yn;
    //    std::cin >> yn;
    //    std::cin.ignore(100,'\n');
    //    if(yn == 'n')
    //    {
    //        done3 = true;
    //    }
    //};
    //np->display();
    //bool done2 = false;
    //while(done2 == false) //testing deleting games 
    //{
    //  std::cout << "delete any games?" << std::endl;
    //  np->display();
    //  std::cout << "enter name to delete: " << std::endl;
    //  int name2;
    //  std::cin >>name2;
    //  std::cin.ignore(100,'\n');
    // 
    //  np->delGame(name2);
    //  np->display();
    //  
    //  std::cout << "delete another? y/n " << std::endl;
    //  char ynd;
    //  std::cin >> ynd;
    //  std::cin.ignore(100,'\n');
    //  if(ynd == 'n')
    //  {
    //      done2 = true;
    //  }
    //}


    //player game deletion loop
    //play loop those games
    //display list of players and score

    //game * ygam = new rngGame; //trying to upcast
    //ygam->play(); //this works

    //gameN * newNode = new gameN(ygam);
    //newNode->play();   //working on this one

    //gamel->add(rng);
    //gamel->display();
    //gamel->play(); 
    //bool done2 = false;
    //bool done3 = false;





    //bool done3 = false; //TEST FOR CLL LAYER
    //gamesL * gamel = new gamesL;
    //while(done3 == false) //testing creating games
    //{
    //    std::cout << "create a game " << std::endl;
    //    std::cout << "what game would you like to create" << std::endl; 
    //    std::cout << "1: rngGame, 2: yum, 3: blackjack " <<std::endl;
    //    std::cout << "input choice : " << std::endl;
    //    int option; 
    //    std::cin >> option;
    //    std::cin.ignore(100,'\n');
    //    std::cout << "number your game " << std::endl;
    //    int nam;
    //    std::cin >> nam;
    //    std::cin.ignore(100,'\n');
    //    if(option == 1)
    //    {
    //        std::cout << "making a rngGame"<< std::endl;
    //        game * rng = new rngGame(nam);
    //        gamel->add(rng);
    //    }
    //    if(option == 2)
    //    {
    //        std::cout << "making a yum" << std::endl;
    //        game * y = new yum(nam);
    //        gamel->add(y);
    //    }
    //    if(option == 3)
    //    {
    //        std::cout << "making a blackjack" << std::endl;
    //        game * bj = new blackjack(nam);
    //        gamel->add(bj);
    //    }
    //    gamel->display();
    //    std::cout << "insesrt another? y/n " << std::endl;
    //    char yn;
    //    std::cin >> yn;
    //    std::cin.ignore(100,'\n');
    //    if(yn == 'n')
    //    {
    //        done3 = true;
    //    }
    //};
    //gamel->display();
    //bool done2 = false;
    //while(done2 == false) //testing deleting games 
    //{
    //  std::cout << "delete any games?" << std::endl;
    //  gamel->display();
    //  std::cout << "enter name to delete: " << std::endl;
    //  int name2;
    //  std::cin >>name2;
    //  std::cin.ignore(100,'\n');
    // 
    //  gamel->delGame(name2);
    //  gamel->display();
    //  
    //  std::cout << "delete another? y/n " << std::endl;
    //  char ynd;
    //  std::cin >> ynd;
    //  std::cin.ignore(100,'\n');
    //  if(ynd == 'n')
    //  {
    //      done2 = true;
    //  }
    //}

    //if(typeid(*rng) == typeid(rngGame))
    //{
    //    std::cout << "this is an rnggame " << std::endl;
    //}

    //bool done = false;
    //bool done2 = false;
    //SYS tests


    return 1;
}
