#ifndef ASSZOCIATIV_H
#define ASSZOCIATIV_H

#include "kulcsertekpar.h"

template <class KulcsTipus, class ErtekTipus>
class Asszociativ
{
    int tmeret;
    KulcsErtekPar<KulcsTipus,ErtekTipus> *tomb;

    int keres (const KulcsTipus &kulcs) const
    {
        int i=0;
        while (i<tmeret && tomb[i].kulcs!=kulcs)i++;
                return i;
    }

public:

    Asszociativ():
        tmeret(),
        tomb(nullptr)
    {}


    ~Asszociativ(){
        delete [] tomb;
    }
    int meret()const {
        return tmeret;
    }



};


#endif // ASSZOCIATIV_H
