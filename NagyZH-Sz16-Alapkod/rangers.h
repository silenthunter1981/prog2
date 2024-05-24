#ifndef RANGERS_H
#define RANGERS_H

#include "warriors.h"

class Rangers : public Warriors
{
    int agility;
public:
    Rangers(const string& _type,const string& _warId,int _price,int _agility);

    void printW()const override;
};

#endif // RANGERS_H
