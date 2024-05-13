#include "szamok.h"
using namespace Tarolo;

#include <iostream>
using namespace std;

Szamok::Szamok(int meret,
               double kezdo)
{
    tomb = new double[meret];
    this->meret = meret;

    for (int i=0;i<meret;i++)
        tomb[i] = kezdo;
}

Szamok::~Szamok()
{
    delete[] tomb;
}

void Szamok::megjelenit() const
{
    for (int i=0;i<meret;i++)
        cout << tomb[i] << " ";
    cout << endl;
}

int Szamok::darabLeker() const
{
    return meret;
}

void Szamok::ertekBeallit(int index,
                          double uj_ertek)
{
    if (0<=index && index<meret)
    {
        tomb[index] = uj_ertek;
    }
}

double Szamok::ertekLeker(int index) const
{
    if (0<=index && index<meret)
    {
        return tomb[index];
    }
    // else
    return -1e8;
}
