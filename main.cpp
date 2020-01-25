#include <iostream>
#include "POKER.h"
#include <stdio.h>
#include <cstdlib>
#include "function.h"

using namespace std;



int main()
{
// Talia
//----------------------------------------------------------------------------------------------------------------------------
    Card newdeck[52];
    newdeck[0].insertCard("AS", 0, 1);
    newdeck[1].insertCard("2S", 1, 1);
    newdeck[2].insertCard("3S", 2, 1);
    newdeck[3].insertCard("4S", 3, 1);
    newdeck[4].insertCard("5S", 4, 1);
    newdeck[5].insertCard("6S", 5, 1);
    newdeck[6].insertCard("7S", 6, 1);
    newdeck[7].insertCard("8S", 7, 1);
    newdeck[8].insertCard("9S", 8, 1);
    newdeck[9].insertCard("TS", 9, 1);
    newdeck[10].insertCard("JS", 10, 1);
    newdeck[11].insertCard("QS", 11, 1);
    newdeck[12].insertCard("KS", 12, 1);
    newdeck[13].insertCard("AC", 0, 2);
    newdeck[14].insertCard("2C", 1, 2);
    newdeck[15].insertCard("3C", 2, 2);
    newdeck[16].insertCard("4C", 3, 2);
    newdeck[17].insertCard("5C", 4, 2);
    newdeck[18].insertCard("6C", 5, 2);
    newdeck[19].insertCard("7C", 6, 2);
    newdeck[20].insertCard("8C", 7, 2);
    newdeck[21].insertCard("9C", 8, 2);
    newdeck[22].insertCard("TC", 9, 2);
    newdeck[23].insertCard("JC", 10, 2);
    newdeck[24].insertCard("QC", 11, 2);
    newdeck[25].insertCard("KC", 12, 2);
    newdeck[26].insertCard("AD", 0, 3);
    newdeck[27].insertCard("2D", 1, 3);
    newdeck[28].insertCard("3D", 2, 3);
    newdeck[29].insertCard("4D", 3, 3);
    newdeck[30].insertCard("5D", 4, 3);
    newdeck[31].insertCard("6D", 5, 3);
    newdeck[32].insertCard("7D", 6, 3);
    newdeck[33].insertCard("8D", 7, 3);
    newdeck[34].insertCard("9D", 8, 3);
    newdeck[35].insertCard("TD", 9, 3);
    newdeck[36].insertCard("JD", 10, 3);
    newdeck[37].insertCard("QD", 11, 3);
    newdeck[38].insertCard("KD", 12, 3);
    newdeck[39].insertCard("AH", 0, 4);
    newdeck[40].insertCard("2H", 1, 4);
    newdeck[41].insertCard("3H", 2, 4);
    newdeck[42].insertCard("4H", 3, 4);
    newdeck[43].insertCard("5H", 4, 4);
    newdeck[44].insertCard("6H", 5, 4);
    newdeck[45].insertCard("7H", 6, 4);
    newdeck[46].insertCard("8H", 7, 4);
    newdeck[47].insertCard("9H", 8, 4);
    newdeck[48].insertCard("TH", 9, 4);
    newdeck[49].insertCard("JH", 10, 4);
    newdeck[50].insertCard("QH", 11, 4);
    newdeck[51].insertCard("KH", 12, 4);

    Card reset[52];

    for (int i=0; i<52; i++) reset[i]=newdeck[i];


//----------------------------------------------------------------------------------------------------------------------------------

    Hand player1;
    player1.create(50, "Holden", false);

    string power;
    bool suit, flush, royal;
    int bank = 0;

    while(true)
    {


        int resetcounter=0;

        for(int i=0; i<52; i++)
        {
            if(newdeck[i].suit!=0) resetcounter++;
        }

        if(resetcounter<9)
        {
            for (int i=0; i<52; i++) newdeck[i]=reset[i];

        }

        player1.draw(newdeck, 52);
        player1.show(bank);
        player1.checkKind(power);
        flush = player1.checkFlush();
        royal = player1.checkRoyal();
        suit = player1.checkSuit();
        if(power=="High card") determineHandType(power, suit, royal, flush);


        cout<<power<<endl;

        player1.placeBet(bank);

        player1.show(bank);

        cout<<power<<endl;

        player1.change(newdeck, 52);

        player1.show(bank);

        player1.checkKind(power);
        flush = player1.checkFlush();
        royal = player1.checkRoyal();
        suit = player1.checkSuit();
        if(power==" ") determineHandType(power, suit, royal, flush);
        cout<<power<<endl<<"________________________________________________________________________________________________________________________________________________________________"<<endl;
        getchar();
        getchar();
    }

    return 0;

}
