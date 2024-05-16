#include <iostream>
#include <fstream>
#include "json.hpp"
using namespace nlohmann;

#include "JsonParser.h"

json JsonParser::loadFromJson(const string &jsonFile) {
    ifstream input(jsonFile);

    if (!input.is_open()) {
        cout << "Nem sikerult megnyitni: " << jsonFile << endl;
        return nullptr;
    }

    json jsonData = json::parse(input);
    return jsonData;
}
