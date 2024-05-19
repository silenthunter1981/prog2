#ifndef LANDOFFICE_H
#define LANDOFFICE_H

#include "building.h"
#include <vector>
#include "json.hpp"

class LandOffice
{
    vector <Building*> buildings;
public:
    LandOffice(const string& _fileOne,const string& _fileTwo,const string& _fileThree);
    void loadBuildings(const string& fileName,const string& type);
    void addBuilding(Building* building);
    void listAll()const;
    void listAreas()const;

    ~LandOffice();



};

#endif // LANDOFFICE_H
