#include "tarolo.h"
using namespace EpicToolbox;

#include <iostream>
using namespace std;

Tarolo::Tarolo()
{
    // beolvassa a tomb meretet es az elemeit
    cin >> meret;
    tomb = new int[meret];
    for (int i=0;i<meret;i++)
        cin >> tomb[i];
}

Tarolo::Tarolo(int meret)
{
    // elemek: 1, 2, 3, ..., meret
    this->meret = meret;
    tomb = new int[meret];
    for (int i=0;i<meret;i++)
        tomb[i] = i+1;
}

Tarolo::~Tarolo()
{
    delete[] tomb;
}

void Tarolo::kiir() const
{
    cout << "Tarolo ";
    cout << "(" << meret << " elem):";
    for (int i=0;i<meret;i++)
        cout << " " << tomb[i];
    cout << endl;
}

void Tarolo::hozzaad(int uj_elem)
{
    int* ujtomb = new int[meret+1];
    for (int i=0;i<meret;i++)
        ujtomb[i] = tomb[i];
    ujtomb[meret] = uj_elem;
    delete[] tomb;
    tomb = ujtomb;
    meret++;
}

double Tarolo::atlag() const
{
    if (meret==0)
        return 0.0; // hibajelenseg
    int sum=0;
    for (int i=0;i<meret;i++)
        sum += tomb[i];
    return sum / (double)meret;
}

int Tarolo::getMeret() const
{
    return meret;
}

int Tarolo::tartomany() const
{
    int min_index=0, max_index=0;
    for (int i=1;i<meret;i++)
    {
        if (tomb[min_index] > tomb[i])
            min_index = i;
        if (tomb[max_index] < tomb[i])
            max_index = i;
    }
    return tomb[max_index] - tomb[min_index];
}

void Tarolo::rendez(bool novekvo)
{
    for (int i=0;i<meret;i++)
    {
        int m = i;
        for (int j=i+1;j<meret;j++)
        {
            if ((novekvo && tomb[j] < tomb[m]) ||
                (!novekvo && tomb[j] > tomb[m]))
                m = j;
        }
        int csere = tomb[i];
        tomb[i] = tomb[m];
        tomb[m] = csere;
    }
}

void Tarolo::hozzafuz(const Tarolo &masik_tarolo)
{
    //// hibas: vegtelen ciklus,
    //// ha a tarolot "onmagahoz akarjuk fuzni"
    // for (int i=0;i<masik_tarolo.meret;i++)
    //    hozzaad(masik_tarolo.tomb[i]);

    int* ujtomb = new int[meret+masik_tarolo.meret];
    for (int i=0;i<meret;i++)
        ujtomb[i] = tomb[i];
    for (int i=0;i<masik_tarolo.meret;i++)
        ujtomb[i+meret] = masik_tarolo.tomb[i];
    delete[] tomb;
    tomb = ujtomb;
    meret += masik_tarolo.meret;
}
