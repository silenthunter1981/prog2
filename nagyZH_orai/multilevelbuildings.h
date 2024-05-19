#ifndef MULTILEVELBUILDINGS_H
#define MULTILEVELBUILDINGS_H

#include "building.h"

class Multilevelbuildings : public Building
{
    int level;
public:
    Multilevelbuildings(const string& _buildingId,const string& _address,int _alapT,int _epEv,int _level);

    int getLevel()const;

    Multilevelbuildings *clone() const override;
    void print()const override;
    void area()const override;
};

#endif // MULTILEVELBUILDINGS_H
