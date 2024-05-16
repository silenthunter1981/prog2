#include "SingleCoupon.h"

SingleCoupon::SingleCoupon(const string &type,
                           unsigned int value,
                           bool valid) :
                            Coupon(type,
                                   value),
                            valid(valid) { }

SingleCoupon *SingleCoupon::clone() const {
    return new SingleCoupon(*this);
}

bool SingleCoupon::isValid() const {
    return valid;
}

void SingleCoupon::setValid(bool valid) {
    SingleCoupon::valid = valid;
}
