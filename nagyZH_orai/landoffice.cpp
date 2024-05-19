#include "landoffice.h"
#include "json.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace nlohmann;

// a gyerekosztályok használatához, a neveket lehet módosítani
#include "simplebuildings.h"
#include "multilevelbuildings.h"
#include "buildingswithland.h"
#include "JsonParser.h"

LandOffice::LandOffice(const string &_fileOne, const string &_fileTwo, const string &_fileThree)
{
    loadBuildings(_fileOne, "simple");
    loadBuildings(_fileTwo, "multilevel");
    loadBuildings(_fileThree, "land");
}

void LandOffice::loadBuildings(const string &fileName, const string &type)
{
    json jsonData = JsonParser::loadFromJson(fileName);

    if (!jsonData.is_null()) {


        for (unsigned i = 0; i < jsonData.size(); i++) {
            const json &data = jsonData[i];
            string _bId = data["Id"];
            string _baAdress = data["Address"];
            int _bArea = data["Area"];
            int _bBuiltIn = data ["BuiltIn"];

            Building* buildings = nullptr;

            if (type == "simple") {
                buildings = new Simplebuildings(
                    _bId,
                    _baAdress,
                    _bArea,
                    _bBuiltIn);
            }

            else if (type == "multilevel") {
                buildings = new Multilevelbuildings(
                    _bId,
                    _baAdress,
                    _bArea,
                    _bBuiltIn,
                    data["Levels"]);
            }

            else if (type == "land") {
                buildings = new Buildingswithland(
                    _bId,
                    _baAdress,
                    _bArea,
                    _bBuiltIn,
                    data["LandArea"]);
            }

            if (buildings) {
                LandOffice::addBuilding(buildings->clone());
            }
        }
    }
}

void LandOffice::addBuilding(Building *building)
{
    buildings.push_back(building);
}

void LandOffice::listAll() const
{
    for (unsigned i = 0; i < buildings.size(); i++) {
        buildings[i]->print();
    }
}

void LandOffice::listAreas() const
{
    for (unsigned i = 0; i < buildings.size(); i++) {
        buildings[i]->area();
    }
}

LandOffice::~LandOffice()
{

        for (unsigned i = 0; i < buildings.size(); i++) {
            if (buildings[i]) {
                delete buildings[i];
            }
        }

}








