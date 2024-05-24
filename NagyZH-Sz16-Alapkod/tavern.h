#ifndef TAVERN_H
#define TAVERN_H

#include "warriors.h"
#include <vector>
#include "json.hpp"
#include <string.h>

class Tavern
{
    vector <Warriors*> _warriors;
public:
    void loadAll(const string& _fileOne,const string& _fileTwo,const string& _fileThree);
    void loadWarriors(const string& _jsonFile,const string& type);
    Warriors *getWarriorById(const string& id) const;
    void printAll();
    ~Tavern();
};

#endif // TAVERN_H
