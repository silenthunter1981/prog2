#ifndef HAJO_H
#define HAJO_H

#include "jarmu.h"

class Hajo : public Jarmu
{
    unsigned int teherbiras;
public:
    Hajo(unsigned int t,unsigned int s,unsigned int teher);
    void kiir() const override; //hiba detektálás
    ~Hajo();
    //Jarmu *clone() const override;
    Hajo *clone() const override;
};

#endif // HAJO_H
