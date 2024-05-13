#ifndef HATARIDO_H
#define HATARIDO_H

#include <string>
using namespace std;

#include "datum.h"

class Hatarido
{
    static Datum aktualisDatum;

    string nev;
    Datum* alpha;
    Datum* beta;
    Datum* vegso = nullptr; // default ertek
public:
    // Hatarido h1("Elso tarolo osztaly");
    Hatarido(const string& nev);
    ~Hatarido();

    string getNev() const;
    void setNev(const string &newNev);

    Datum* getAlphaDatum() const;
    void setAlphaDatum(const Datum& newAlpha);

    Datum* getBetaDatum() const;
    void setBetaDatum(Datum newBeta);

    Datum* getVegsoDatum() const;
    void setVegsoDatum(Datum newVegso);

    static Datum getAktualisDatum();
    static void setAktualisDatum(const Datum &newAktualisDatum);

    void lejart () const;

    // h1.hataridoTorol("alpha");
    void hataridoTorol(const string& melyik);

    Hatarido (const Hatarido& orig);
};

#endif // HATARIDO_H
