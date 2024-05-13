#ifndef RENDEZVENY_H
#define RENDEZVENY_H

#include "szamsor.h"
#include "szemely.h"

class Rendezveny : public Szamsor
{
    // // ezt is lehetne akar:
    // Szemely vip;
    // bool van_vip;

    Szemely* vip = nullptr;
public:
    Rendezveny();

    // r2.setKiemeltVendeg(Szemely("Vendeg", "Piroska", 30));
    void setKiemeltVendeg(const Szemely& uj_vip);

    void kiir () const;
};

#endif // RENDEZVENY_H
