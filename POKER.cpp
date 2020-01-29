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


//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Hand::determineHandType()
{
    int check[]= {i.value, ii.value, iii.value, iv.value, v.value};
    int samecounter = 1;
    bool f, s, r;
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

    if((check[0]==check[1]-1)&&(check[1]==check[2]-1)&&(check[2]==check[3]-1)&&(check[3]==check[4]-1)) f = true;
    else f = false;

    if((check[0]==1)&&(check[1]==2)&&(check[2]==3)&&(check[3]==4)&&(check[4]==13)) f = true;
    else f = false;

    if((check[0]==9)&&(check[1]==10)&&(check[2]==11)&&(check[3]==12)&&(check[4]==13)) r = true;
    else r = false;

    if((i.suit==ii.suit)&&(ii.suit==iii.suit)&&(iii.suit==iv.suit)&&(iv.suit==v.suit)) s = true;
    else s = false;

    if(kind=="High card")
    {
      if ((f==true)&&(s==true)) kind="Straight Flush";
      if ((f==true)&&(s==false)) kind="Straight";
      if ((r==true)&&(s==true)) kind="Royal flush";
      if ((r==true)&&(s==false)) kind="Straight";
      if ((r==false)&&(f==false)&&(s==true)) kind="Flush";
    }

}


//--------------------------------------------------------------------------------------------------------------------------------


void Hand::showAI(int b)
{

    cout<<endl<<"PLAYER: "<<playername<<"  $"<<credit<<"        BANK: $"<<b<<endl;
}

//---------------------------------------------------------------------------------------------------------------------------------
void Hand::showAIfin(int b)
{

    cout<<endl<<"PLAYER: "<<playername<<"  $"<<credit<<"        BANK: $"<<b<<endl;
    cout<<"________________________________";
    cout<<endl<<"|| "<<i.name<<" || "<<ii.name<<" || "<<iii.name<<" || "<<iv.name<<" || "<<v.name<<" || "<<endl<<kind<<endl;
    cout<<"--------------------------------"<<endl;
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
//-----------------------------------------------------------------------------------------------------------------------------------
void Hand::placeBetAI(int &b)
{
    int bet;
    srand(time(NULL));

    if(kind=="High card") bet = rand()%(credit/10);
    if (kind=="One pair") bet = rand()%(credit/10);
    if (kind=="Two pairs") bet = rand()%(credit/9);
    if (kind=="Three of a kind") bet = rand()%(credit/7);
    if (kind=="Streight") bet = rand()%(credit/6);
    if (kind=="Flush") bet = rand()%(credit/5);
    if (kind=="Full house") bet = rand()%(credit/4);
    if (kind=="Four of a kind") bet = rand()%(credit/3);
    if (kind=="Straight flush") bet = rand()%(credit/2);
    if (kind=="Royal flush") bet = rand()%(credit);
  
    credit -= bet;
    b += bet;

}

//-----------------------------------------------------------------------------------------------------------------------------------

void Hand::winner(int &b)
{
  cout<<endl<<playername<<" is a winner!!!"<<endl;
  credit += b;
  b = 0;
}

//-----------------------------------------------------------------------------------------------------------------------------------
int Hand::score()
{


    if(kind=="High card") return 0;
    if (kind=="One pair") return 1;
    if (kind=="Two pairs") return 2;
    if (kind=="Three of a kind") return 3;
    if (kind=="Streight") return 4;
    if (kind=="Flush") return 5;
    if (kind=="Full house") return 6;
    if (kind=="Four of a kind") return 7;
    if (kind=="Straight flush") return 8;
    if (kind=="Royal flush") return 9;


}

//------------------------------------------------------------------------------------------------------

//have to implement suit for royal flush tie
int Hand::tie()
{
  int check[]= {i.value, ii.value, iii.value, iv.value, v.value};
  quickSort(check, 0, 4);

  if(kind=="High card") return check[4];
  if(kind=="One pair")
    {
      if(check[0]==check[1]) return check[0];
      if(check[1]==check[2]) return check[1];
      if(check[2]==check[3]) return check[2];
      if(check[3]==check[4]) return check[3];
    }
  if(kind=="Two pairs") return check[3];
  if(kind=="Three of a kind") return check[2];
  if(kind=="Streight")
    {
      if(check[0]==1) return 0;
      else return check[4];
    }
  if(kind=="Flush") return check[4];
  if(kind=="Full house") return check[2];
  if(kind=="Four of a kind") return check[1];
  if(kind=="Streight flush")
  {
    if(check[0]==1) return 0;
    else return check[4];
  }

}
