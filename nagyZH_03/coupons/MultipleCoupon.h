#ifndef INC_03_MULTIPLECOUPON_H
#define INC_03_MULTIPLECOUPON_H

#include "coupon.h"

class MultipleCoupon: public Coupon {
    unsigned int totalUses;
    bool valid;

public:
    MultipleCoupon(const string &type,
                   unsigned int value,
                   unsigned int totalUses,
                   bool valid = true);

    MultipleCoupon *clone() const override;

    unsigned int getTotalUses() const;
    void setTotalUses(unsigned int totalUses);

    bool isValid() const;

    void setValid(bool valid);
};


#endif //INC_03_MULTIPLECOUPON_H
