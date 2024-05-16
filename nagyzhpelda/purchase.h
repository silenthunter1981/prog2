#ifndef INC_03_PURCHASE_H
#define INC_03_PURCHASE_H

#include <string>
using namespace std;

#include "wallet.h"
#include "purchase/PurchaseItem.h"

class Purchase {
    vector <PurchaseItem> items;

public:
    Purchase(const string &jsonFile);

    void print() const;
    unsigned int getTotal();
    unsigned int useCoupons(Wallet &wallet);
};


#endif //INC_03_PURCHASE_H
