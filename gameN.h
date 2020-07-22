//this is the implementation of the game node file
//gameN.h

class gameN
{
    public:
    gameN();
    //param constructor that designates which game on creation int val 1/2/3
    ~gameN();
    //add a game into this

    //whatever game functions we have
    //including all derived functions :(
    
    protected:
    gameN * next;
    //game * aGame; //each gameN houses one instance of a game
};

