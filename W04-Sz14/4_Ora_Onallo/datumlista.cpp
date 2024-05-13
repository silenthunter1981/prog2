#include "datumlista.h"

DatumLista::DatumLista(int meret,
                       const string &megjegyzes):
    tomb(new Datum [meret]),
    meret(meret),
    megjegyzes(megjegyzes)
{
}

DatumLista::~DatumLista()
{
    delete[] tomb;
}

// tovabbiak...
