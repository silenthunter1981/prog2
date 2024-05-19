#include "building.h"

Building::Building(const string &_buildingId, const string &_address, int _alapT, int _epEv):
    buldingId(_buildingId),
    address(_address),
    alapT(_alapT),
    epEv(_epEv)
{

}

const string &Building::getBuildingId() const
{
    return buldingId;
}

const string &Building::getAddress() const
{
    return address;
}

void Building::setBuildingId(const string &_builingId)
{
    buldingId =_builingId;
}

void Building::setAddress(const string &_address)
{
    address = _address;
}

void Building::setAlapT(int _alapT)
{
    alapT = _alapT;
}

void Building::setEpEv(int _epEv)
{
    epEv = _epEv;
}

const int &Building::getAlapT() const
{
    return alapT;
}

const int &Building::getEpEv() const
{
    return  epEv;
}

/*void Building::print()
{
    cout << getBuildingId() << " " << getAddress() << " " << getAlapT() << " " << getEpEv() << endl;
}*/
