#ifndef MAGE_H
#define MAGE_H

#include "warriors.h"

class Mage : public Warriors
{
    double magic;
public:
    Mage(const string& _type,const string& _warId,int _price,double _magic);

    void printW()const override;
};

#endif // MAGE_H
