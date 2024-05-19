#ifndef SIMPLEBUILDINGS_H
#define SIMPLEBUILDINGS_H

#include "building.h"

class Simplebuildings : public Building
{

public:
    Simplebuildings(const string& _buildingId,const string& _address,int _alapT,int _epEv);

    Simplebuildings *clone() const override;
    void print()const override;
    void area()const override;
};

#endif // SIMPLEBUILDINGS_H
