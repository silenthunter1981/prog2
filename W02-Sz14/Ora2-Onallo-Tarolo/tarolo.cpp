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
