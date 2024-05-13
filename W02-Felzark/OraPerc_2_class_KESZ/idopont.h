#ifndef IDOPONT_H
#define IDOPONT_H

#include <iostream>
using namespace std;

namespace Idokezelo_Eszkozok
{

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

    // a kezdo idopont az aktualis objektum (this)
    Idopont* ujtomb (int lepeskoz, int meret) const;

    bool korabbi (const Idopont& p2) const;
    string napszak () const;
};

void kiir (Idopont* t, int N);

} // namespace Idokezelo_Eszkozok

#endif // IDOPONT_H
