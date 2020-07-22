//this is the implementation for a list of games, it manages a CLL that is comprised of 
//base game nodes (it only serves/works with derived class games)

class gamesL()
{
    public:
        gamesL();

        ~gamesL();

        //


    protected:
        gameN * rear;
};
