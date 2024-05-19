#ifndef BUILDINGSWITHLAND_H
#define BUILDINGSWITHLAND_H

#include "building.h"

class Buildingswithland : public Building
{
    int kert;
public:
    Buildingswithland(const string& _buildingId,const string& _address,int _alapT,int _epEv,int _kert);

    int getKert()const;
    Buildingswithland *clone() const override;

    void print()const override;
    void area()const override;
};

#endif // BUILDINGSWITHLAND_H
