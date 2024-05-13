#ifndef HATARIDO_H
#define HATARIDO_H

#include <string>
using namespace std;

#include "datum.h"

class Hatarido
{
    static Datum aktualisDatum;

    // nem kell a feladathoz, csak pelda:
    static int aktualisEv;
    static string aktualisHetNapja;

    string nev;
    Datum* alpha;
    Datum* beta;
    Datum* vegso = nullptr;
public:
    // Hatarido h1("Elso tarolo osztaly");
    Hatarido(const string& nev);
    ~Hatarido();

    string getNev() const;
    void setNev(const string& newNev);

    Datum* getAlphaDatum() const;

    // h1.setAlphaDatum(Datum(2017, 3, 6));
    //
    // Datum d(2017, 3, 6);
    // h1.setAlphaDatum(d);
    //
    // atadas: nem Datum*, hanem Datum,
    // vagy meginkabb const Datum&
    void setAlphaDatum(const Datum& newAlpha);

    Datum* getBetaDatum() const;
    void setBetaDatum(const Datum& newBeta);

    Datum* getVegsoDatum() const;
    void setVegsoDatum(const Datum& newVegso);

    static Datum getAktualisDatum(); // nem const
    static void setAktualisDatum(const Datum& newAktualisDatum);

    void lejart () const;

    // h1.hataridoTorol("alpha");
    void hataridoTorol (const string& melyik);

    Hatarido (const Hatarido& orig);
};

#endif // HATARIDO_H
