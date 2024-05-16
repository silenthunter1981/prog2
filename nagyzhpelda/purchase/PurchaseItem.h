#ifndef INC_03_PURCHASEITEM_H
#define INC_03_PURCHASEITEM_H

#include <string>
using namespace std;

#include "purchase/quantity.h"

class PurchaseItem {
    string name;
    unsigned int unitPrice;
    Quantity quantity;
public:
    PurchaseItem(const string &name,
                 unsigned int unitPrice,
                 const Quantity &quantity);

    const string &getName() const;

    unsigned int getUnitPrice() const;

    const Quantity &getQuantity() const;
};


#endif //INC_03_PURCHASEITEM_H
