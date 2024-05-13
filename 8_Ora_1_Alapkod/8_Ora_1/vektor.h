#ifndef VEKTOR_H
#define VEKTOR_H

#include <cmath>

#include <iostream>

using namespace std;

class Vektor
{
	unsigned int darab;
	double *elemek;

	// meg lehet oldani egy darab vector<double> tárolóval is, ki lehet próbálni, hogy mi változik
public:
	Vektor(unsigned int db);
	Vektor(const Vektor &masik);
	~Vektor();

	unsigned int getDarab() const;
	double getElem(unsigned int index) const;
	void setElem(unsigned int index, double elem);

    Vektor operator +(const Vektor &masik) const;
    Vektor& operator +=(const Vektor &masik);
    friend Vektor operator +(double ertek,const Vektor &vektor);
    Vektor& operator =(const Vektor &masik);
};


#endif // VEKTOR_H
