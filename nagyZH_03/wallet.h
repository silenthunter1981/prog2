#ifndef INC_03_WALLET_H
#define INC_03_WALLET_H

#include <string>
#include <vector>

#include "json.hpp"
#include "coupon.h"

using namespace std;
using namespace nlohmann;

class Wallet {
public:
    vector <Coupon*> coupons;

    Wallet();
    ~Wallet();

    void loadCoupons(const string &jsonFile);
    void addCoupon(Coupon* coupon);

    template<typename T>
    unsigned int countCoupons(bool valid = false) const {
        int count = 0;

        for (unsigned i = 0; i < this->coupons.size(); i++) {
            T* coupon = dynamic_cast<T*>(this->coupons[i]);

            if (coupon && (!valid || coupon->isValid())) {
                count++;
            }
        }

        return count;
    }

    void exportCounts(const string& filename);

    vector<Coupon *> &getCoupons();
};


#endif //INC_03_WALLET_H
