#include "MultipleCoupon.h"

MultipleCoupon::MultipleCoupon(const string &type,
                               unsigned int value,
                               unsigned int totalUses,
                               bool valid) :
                                Coupon(type,
                                       value),
                                totalUses(totalUses),
                                valid(valid) { }

MultipleCoupon *MultipleCoupon::clone() const {
    return new MultipleCoupon(*this);
}

unsigned int MultipleCoupon::getTotalUses() const {
    return totalUses;
}

void MultipleCoupon::setTotalUses(unsigned int totalUses) {
    MultipleCoupon::totalUses = totalUses;
}

bool MultipleCoupon::isValid() const {
    return valid;
}

void MultipleCoupon::setValid(bool valid) {
    MultipleCoupon::valid = valid;
}
