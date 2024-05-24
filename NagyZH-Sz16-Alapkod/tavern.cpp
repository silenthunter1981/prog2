#include "tavern.h"
#include "json.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace nlohmann;

#include "knight.h"
#include "rangers.h"
#include "mage.h"

void Tavern::loadAll(const string &_fileOne, const string &_fileTwo, const string &_fileThree)
{
    loadWarriors(_fileOne, "Knight");
    loadWarriors(_fileTwo, "Ranger");
    loadWarriors(_fileThree, "Mage");
}

void Tavern::loadWarriors(const string& _jsonFile, const string &type)
{
    ifstream input(_jsonFile);
    if (!input.is_open())
    {
        cout << "Cannot open input karakterek.json" << endl;
        return ;
    }

    json jDatas = json::parse(input);

    for (unsigned i=0; i<jDatas.size(); i++)
    {
        const json &data = jDatas[i];
        if (type == "Knight")
            _warriors.push_back(new Knight(type, data["Id"], data["Price"], data["Strength"]));
        else if (type=="Ranger")
            _warriors.push_back(new Rangers(type,data["Id"], data["Price"], data["Agility"]));
        else if (type =="Mage")
            _warriors.push_back(new Mage(type,data["Id"], data["Price"], data["Magic"]));

    }
}

Warriors *Tavern::getWarriorById(const string &id) const
{
    for (Warriors* warrior : _warriors) {
        if (warrior->getWarId() == id) {
            return warrior;
        }
    }
    return nullptr;
}

Tavern::~Tavern()
{
    for (unsigned i = 0; i < _warriors.size(); i++) {
        if (_warriors[i]) {
                delete _warriors[i];
        }
    }
}

void Tavern::printAll()
{
    for(unsigned int i=0;i<_warriors.size();i++){
        _warriors[i]->printW();
    }
}

