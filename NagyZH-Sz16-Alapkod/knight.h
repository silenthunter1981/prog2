#ifndef KNIGHT_H
#define KNIGHT_H

#include "warriors.h"

class Knight : public Warriors
{
    int strength;
public:
    Knight(const string& _type,const string& _warId, int _price, int _strength);

    void printW()const override;
};

#endif // KNIGHT_H
