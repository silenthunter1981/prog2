TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        dragon.cpp \
        knight.cpp \
        mage.cpp \
        main.cpp \
        party.cpp \
        rangers.cpp \
        tavern.cpp \
        warriors.cpp

HEADERS += \
    dragon.h \
    json.hpp \
    knight.h \
    mage.h \
    party.h \
    rangers.h \
    tavern.h \
    warriors.h

DISTFILES += \
    in-knights.json \
    in-mages.json \
    in-party-1.txt \
    in-party-2.txt \
    in-party-3.txt \
    in-rangers.json \
    minta-stdout.txt
