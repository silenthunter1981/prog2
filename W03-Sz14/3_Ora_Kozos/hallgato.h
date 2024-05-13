#ifndef HALLGATO_H
#define HALLGATO_H

#include "szemely.h"

class Hallgato : public Szemely
{
    string neptun;
    unsigned int felevek;
public:
    Hallgato(const string& vnev,
             const string& knev,
             unsigned int eletkor,
             const string& neptun,
             unsigned int felevek=1);
    string getNeptunCode() const;
    unsigned int getFelevek() const;
    void setFelevek(unsigned int newFelevek);

    void kiir () const;

    bool furcsa () const;
};

#endif // HALLGATO_H
