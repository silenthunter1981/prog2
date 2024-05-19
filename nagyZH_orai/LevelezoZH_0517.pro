TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
		building.cpp \
    buildingswithland.cpp \
    jsonparser.cpp \
        landoffice.cpp \
		main.cpp \
    multilevelbuildings.cpp \
    simplebuildings.cpp

HEADERS += \
	building.h \
    buildingswithland.h \
    json.hpp \
    jsonparser.h \
	landoffice.h \
    multilevelbuildings.h \
    simplebuildings.h

DISTFILES += \
    buildingswithland.json \
    minta-stdout.txt \
    multilevelbuildings.json \
    renovations.json \
    simplebuildings.json
