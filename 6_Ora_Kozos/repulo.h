#ifndef REPULO_H
#define REPULO_H

#include "jarmu.h"

class Repulo : public Jarmu
{
    unsigned int utasletszam;
public:
    Repulo(unsigned int t,unsigned int s,unsigned int u);
    void kiir() const override;
    ~Repulo();
    Repulo *clone() const override;
};

#endif // REPULO_H
