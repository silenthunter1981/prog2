#include "utazas.h"

Utazas::Utazas(const string &nev, const string &leiras, int napokSzama):
    nev(nev),
    leiras(leiras),
    napokSzama(napokSzama)
{

}

Utazas::~Utazas()
{
}

void Utazas::setLeiras(const string &utLeiras)
{
    leiras=utLeiras;
}

string Utazas::getLeiras() const
{
    return leiras;
}

void Utazas::setNapokSzama(int &utNapokSzama)
{
    napokSzama=utNapokSzama;
}

int Utazas::getNapokSzama() const
{
    return napokSzama;
}

string Utazas::getName() const
{
    return nev;
}

void Utazas::setName(const string &utNev)
{
    nev=utNev;
}


