#include "multilevelbuildings.h"

Multilevelbuildings:: Multilevelbuildings(const string& _buildingId,const string& _address,int _alapT,int _epEv,int _level):
    Building(_buildingId,_address,_alapT,_epEv),
    level(_level)
{}

int Multilevelbuildings::getLevel() const
{
    return level;
}

Multilevelbuildings *Multilevelbuildings::clone() const
{
return new Multilevelbuildings(*this);
}



void Multilevelbuildings::print() const
{
    cout << "Multi level building - " << getBuildingId() << ":  " << getAddress() << ",  " << getAlapT() << "m^2,  built in " << getEpEv() << ",  " << getLevel()<< " levels" << endl;
}

void Multilevelbuildings::area() const
{
    cout << getAddress() << " : " << (getAlapT()*getLevel()) << endl;
}
