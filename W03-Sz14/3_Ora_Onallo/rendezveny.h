#ifndef RENDEZVENY_H
#define RENDEZVENY_H

#include "szamsor.h"
#include "szemely.h"

class Rendezveny : public Szamsor
{
    Szemely* kiemelt; // kezdetben nullptr
    // nullptr, NULL, 0
public:
    Rendezveny();

    // r2.setKiemeltVendeg(Szemely("Vendeg", "Piroska", 30));

    // nem pointer megy be:
    void setKiemeltVendeg (const Szemely& sz);

    ~Rendezveny();

    void kiir () const;

};

#endif // RENDEZVENY_H
