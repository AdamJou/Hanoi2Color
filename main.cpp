#include <iostream>
#include <fstream>



using namespace std;

void hanoi(ofstream &pl, int ilosc, int z = 1, int na = 2)
{
    int lustro = 6 - z - na;
    if(ilosc == 1)
    {
        pl << z << " " << na << endl;
    }
    else if(ilosc>=2)
    {
        hanoi(pl, ilosc - 1, z , lustro);
        hanoi(pl, 1, z ,na);
        hanoi(pl, ilosc -1, lustro, na);
    }
}


void hanoi_kolor(ofstream &pl, int ilosc, int z = 1, int na=3)
{
    int help;
    pl << ilosc << endl << 3 << endl;
    for(int a = 1; a < ilosc; a++)
    {
        hanoi(pl, ilosc -a, z , na);
        help = z;
        z = na;
        na = help;
    }
}


int main()
{

    ofstream pl;
    pl.open("wynik.txt");

    hanoi_kolor(pl,4);
    pl.close();




    return 0;
}
