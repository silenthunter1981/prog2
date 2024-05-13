#include "tarolo.h"

#include <iostream>
using namespace std;

Tarolo::Tarolo()
{
    cin >> meret;
    tomb = new int[meret];
    for (int i=0;i<meret;i++)
        cin >> tomb[i];
}

Tarolo::Tarolo(int meret)
{
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
    cout << "[" << meret << "]:";
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
