#ifndef HALLGATO_H
#define HALLGATO_H

#include "szemely.h"

// ősosztály (base class): Szemely
// gyerekosztály (derived class): Hallgato
// public öröklődés: fontos
class Hallgato : public Szemely
{
    string neptun;
    unsigned felevek; // unsigned int = unsigned
public:
    Hallgato(const string& vnev,
             const string& knev,
             unsigned eletkor,
             const string& neptun,
             unsigned felevek=1);
    // default argumentum (=1): csak a headerben
    string getNeptun() const;
    unsigned int getFelevekSzama() const;
    void setFelevek(unsigned int newFelevek);

    void kiir () const;

    bool furcsa () const;
};

// QtCreator: Ctrl+Shift+R -> symbol átnevezése

#endif // HALLGATO_H
