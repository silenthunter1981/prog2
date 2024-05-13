#include "datumlista.h"
using namespace Naptar;

int DatumLista::maxDarab = 6;

DatumLista::DatumLista(int meret,
                       const string& megjegyzes):
    tomb(new Datum [meret]),
    meret(meret),
    megjegyzes(megjegyzes)
{
}

DatumLista::~DatumLista()
{
    delete[] tomb;
}

void DatumLista::setMegjegyzes(const string& megjegyzes)
{
    this->megjegyzes = megjegyzes;
}

const string& DatumLista::getMegjegyzes() const
{
    return megjegyzes;
}

void DatumLista::setDatum(int index, const Datum& datum)
{
    if (0<=index && index<meret)
    {
        tomb[index] = datum;
    }
    else
    {
        // nem specifikalja a feladat,
        // hogy ervenytelen index eseten mi tortenjen
    }
}

const Datum& DatumLista::getDatum(int index) const
{
    // index ellenorzes nincs
    return tomb[index];
}

unsigned int DatumLista::getDarab() const
{
    return meret;
}

// meg kell irni a masolo konstruktort,
// a dinamikus tomb miatt nem jo az automatikus masolas
DatumLista::DatumLista(const DatumLista& orig):
    tomb(new Datum[orig.meret]),
    meret(orig.meret),
    megjegyzes(orig.megjegyzes)
{
    for (int i=0;i<meret;i++)
        tomb[i] = orig.tomb[i];
}

void DatumLista::hozzaad(const Datum& datum)
{
    if (meret >= maxDarab)
    {
        // nem tortenik meg a beszuras
        // (a feladat nem reszletezi,
        // hogy van-e egyeb teendo ilyenkor)
        return;
    }

    // ujrafoglalos procedura
    Datum* ujtomb = new Datum[meret+1];
    for (int i=0;i<meret;i++)
        ujtomb[i] = tomb[i];
    ujtomb[meret] = datum;
    delete[] tomb;
    tomb = ujtomb;
    meret++;
}

// kell a Datum osztalyba a korabbiMint() fuggveny is
const Datum& DatumLista::legkorabbi() const
{
    if (meret==0)
    {
        // nulla meretre nincs ertelme a hivasnak,
        // de a feladat szerint feltetelezhetjuk
        // hogy ez az eset ugysem fordul elo
        throw 0;
    }
    int min_idx=0;
    for (int i=0;i<meret;i++)
    {
        if (tomb[i].korabbiMint(tomb[min_idx]))
            min_idx = i;
    }
    return tomb[min_idx];
}

int DatumLista::getMaxDarab()
{
    return maxDarab;
}

void DatumLista::setMaxDarab(int newMaxDarab)
{
    maxDarab = newMaxDarab;
}
