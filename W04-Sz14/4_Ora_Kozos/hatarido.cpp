#include "hatarido.h"

#include <iostream>
using namespace std;

// static Datum aktualisDatum;
Datum Hatarido::aktualisDatum(2024,3,6);

// // egyeb tipus, pl. int eseten lehetne peldaul:
// // static int aktualisEv;
// int Hatarido::aktualisEv = 2024;

// Hatarido h1("Elso tarolo osztaly");
Hatarido::Hatarido(const string &_nev):
    nev(_nev),
    alpha(nullptr), // barmelyik jo
    beta(NULL),
    vegso(0)
{
    // nev = _nev;
    // this->nev = nev;
}

Hatarido::~Hatarido()
{
    delete alpha;
    delete beta;
    delete vegso;
}

string Hatarido::getNev() const
{
    return nev;
}

void Hatarido::setNev(const string &newNev)
{
    nev = newNev;
}

Datum *Hatarido::getAlphaDatum() const
{
    return alpha;
}

void Hatarido::setAlphaDatum(const Datum& newAlpha)
{
    delete alpha;
    alpha = new Datum(newAlpha);
}

Datum *Hatarido::getBetaDatum() const
{
    return beta;
}

void Hatarido::setBetaDatum(Datum newBeta)
{
    delete beta;
    beta = new Datum(newBeta);
}

Datum *Hatarido::getVegsoDatum() const
{
    return vegso;
}

void Hatarido::setVegsoDatum(Datum newVegso)
{
    delete vegso;
    vegso = new Datum(newVegso);
}

Datum Hatarido::getAktualisDatum()
{
    return aktualisDatum;
}

void Hatarido::setAktualisDatum(const Datum &newAktualisDatum)
{
    aktualisDatum = newAktualisDatum;
}

void Hatarido::lejart() const
{
    // ha nincs korabbiMint() fuggveny,
    // akkor alpha->getEv() < aktualisDatum.getEv()
    // de ez csak reszmegoldas

    if (alpha && alpha->korabbiMint(aktualisDatum))
    {
        cout << "alpha lejart" << endl;
    }
    if (beta && beta->korabbiMint(aktualisDatum))
    {
        cout << "beta lejart" << endl;
    }
    if (vegso && vegso->korabbiMint(aktualisDatum))
    {
        cout << "vegso lejart" << endl;
    }
}

void Hatarido::hataridoTorol(const string &melyik)
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

// // masolo konstruktor van alapertelmezetten
// // es ezt csinalja:
// Hatarido::Hatarido(const Hatarido &orig):
//     nev(orig.nev),
//     alpha(orig.alpha),
//     beta(orig.beta),
//     vegso(orig.vegso)
// {
// }

Hatarido::Hatarido(const Hatarido &orig):
    nev(orig.nev),
    alpha(),
    beta(),
    vegso(orig.vegso ? new Datum(*orig.vegso) : nullptr)
{
    if (orig.alpha)
        alpha = new Datum(*orig.alpha);
    else
        alpha = nullptr;

    beta = orig.beta ? new Datum(*orig.beta) : nullptr;
}
