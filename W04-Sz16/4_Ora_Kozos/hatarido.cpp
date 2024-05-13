#include "hatarido.h"

#include <iostream>

Datum Hatarido::aktualisDatum(2024, 3, 6);
// mintha: Datum d(2024, 3, 6);

// nem kell a feladathoz, csak pelda:
int Hatarido::aktualisEv = 2024;
string Hatarido::aktualisHetNapja = "szerda";

string Hatarido::getNev() const
{
    return nev;
}

void Hatarido::setNev(const string& newNev)
{
    nev = newNev;
}

Datum* Hatarido::getAlphaDatum() const
{
    return alpha;
}

void Hatarido::setAlphaDatum(const Datum& newAlpha)
{
    delete alpha;
    // rossz:
    // alpha = &newAlpha;

    // // OK:
    // alpha = new Datum(newAlpha.getEv(),
    //                   newAlpha.getHonap(),
    //                   newAlpha.getNap());

    // legjobb: (Datum masolo konstruktora)
    alpha = new Datum(newAlpha);
}

Datum* Hatarido::getBetaDatum() const
{
    return beta;
}

void Hatarido::setBetaDatum(const Datum& newBeta)
{
    delete beta;
    beta = new Datum(newBeta);
}

Datum* Hatarido::getVegsoDatum() const
{
    return vegso;
}

void Hatarido::setVegsoDatum(const Datum& newVegso)
{
    delete vegso;
    vegso = new Datum(newVegso);
}

Datum Hatarido::getAktualisDatum()
{
    return aktualisDatum;
}

void Hatarido::setAktualisDatum(const Datum& newAktualisDatum)
{
    aktualisDatum = newAktualisDatum;
}

void Hatarido::lejart() const
{
    if (alpha && alpha->korabbiMint(aktualisDatum))
    {
        cout << "alpha LEJART!" << endl;
    }
    if (beta)
    {
        if (beta->korabbiMint(aktualisDatum))
        {
            cout << "beta LEJART!" << endl;
        }
    }
    if (vegso)
        if (vegso->korabbiMint(aktualisDatum))
            cout << "vegso LEJART!" << endl;
}

void Hatarido::hataridoTorol(const string& melyik)
{
    if (melyik == "alpha")
    {
        delete alpha;
        alpha = nullptr;
    }
    else if (melyik == "beta")
    {
        delete beta;
        beta = nullptr;
    }
    else if (melyik == "vegso")
    {
        delete vegso;
        vegso = nullptr;
    }
}

// // az alapertelmezett masolo konstruktor
// // (automatikus, ha nem irunk masolo konstruktort)
// // az pontosan ezt csinalna:
// Hatarido::Hatarido(const Hatarido& orig):
//     nev(orig.nev),
//     alpha(orig.alpha),
//     beta(orig.beta),
//     vegso(orig.vegso)
// {
// }

Hatarido::Hatarido(const Hatarido& orig):
    nev(orig.nev),
    vegso(orig.vegso ? new Datum(*orig.vegso) : nullptr)
{
    if (orig.alpha)
        alpha = new Datum(*orig.alpha);
    else
        alpha = nullptr;

    beta = orig.beta ? new Datum(*orig.beta) : nullptr;
}

Hatarido::Hatarido(const string& nev):
    nev(nev),
    alpha(nullptr), // nullptr, NULL, 0
    beta(nullptr),
    vegso(nullptr)
{
    // this->nev = nev;
    // nev = _nev;
}

Hatarido::~Hatarido()
{
    delete alpha;
    delete beta;
    delete vegso;
}

