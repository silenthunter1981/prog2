#include "idopont.h"

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
