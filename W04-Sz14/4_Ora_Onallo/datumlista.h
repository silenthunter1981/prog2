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

    // tovabbiak, pl:
    const string& getMegjegyzes() const;
    void setMegjegyzes (const string& uj_megjegyzes) const;
    const Datum& getDatum (int index) const;
    void setDatum (int index, const Datum& uj_datum);
};

#endif // DATUMLISTA_H
