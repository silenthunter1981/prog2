#ifndef KORUTAZAS_H
#define KORUTAZAS_H

#include "utazas.h"

class Korutazas : public Utazas
{
    string* varosok;
    int varosokSzama;
    int maxVarosokSzama;

public:
    Korutazas(const string &utNev,const string &utLeiras,int utNapokSzama,int utMaxVarosokSzama);
    ~Korutazas();
    void operator +=(string varos);
    virtual void kiir() ;


};

#endif // KORUTAZAS_H

