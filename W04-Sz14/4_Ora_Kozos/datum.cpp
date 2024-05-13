#include "datum.h"

Datum::Datum(unsigned int _ev, unsigned int _honap, unsigned int _nap):
	ev(_ev),
	honap(_honap),
	nap(_nap)
{
}

unsigned int Datum::getEv() const
{
	return ev;
}

void Datum::setEv(unsigned int value)
{
	ev = value;
}

unsigned int Datum::getHonap() const
{
	return honap;
}

void Datum::setHonap(unsigned int value)
{
	honap = value;
}

unsigned int Datum::getNap() const
{
	return nap;
}

void Datum::setNap(unsigned int value)
{
    nap = value;
}

// return: true, ha a "this" korabbi, mint a masik
bool Datum::korabbiMint(const Datum &masik) const
{
    // eredeti: ev, honap, nap
    // masik: masik.ev, masik.honap, masik.nap
    if (ev < masik.ev)
        return true;
    if (ev > masik.ev)
        return false;
    // ezen ponton biztos, hogy ev == masik.ev
    if (honap < masik.honap)
        return true;
    if (honap > masik.honap)
        return false;
    // ezen a ponton biztos, hogy ev es honap is egyenlo
    return nap < masik.nap;
}
