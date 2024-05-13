#include "datumlista.h"

DatumLista::DatumLista(int meret,
                       const string& megjegyzes):
    tomb(new Datum[meret]),
    meret(meret),
    megjegyzes(megjegyzes)
{
    // tomb = new Datum[meret];
}

DatumLista::~DatumLista()
{
    // new-hoz delete,
    // new[]-hoz delete[]

    delete[] tomb;
}

const Datum& DatumLista::getDatum(int index) const
{
    return tomb[index];
}

void DatumLista::setDatum(int index, const Datum& uj_datum)
{
    tomb[index] = uj_datum;
}
