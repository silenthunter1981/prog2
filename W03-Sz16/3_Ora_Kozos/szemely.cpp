#include "szemely.h"

#include <iostream>

Szemely::Szemely(const string &v, const string &k, unsigned int kor):
	vnev(v),
	knev(k),
	eletkor(kor)
{
}

string Szemely::getVezetekNev() const
{
	return vnev;
}

const string &Szemely::getKeresztNev() const
{
	return knev;
}

string Szemely::teljesNev() const
{
    string eredmeny = vnev + " " + knev;
    return eredmeny; // Figyelem: itt a művelet új változót hoz létre, ami megszűnik a függvény végén. Így nem lehet referenciával visszatérni.
}

unsigned int Szemely::getEletkor() const
{
	return eletkor;
}

void Szemely::kiir() const
{
    cout << vnev << " " << knev << ": " << eletkor << endl;
}

bool Szemely::fiatalabb(const Szemely &masik) const
{
    return eletkor < masik.eletkor;
}
