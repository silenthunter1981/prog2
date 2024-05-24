#ifndef PARTY_H
#define PARTY_H

#include "warriors.h"
#include <string.h>

#include <vector>

class Party
{
    vector<Warriors*> party;
public:
    Party(const string& _txtFile, const string& _tavern);
    
};

#endif // PARTY_H
