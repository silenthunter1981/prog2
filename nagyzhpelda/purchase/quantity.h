#ifndef INC_03_QUANTITY_H
#define INC_03_QUANTITY_H

#include <string>
using namespace std;

class Quantity {
    float value;
    string unit;
public:
    Quantity(float value,
             const string &unit);

    float getValue() const;

    const string &getUnit() const;
};


#endif //INC_03_QUANTITY_H
