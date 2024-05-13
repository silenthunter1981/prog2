#include "idopont.h"
using namespace Idokezelo_Eszkozok;

Idopont::Idopont()
{
}

void Idopont::setOra(int ora)
{
    this->ora = ora;
}

void Idopont::setPerc(int perc)
{
    this->perc = perc;
}

void Idopont::kiir() const
{
    cout << ora/10 << ora%10 << ":";
    cout << perc/10 << perc%10;
}

void Idopont::plusz1perc()
{
    perc++;
    if (perc == 60)
    {
        perc = 0;
        ora++;
    }
    if (ora == 24)
    {
        ora = 0;
    }
}

void Idopont::megnovel(int mennyi_perccel)
{
    perc += mennyi_perccel;
    if (perc >= 60)
    {
        ora += perc / 60;
        perc %= 60; // p.perc = p.perc % 60;
    }
    if (ora >= 24)
    {
        ora %= 24;
    }
}

Idopont* Idopont::ujtomb(int lepeskoz, int meret) const
{
    Idopont* t = new Idopont[meret];
    // for (int i=0;i<meret;i++)
    // {
    //     t[i] = *this;
    //     megnovel(t[i],lepeskoz*i);
    // }

    t[0] = *this; // amennyiben meret>0
    for (int i=1;i<meret;i++) // i=1 fontos
    {
        t[i] = t[i-1];
        t[i].megnovel(lepeskoz);
    }

    return t;
}

bool Idopont::korabbi(const Idopont& p2) const
{
    if (ora < p2.ora)
        return true;
    if (ora > p2.ora)
        return false;
    // ezen a ponton biztos, hogy ora==p2.ora
    return perc < p2.perc;
}

string Idopont::napszak() const
{
    if (ora <= 5 || ora >= 22)
        return "ejszaka";
    if (ora <= 9)
        return "reggel";
    if (ora <= 11)
        return "delelott";
    if (ora <= 17)
        return "delutan";
    return "este";
}

namespace Idokezelo_Eszkozok
{

void kiir(Idopont* t, int N)
{
    cout << "Idopont tomb (" << N << " elem):" << endl;
    for (int i=0;i<N;i++)
    {
        cout << "  ";
        t[i].kiir();
        cout << endl;
    }
}

} // namespace Idokezelo_Eszkozok
