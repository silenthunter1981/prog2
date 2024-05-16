#include "coupon.h"

Coupon::Coupon(const string &type,
               unsigned int value):
                type(type),
                value(value) { }


const string &Coupon::getType() const {
    return type;
}

unsigned int Coupon::getValue() const {
    return value;
}


void Coupon::setType(const string &type) {
    Coupon::type = type;
}

void Coupon::setValue(unsigned int value) {
    Coupon::value = value;
}