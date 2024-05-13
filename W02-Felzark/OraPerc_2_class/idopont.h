#ifndef IDOPONT_H
#define IDOPONT_H

#include <iostream>
using namespace std;

class Idopont
{
    int ora, perc;
public:
    Idopont();

    void setOra (int ora);
    void setPerc (int perc);

    void kiir () const;

    void plusz1perc ();

    void megnovel (int mennyi_perccel);
};

void kiir (Idopont* t, int N);

#endif // IDOPONT_H
