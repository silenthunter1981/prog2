#include "simplebuildings.h"

Simplebuildings::Simplebuildings(const string &_buildingId, const string &_address, int _alapT, int _epEv):
    Building(_buildingId,_address,_alapT,_epEv)
{

}

Simplebuildings *Simplebuildings::clone() const
{
    return new Simplebuildings(*this);
}

void Simplebuildings::print() const
{
    cout << "Simple building - " << getBuildingId() << ":  " << getAddress() << ",  " << getAlapT() << "m^2,  built in " << getEpEv() << endl;
}

void Simplebuildings::area() const
{
    cout << getAddress() << " : " << getAlapT() << endl;
}
