#include <iostream>
#include "POKER.h"
#include "pokeralgorytmy.h"
//#include <time.h>
//#include <stdio.h>
#include <cstdlib>

using namespace std;

Card::Card()
{

}

void Card::insertCard(string n, int v, int s)
{
    name=n;
    value=v;
    suit=s;
}

void Card::create()
{
    char c[2];

    cin>>c[0]>>c[1];

    if ((c[1]=='s')||(c[1]=='S')) suit=1;
    if ((c[1]=='c')||(c[1]=='C')) suit=2;
    if ((c[1]=='d')||(c[1]=='D')) suit=3;
    if ((c[1]=='h')||(c[1]=='H')) suit=4;
    if ((c[0]=='a')||(c[0]=='A')) value=0;
    if (c[0]=='2')value=1;
    if (c[0]=='3')value=2;
    if (c[0]=='4')value=3;
    if (c[0]=='5')value=4;
    if (c[0]=='6')value=5;
    if (c[0]=='7')value=6;
    if (c[0]=='8')value=7;
    if (c[0]=='9')value=8;
    if ((c[0]=='t')||(c[0]=='T')) value=9;
    if ((c[0]=='j')||(c[0]=='J')) value=10;
    if ((c[0]=='q')||(c[0]=='Q')) value=11;
    if ((c[0]=='k')||(c[0]=='K')) value=12;

}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Hand::show(int b)
{
    system("clear");
    cout<<endl<<"PLAYER: "<<playername<<"  $"<<credit<<"        BANK: $"<<b<<endl;
    cout<<"________________________________";
    cout<<endl<<"|| "<<i.name<<" || "<<ii.name<<" || "<<iii.name<<" || "<<iv.name<<" || "<<v.name<<" || "<<endl<<kind<<endl;
    cout<<"--------------------------------"<<endl;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

Hand::Hand()
{


}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Hand::create(int cr, string name, bool cards)
{
    if(cards==true)
    {
        i.create();
        ii.create();
        iii.create();
        iv.create();
        v.create();
    }

    playername = name;
    credit = cr;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

bool Hand::checkSuit()
{
    if((i.suit==ii.suit)&&(ii.suit==iii.suit)&&(iii.suit==iv.suit)&&(iv.suit==v.suit)) return true;
    else return false;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Hand::checkKind()
{
    int check[]= {i.value, ii.value, iii.value, iv.value, v.value};
    int samecounter = 1;
    quickSort(check, 0, 4);

    for (int i=0; i<4; i++)
    {
        if(check[i]==check[i+1]) samecounter++;
    }

    if(samecounter==2) kind="One pair";
    if((samecounter==4)&&(check[1]!=check[3])) kind="Full house";
    if((samecounter==4)&&(check[1]==check[3])) kind="Four of a kind";
    if(samecounter==3) kind="Two pairs";
    if((samecounter==3)&&(check[0]==check[1])&&(check[1]==check[2])) kind="Three of a kind";
    if((samecounter==3)&&(check[1]==check[2])&&(check[2]==check[3])) kind="Three of a kind";
    if((samecounter==3)&&(check[2]==check[3])&&(check[3]==check[4])) kind="Three of a kind";
    if(samecounter==1) kind="High card";
}

//-------------------------------------------------------------------------------------------------------------------------

bool Hand::checkFlush()
{
    int check[]= {i.value, ii.value, iii.value, iv.value, v.value};
    quickSort(check, 0, 4);

    if((check[0]==check[1]-1)&&(check[1]==check[2]-1)&&(check[2]==check[3]-1)&&(check[3]==check[4]-1)) return true;
    else return false;
}

//----------------------------------------------------------------------------------------------------------------------------

bool Hand::checkRoyal()
{
    int check[]= {i.value, ii.value, iii.value, iv.value, v.value};
    quickSort(check, 0, 4);

    if((check[0]==0)&&(check[1]==9)&&(check[2]==10)&&(check[3]==11)&&(check[4]==12)) return true;
    else return false;
}

//--------------------------------------------------------------------------------------------------------------------------------

void Hand::determineHandType(bool s, bool r, bool f)
{
  if(kind=="High card")
  {
    if ((f==true)&&(s==true)) kind="Straight Flush";
    if ((f==true)&&(s==false)) kind="Straight";
    if ((r==true)&&(s==true)) kind="Royal flush";
    if ((r==true)&&(s==false)) kind="Straight";
    if ((r==false)&&(f==false)&&(s==true)) kind="Flush";
  }
}

//---------------------------------------------------------------------------------------------------------------------------------

void Hand::draw(Card deck[], int siz)
{
    int p;

    srand(time(NULL));
    p = rand()%siz;

    while (deck[p].suit==0)
    {
        p = rand()%siz;
    }
    i = deck[p];
    deck[p].suit=0;

    while (deck[p].suit==0)
    {
        p = rand()%siz;
    }
    ii = deck[p];
    deck[p].suit=0;

    while (deck[p].suit==0)
    {
        p = rand()%siz;
    }
    iii = deck[p];
    deck[p].suit=0;

    while (deck[p].suit==0)
    {
        p = rand()%siz;
    }
    iv = deck[p];
    deck[p].suit=0;

    while (deck[p].suit==0)
    {
        p = rand()%siz;
    }
    v = deck[p];
    deck[p].suit=0;

}

//------------------------------------------------------------------------------------------------------------------------------

void Hand::change(Card deck[], int siz)
{
    Card hand[]= {i, ii, iii, iv, v};
    int howmany;
    string card;

    HOWMANY: cout<<endl<<"HOW MANY CARDS? ";
    cin>>howmany;
    if(howmany>4)
    {
        cerr<<"TOO MANY!";
        goto HOWMANY;
    }
    cout<<endl;
    for(int i=0; i<howmany; i++)
    {
        cout<<"PICK CARD "<<i+1<<": ";
        cin>>card;
        for(int i=0; i<5; i++)
            if(hand[i].name==card) hand[i].name="XX";
    }

    for(int i=0; i<5; i++)
    {
        srand(time(NULL));
        int p = rand()%siz;


        while (deck[p].suit==0)
        {
            p = rand()%siz;
        }
        if(hand[i].name=="XX")
        {
            hand[i] = deck[p];
            deck[p].suit=0;
        }
    }
    i = hand[0];
    ii = hand[1];
    iii = hand[2];
    iv = hand[3];
    v = hand[4];

}

//----------------------------------------------------------------------------------------------------------------------------

void Hand::placeBet(int &b)
{
    int bet;
    BET: cout<<endl<<"BET: ";
    cin>>bet;
    if(bet>credit)
    {
        cerr<<endl<<"NOT ENOUGH MONEY!"<<endl;
        goto BET;
    }
    credit -= bet;
    b += bet;

}
