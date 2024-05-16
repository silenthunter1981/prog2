#ifndef INC_03_SINGLECOUPON_H
#define INC_03_SINGLECOUPON_H

#include "coupon.h"

class SingleCoupon: public Coupon {
    bool valid;

public:
    SingleCoupon(const string &type,
                 unsigned int value,
                 bool valid = true);

    SingleCoupon *clone() const override;

    bool isValid() const;

    void setValid(bool valid);
};


#endif //INC_03_SINGLECOUPON_H
