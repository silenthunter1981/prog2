#include "hallgato.h"

#include <iostream>
using namespace std;

Hallgato::Hallgato(const string &vnev,
                   const string &knev,
                   unsigned int eletkor,
                   const string &neptun,
                   unsigned int felevek):
    Szemely(vnev,knev,eletkor),
    neptun(neptun) //,
    //felevek(felevek)
{
    this->felevek = felevek;
}

string Hallgato::getNeptunCode() const
{
    return neptun;
}

unsigned int Hallgato::getFelevek() const
{
    return felevek;
}

void Hallgato::setFelevek(unsigned int newFelevek)
{
    felevek = newFelevek;
}

void Hallgato::kiir() const
{
    // kiir(); // nem jo, vegtelen ciklus
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

    return eletkor < 18 + felevek/2; // eletkor: protected
}
