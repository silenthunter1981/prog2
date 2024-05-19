#include "buildingswithland.h"

Buildingswithland::Buildingswithland(const string& _buildingId,const string& _address,int _alapT,int _epEv,int _kert):
    Building(_buildingId,_address,_alapT,_epEv),
    kert(_kert)
{}

int Buildingswithland::getKert() const
{
    return kert;
}

Buildingswithland *Buildingswithland::clone() const
{
return new Buildingswithland(*this);
}

void Buildingswithland::print() const
{
    cout << "Building with land - " << getBuildingId() << ":  " << getAddress() << ",  " << getAlapT() << "m^2,  built in " << getEpEv() << ",  " << getKert() << "m^2" << endl;
}

void Buildingswithland::area() const
{
    cout << getAddress() << " : " << (getAlapT()+getKert()) << endl;
}
