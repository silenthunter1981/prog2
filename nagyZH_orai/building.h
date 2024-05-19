#ifndef BUILDING_H
#define BUILDING_H

#include <string>
#include <iostream>
#include <vector>


using namespace std;

class Building
{
    string buldingId;
    string address;
    int alapT;
    int epEv;
public:
    Building(const string& _buildingId,const string& _address,int _alapT,int _epEv);
    virtual ~Building()= default;
    const string& getBuildingId()const;
    const string& getAddress()const;
    void setBuildingId(const string& _builingId);
    void setAddress(const string &_address);
    void setAlapT(int _alapT);
    void setEpEv(int _epEv);
    const int &getAlapT()const;
    const int& getEpEv()const;


    virtual void print()const =0;
    virtual Building *clone() const = 0;
    virtual void area()const =0;
};


#endif // BUILDING_H
