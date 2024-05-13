#include "korutazas.h"


Korutazas::Korutazas(const string &utNev, const string &utLeiras, int utNapokSzama, int utMaxVarosokSzama):
    Utazas(utNev,utLeiras,utNapokSzama),
    varosokSzama(utMaxVarosokSzama)
{
    varosok=new string[varosokSzama];
    varosokSzama=0;
}

Korutazas::~Korutazas()
{
    delete [] varosok;
}

void Korutazas::operator +=(string varos)
{
    if(varosokSzama<maxVarosokSzama){
        varosok[varosokSzama]=varos;
        varosokSzama++;
    }
}
void Korutazas::kiir(){
    cout<< getName() << ", " << getLeiras() << ", " << getNapokSzama() << " nap, " << endl;
}
