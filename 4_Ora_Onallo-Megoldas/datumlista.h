#ifndef DATUMLISTA_H
#define DATUMLISTA_H

#include <string>
using namespace std;

#include "datum.h"

namespace Naptar
{

class DatumLista
{
    static int maxDarab;
    // static adattag: kell a .cpp-be is!

    Datum* tomb;
    int meret;
    string megjegyzes;
public:
    DatumLista(int meret,
               const string& megjegyzes);
    ~DatumLista();

    void setMegjegyzes (const string& megjegyzes);
    const string& getMegjegyzes () const;

    void setDatum (int index, const Datum& datum);
    const Datum& getDatum (int index) const;

    // int lenne az osztaly sajat logikaja alapjan,
    // de a main() unsigned int-kent kezeli az indexeket
    // mindketto OK, de igy nincs warning
    unsigned int getDarab () const;

    DatumLista(const DatumLista& orig);

    void hozzaad (const Datum& datum);

    const Datum& legkorabbi () const;

    // QtCreator-ral generalhato:
    static int getMaxDarab();
    static void setMaxDarab(int newMaxDarab);
};

} // namespace Naptar

#endif // DATUMLISTA_H
