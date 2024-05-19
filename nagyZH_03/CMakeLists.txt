cmake_minimum_required(VERSION 3.28)
project(03)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(03
        json.hpp
        main.cpp
        coupon.h
        coupon.cpp
        purchase.h
        coupons/MonthlyCoupon.h
        coupons/MonthlyCoupon.cpp
        coupons/MultipleCoupon.h
        coupons/MultipleCoupon.cpp
        coupons/SingleCoupon.h
        coupons/SingleCoupon.cpp
        wallet.cpp
        wallet.h
        purchase.cpp
        JsonParser.cpp
        JsonParser.h
        purchase/quantity.cpp
        purchase/quantity.h
        purchase/PurchaseItem.cpp
        purchase/PurchaseItem.h)
