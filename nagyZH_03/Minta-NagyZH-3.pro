TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        JsonParser.cpp \
        coupon.cpp \
        coupons/MonthlyCoupon.cpp \
        coupons/MultipleCoupon.cpp \
        coupons/SingleCoupon.cpp \
        main.cpp \
        wallet.cpp

DISTFILES += \
    coupons-1.json \
    coupons-2.json \
    export-example-A.json \
    export-example-B.json \
    minta-stdout.txt \
    purchases.json

HEADERS += \
    JsonParser.h \
    coupon.h \
    coupons/MonthlyCoupon.h \
    coupons/MultipleCoupon.h \
    coupons/SingleCoupon.h \
    json.hpp \
    wallet.h
