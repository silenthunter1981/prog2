#include "quantity.h"

Quantity::Quantity(float value,
                   const string &unit) :
                   value(value),
                   unit(unit) {}

float Quantity::getValue() const {
    return value;
}

const string &Quantity::getUnit() const {
    return unit;
}
