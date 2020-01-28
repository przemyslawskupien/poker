#include <iostream>



using namespace std;

//-------------------------------------------------------------------------------------------------------------------------

class Card
{
public:

    string name;
    int suit, value;

    Card();
    void create();
    void insertCard(string, int, int);
};

//--------------------------------------------------------------------------------------------------------------------------



class Hand
{
    Card i, ii, iii, iv, v;
    int credit;
    string playername, kind;

public:
    Hand ();

    void show(int);
    void create(int, string, bool);
    void draw(Card[], int);
    void change(Card[], int);
    void placeBet(int&);
    void determineHandType();
    int score();
    void winner(int&);

    void showAI(int);
    void showAIfin(int);
    void placeBetAI(int&);
};

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
