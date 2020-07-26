//game.h
//This should be virtual
class game
{
    public:
    //parameteriazed constructor ?
    game();
    virtual ~game();
    virtual int play()=0; //pure virtual, can only make pointers via dynamic binding
    virtual int quit()=0;
    virtual int taketurn(); //check if we realllly want to virtualize it
    virtual int setTag(char * name)=0;
    //if(we need overloaded operators) implement here
    //derived_type * new_ptr = <dynamic_cast><derived_type *> (old_ptr);
    //getWinData();
    protected:
    char * tag;
    bool win;
};

class rngGame : public game
{
    public:
        rngGame();
        ~rngGame(); //but that's not an identical signature...does this work?
        //parameterized constructor 
        
        int play(); //can invoke quit/rollDie/setTag
        int quit(); //exit the loop + return data bember:
        //int taketurn();
        int setTag(char * name);
        //int static_cast<type*>pickCard();
        int rollDie();
private:
};

//2nd game
//3rd game
