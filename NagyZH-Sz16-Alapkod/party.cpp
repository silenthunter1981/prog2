#include "party.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include "tavern.h"
#include "warriors.h"

using namespace std;

Party::Party(const string &_txtFile, const string &_tavern)
{
    ifstream input(_txtFile);
        if (!input.is_open())
        {
            cout << "Cannot open input file" << endl;
            return ;
        }

        string charId;
        input >> charId;
        while (charId!="*")
        {
            Warriors* warrior = _tavern.getWarriorById(charId);
        }


}
