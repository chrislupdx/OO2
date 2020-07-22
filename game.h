//game.h

//This should be virtual
class game
{
    public:
    //parameteriazed constructor ?
    game();
    virtual ~game();
    
    virtual int play()=0; //pure virtual, can only make pointers via dynamic binding

    virtual int quit(); //

    //virtual int taketurn(); //check if we realllly want to virtualize it
    virtual int setTag();

    //oh yeah why is pure virtual a thing 
    //if(we need overloaded operators) implement here
    //derived_type * new_ptr = <dynamic_cast><derived_type *> (old_ptr);

    protected:
    //char * tag;
    //int * hScore;
    //int *pScore
};

class rngGame : public game
{
    public:
        rnGame();
        //~game(); //how do we actually implement this properly
        //~rngGame(); //but that's not an identical signature...
        int play();
        int quit();
        int taketurn();
        int setTag();
        //int static_cast<type*>pickCard();

    private:
       // int * userDeck; //an array of 3 integers
}
