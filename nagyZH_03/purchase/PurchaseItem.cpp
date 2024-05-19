#include "PurchaseItem.h"

PurchaseItem::PurchaseItem(const string &name,
                           unsigned int unitPrice,
                           const Quantity &quantity) :
                           name(name),
                           unitPrice(unitPrice),
                           quantity(quantity) {}

const string &PurchaseItem::getName() const {
    return name;
}

unsigned int PurchaseItem::getUnitPrice() const {
    return unitPrice;
}

const Quantity &PurchaseItem::getQuantity() const {
    return quantity;
}
