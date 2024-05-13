#ifndef VERSENY_H
#define VERSENY_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#include "probalkozas.h"

class Verseny
{
    string megnevezes;
    vector<Probalkozas> probalkozasok;
public:
    Verseny(const string &fajlnev);
    //void kiir() const;
    void kiir(const string &fajlnev) const;
    void kiir(ostream &os = cout) const;
    void uj(string nev,double tavolsag,bool ervenyes);
    vector<double> ervenyesDobasok();
};

#endif // VERSENY_H
