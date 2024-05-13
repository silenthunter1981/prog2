#include "rendezveny.h"

#include <iostream>
using namespace std;

// gyerek konstruktor elso dolga:
// ososztaly konstruktor meghivni
Rendezveny::Rendezveny():
    Szamsor(7), // Szamsor(unsigned int db);
    vip(nullptr) // nullptr, NULL, 0
{
}

void Rendezveny::setKiemeltVendeg(const Szemely &uj_vip)
{
    // mem kezeles???
    vip = new Szemely(uj_vip);
}

void Rendezveny::kiir() const
{
    for (unsigned i=0;i<getDarab();i++)
        cout << getErtek(i) << " ";

    if (vip)
        cout << vip->teljesNev();
    else
        cout << "<NINCS VIP>";
    cout << endl;
}
