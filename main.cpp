//thiS is the implementation of main it likely talks to the game system
#include "sys.h"
#include <iostream>
int main()
{
    //sys sys;
    std::cout << "create a player " << std::endl;
    char name[20];
    std::cin >> name;
    std::cin.ignore(100, '\n');
    
    //Player 
    player p(name);
    //p.displayP();
  
   // playerN pN(p);
   // pN.displayN();

    //sys.createPlayer(name); 
    //sys.displayPlayers(); 
    
    return 1;
}
