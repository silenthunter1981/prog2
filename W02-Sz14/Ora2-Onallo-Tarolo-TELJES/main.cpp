#include <iostream>
using namespace std;

#include "tarolo.h"
using EpicToolbox::Tarolo;

int kisebbTarolo (const Tarolo& a,
                 const Tarolo& b)
{
    // kell a Tarolo-ba a getMeret() metodus
    int ma = a.getMeret();
    int mb = b.getMeret();
    if (ma > mb)
        return 1;
    if (ma < mb)
        return -1;
    return 0;
}

int main()
{
    Tarolo t1;
    Tarolo t2(7);

    t1.kiir(); // amit beirunk
    t2.kiir(); // 1 2 3 4 5 6 7

    t2.hozzaad(8);
    t2.hozzaad(9);
    t2.hozzaad(10);
    t2.kiir(); // 1 2 3 4 5 6 7 8 9 10

    cout << t2.atlag() << endl; // 5.5

    cout << kisebbTarolo(t1,t2) << endl;
    cout << kisebbTarolo(t2,t1) << endl;
    // 0 0 vagy 1 -1 vagy -1 1
    cout << kisebbTarolo(t1,t1) << endl; // 0

    cout << t2.tartomany() << endl; // 9
    t2.rendez(false);
    t2.kiir(); // 10 9 8 7 6 5 4 3 2 1
    t2.rendez(true);
    t1.kiir();
    t1.rendez(true);
    t2.kiir(); // 1 2 3 4 5 6 7 8 9 10

    t2.hozzafuz(t2); // 1 2 ... 10 1 2 ... 10
    t2.kiir();
    t2.hozzafuz(t1);
    t2.kiir();

    cout << "main() vege!" << endl;
    return 0;
}
