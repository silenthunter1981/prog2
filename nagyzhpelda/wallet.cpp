#include <iostream>
#include <fstream>
#include "json.hpp"

#include "JsonParser.h"
#include "wallet.h"
#include "coupons/SingleCoupon.h"
#include "coupons/MultipleCoupon.h"
#include "coupons/MonthlyCoupon.h"

Wallet::Wallet() { }

void Wallet::loadCoupons(const string &jsonFile) {
    json jsonData = JsonParser::loadFromJson(jsonFile);

    if (!jsonData.is_null()) {
//        coupons.clear();

        for (unsigned i = 0; i < jsonData.size(); i++) {
            const json &data = jsonData[i];
            string type = data["Type"];

            Coupon* coupon = nullptr;

            if (type == "Single use") {
                coupon = new SingleCoupon(
                        data["Type"],
                        data["Value"]);
            }

            else if (type == "Multiple use") {
                coupon = new MultipleCoupon(
                        data["Type"],
                        data["Value"],
                        data["TotalUses"]);
            }

            else if (type == "Monthly") {
                coupon = new MonthlyCoupon(
                        data["Type"],
                        data["Value"],
                        data["Year"],
                        data["Month"]);
            }

            if (coupon) {
                Wallet::addCoupon(coupon->clone());
            }
        }
    }
}

void Wallet::addCoupon(Coupon *coupon) {
    coupons.push_back(coupon);
}

Wallet::~Wallet() {
    for (unsigned i = 0; i < coupons.size(); i++) {
        if (coupons[i]) {
            delete coupons[i];
        }
    }
}

vector<Coupon *> &Wallet::getCoupons() {
    return coupons;
}

void Wallet::exportCounts(const string &filename) {
    ofstream file(filename);
    json jsonData;

    vector <Coupon*> coupons = this->getCoupons();

    unsigned int singleUseValid = 0;
    unsigned int singleUseInValid = 0;

    unsigned int multipleUseValid = 0;
    unsigned int multipleUseInValid = 0;

    unsigned int monthlyValid = 0;
    unsigned int monthlyInValid = 0;

    for (unsigned i = 0; i < coupons.size(); i++) {
        if (coupons[i]->getType() == "Single use") {
            SingleCoupon* singleCoupon = dynamic_cast<SingleCoupon*>(coupons[i]);

            if (singleCoupon->isValid()) {
                singleUseValid++;
            }
            else {
                singleUseInValid++;
            }
        }

        else if (coupons[i]->getType() == "Multiple use") {
            MultipleCoupon* multipleCoupon = dynamic_cast<MultipleCoupon*>(coupons[i]);

            if (multipleCoupon->isValid()) {
                multipleUseValid++;
            }
            else {
                multipleUseInValid++;
            }
        }

        else if (coupons[i]->getType() == "Monthly") {
            MonthlyCoupon* monthlyCoupon = dynamic_cast<MonthlyCoupon*>(coupons[i]);

            if (monthlyCoupon->isValid()) {
                monthlyValid++;
            }
            else {
                monthlyInValid++;
            }
        }
    }

    jsonData["Monthly"] = {
        {"Valid", monthlyValid},
        {"Invalid", monthlyInValid}
    };

    jsonData["Multiple use"] = {
            {"Valid", multipleUseValid},
            {"Invalid", multipleUseInValid}
    };

    jsonData["Single use"] = {
            {"Valid", singleUseValid},
            {"Invalid", singleUseInValid}
    };

    file << jsonData.dump(4);
}