//game.h
//This is the implementation of game.h
//chris lu
//cs202
//program 2
class game
{
    public:
    game(); //default
    game(game * gtcp); //copy
    game(int nametoadd); //paramaterized
    virtual ~game(); //virtual destructor
    virtual int play()=0; //virtual, can only make pointers via dynamic binding
    virtual void quit()=0; //virtual
    virtual int taketurn()=0;//virtual
    virtual int setTag(char * name)=0; //virtual
    virtual int copy(game * gametcp)=0; //virtual
    int display(); //ugh god can we even call this
    int get_name(); //getter
    char * get_tag(); //getter
    bool get_win(); //converts win to a number
    
    protected: 
    int name;
    char * tag;
    bool win; //convert to int
};

class rngGame : public game
{
    public:
        rngGame(); //default
        rngGame(int nametoadd);  //parameterized constructor
        ~rngGame(); //but that's not an identical signature...does this work?
        
        int play(); //covers virtual
        void quit(); //used in play
        int taketurn(); //used in play
        int setTag(char * name); //used in play
        int rollDie();  //returns a random number between 1-10
        int copy(game * gametcp); //copies arg into calling class
private:
};

//this is a matching game
class yum : public game
{
    public:
        yum();//default
        yum(int nametoadd); //paramterized constructor
        ~yum(); //destructor
        
        int taketurn(); //virtual
        int play(); //virtual
        void quit(); //virtual
        int setTag(char * name); //virtual
        int roll();  //rolls a rng
        int copy(game * gametcp); //virtual
    private:
};

//the third game
class blackjack : public game
{
    public:
        blackjack(); //default constructor
        blackjack(int nametoadd); //paramterized constructor
        ~blackjack(); //default destructor
        int play(); //not done
        void quit(); //not done
        int roll();
        int setTag(char * name); //not done
        int copy(game * gametcp); //not done
        int taketurn(); //virtual
    private:
};
