#ifndef DATUMLISTA_H
#define DATUMLISTA_H

#include <string>
using namespace std;

#include "datum.h"

class DatumLista
{
    Datum* tomb;
    int meret;
    string megjegyzes;
public:
    DatumLista(int meret, const string& megjegyzes);
    ~DatumLista();

    const Datum& getDatum (int index) const;
    void setDatum (int index, const Datum& uj_datum);
};

#endif // DATUMLISTA_H
