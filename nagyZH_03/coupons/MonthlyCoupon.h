#ifndef INC_03_MONTHLYCOUPON_H
#define INC_03_MONTHLYCOUPON_H

#include "coupon.h"

class MonthlyCoupon: public Coupon {
    unsigned int year;
    unsigned int month;
    bool valid;

public:
    static int currentYear;
    static int currentMonth;
    static int currentDay;

    MonthlyCoupon(const string &type,
                  unsigned int value,
                  unsigned int year,
                  unsigned int month,
                  bool valid = true);

    MonthlyCoupon *clone() const override;

    unsigned int getYear() const;
    unsigned int getMonth() const;

    void setYear(unsigned int year);
    void setMonth(unsigned int month);

    static void setCurrentDate(int year, int month, int day);
    bool isValid();

//    bool isValid() const;
//    void setValid(bool valid);
};


#endif //INC_03_MONTHLYCOUPON_H
