#include <iostream>

using namespace std;

void determineHandType(string &p, bool s, bool r, bool f)
{
    if ((f==true)&&(s==true)) p="Straight Flush";
    if ((f==true)&&(s==false)) p="Straight";
    if ((r==true)&&(s==true)) p="Royal flush";
    if ((r==true)&&(s==false)) p="Straight";
    if ((r==false)&&(f==false)&&(s==true)) p="Flush";
}
