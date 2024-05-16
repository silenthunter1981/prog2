#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include "purchase.h"
#include "JsonParser.h"

#include "coupons/SingleCoupon.h"
#include "coupons/MultipleCoupon.h"
#include "coupons/MonthlyCoupon.h"

#include "purchase/PurchaseItem.h"
#include "purchase/quantity.h"

Purchase::Purchase(const string &jsonFile) {
    json jsonData = JsonParser::loadFromJson(jsonFile);

    if (!jsonData.is_null()) {
        items.clear();

        for (unsigned i = 0; i < jsonData.size(); i++) {
            const json &data = jsonData[i];

            Quantity quantity(data["Quantity"]["Value"],
                                data["Quantity"]["Unit"]);

            items.push_back({data["Name"],
                             data["UnitPrice"],
                             quantity});
        }
    }
}

void Purchase::print() const {
    for (unsigned i = 0; i < items.size(); i++) {
        PurchaseItem item = items[i];
        Quantity quantity = items[i].getQuantity();

        cout << "[" << item.getName() << ", "
            << item.getUnitPrice() << " x "
            << quantity.getValue() << " "
            << quantity.getUnit() << "]"
            << endl;
    }
}

unsigned int Purchase::getTotal() {
    unsigned int sum = 0;

    for (unsigned i = 0; i < items.size(); i++) {
        PurchaseItem item = items[i];
        Quantity quantity = items[i].getQuantity();
        sum += item.getUnitPrice() * quantity.getValue();
    }

    return sum;
}

unsigned int Purchase::useCoupons(Wallet &wallet) {
    unsigned int sum = Purchase::getTotal();
    vector <Coupon*> &coupons = wallet.getCoupons();

    for (unsigned i = 0; i < coupons.size(); i++) {
        if (coupons[i]->getType() == "Single use") {
            SingleCoupon* singleCoupon = dynamic_cast<SingleCoupon*>(coupons[i]);
            if (singleCoupon->isValid()) {
                sum -= singleCoupon->getValue();
                singleCoupon->setValid(false);
            }
        }

        else if (coupons[i]->getType() == "Multiple use") {
            MultipleCoupon* multipleCoupon = dynamic_cast<MultipleCoupon*>(coupons[i]);

            if (multipleCoupon->isValid()) {
                sum -= multipleCoupon->getValue();
                multipleCoupon->setTotalUses(multipleCoupon->getTotalUses()-1);

                if (multipleCoupon->getTotalUses() == 0) {
                    multipleCoupon->setValid(false);
                }
            }
        }

        else if (coupons[i]->getType() == "Monthly") {
            MonthlyCoupon* monthlyCoupon = dynamic_cast<MonthlyCoupon*>(coupons[i]);

            if (monthlyCoupon->isValid()) {
                sum -= monthlyCoupon->getValue();
            }
        }
    }

    return sum;
}