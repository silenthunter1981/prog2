#include "rendezveny.h"

#include <iostream>
using namespace std;

// Szamsor(unsigned int db);
// Szamsor(const Szamsor &sz);

Rendezveny::Rendezveny():
    Szamsor(7),
    kiemelt(nullptr)
{
}

void Rendezveny::setKiemeltVendeg(const Szemely &sz)
{
    delete kiemelt; // ha be volt allitva ezelott
    kiemelt = new Szemely(sz); // masolo konstruktor
}

Rendezveny::~Rendezveny()
{
    delete kiemelt; // ha be volt allitva, ha nem
}

void Rendezveny::kiir() const
{
    for (unsigned int i=0;i<getDarab();i++)
        cout << getErtek(i) << " ";
    cout << "Kiemelt: ";
    if (kiemelt)
        cout << kiemelt->teljesNev();
    else
        cout << "<NINCS>";
    cout << endl;
}
