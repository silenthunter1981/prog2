#ifndef INC_03_COUPON_H
#define INC_03_COUPON_H

#include <string>
using namespace std;

class Coupon {
    string type;
    unsigned int value;
    bool valid;
public:
    Coupon(const string &type,
           unsigned int value);

    virtual Coupon *clone() const = 0;
    virtual ~Coupon() = default;

    const string &getType() const;
    unsigned int getValue() const;

    void setType(const string &type);
    void setValue(unsigned int value);
};


#endif //INC_03_COUPON_H
