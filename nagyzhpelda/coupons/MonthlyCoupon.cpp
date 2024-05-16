#include "MonthlyCoupon.h"

int MonthlyCoupon::currentYear = 2024;
int MonthlyCoupon::currentMonth = 5;
int MonthlyCoupon::currentDay = 1;

MonthlyCoupon::MonthlyCoupon(const string &type,
                             unsigned int value,
                             unsigned int year,
                             unsigned int month,
                             bool valid) :
                                Coupon(type,
                                       value),
                             year(year),
                             month(month),
                             valid(valid) {}

MonthlyCoupon *MonthlyCoupon::clone() const {
    return new MonthlyCoupon(*this);
}

unsigned int MonthlyCoupon::getYear() const {
    return year;
}

void MonthlyCoupon::setYear(unsigned int year) {
    MonthlyCoupon::year = year;
}

unsigned int MonthlyCoupon::getMonth() const {
    return month;
}

void MonthlyCoupon::setMonth(unsigned int month) {
    MonthlyCoupon::month = month;
}

void MonthlyCoupon::setCurrentDate(int year, int month, int day) {
    MonthlyCoupon::currentYear = year;
    MonthlyCoupon::currentMonth = month;
    MonthlyCoupon::currentDay = day;
}

bool MonthlyCoupon::isValid() {
    if (MonthlyCoupon::getYear() != currentYear) {
        return false;
    }

    if (MonthlyCoupon::getMonth() != currentMonth) {
        return false;
    }

    return true;
}