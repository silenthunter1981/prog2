#ifndef INC_03_JSONPARSER_H
#define INC_03_JSONPARSER_H

#include <string>
#include "json.hpp"

using namespace std;
using namespace nlohmann;

class JsonParser {
public:
    static json loadFromJson(const string &jsonFile);
};


#endif //INC_03_JSONPARSER_H
