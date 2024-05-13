#include "hallgato.h"

#include <iostream>
using namespace std;

Hallgato::Hallgato(const string &vnev,
                   const string &knev,
                   unsigned int eletkor,
                   const string &_neptun,
                   unsigned int felevek):
    Szemely(vnev,knev,eletkor),
    neptun(_neptun),
    felevek(felevek)
{
    // this->vnev = vnev;
}

string Hallgato::getNeptun() const
{
    return neptun;
}

unsigned int Hallgato::getFelevekSzama() const
{
    return felevek;
}

void Hallgato::setFelevek(unsigned int newFelevek)
{
    felevek = newFelevek;
}

void Hallgato::kiir() const
{
    // kiir(); // nem jo, infinite loop
    Szemely::kiir();
    cout << neptun << " " << felevek << endl;
}

bool Hallgato::furcsa() const
{
    // if (...)
    //     return true;
    // else
    //     return false;

    // return getEletkor() < 18 + felevek/2;

    // eletkor: protected
    return eletkor < 18 + felevek/2;
}

