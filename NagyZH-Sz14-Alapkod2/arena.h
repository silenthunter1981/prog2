#ifndef ARENA_H
#define ARENA_H

#include <string>
#include <iostream>
#include <vector>
#include "json.hpp"
#include "character.h"

using namespace std;

class Arena
{
    vector<Character*> allCharacters;

public:
    ~Arena();
    void load(const string& _jsonFile);
    void print(const string& charId);

    void printAll();
    void performAction(const string& characterI,const string& characterII);


};

#endif // ARENA_H
