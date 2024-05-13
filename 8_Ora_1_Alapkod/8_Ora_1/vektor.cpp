#include "vektor.h"

Vektor::Vektor(unsigned int db):
	darab(db)
{
	elemek=new double[darab];
}

Vektor::Vektor(const Vektor &masik):
	darab(masik.darab)
{
	elemek=new double[darab];
	for (unsigned int i=0; i<darab; i++)
		elemek[i]=masik.elemek[i];
}

Vektor::~Vektor()
{
	delete [] elemek;
}

unsigned int Vektor::getDarab() const
{
	return darab;
}

double Vektor::getElem(unsigned int index) const
{
	return elemek[index];
}

void Vektor::setElem(unsigned int index, double elem)
{
	elemek[index]=elem;
}

Vektor Vektor::operator +(const Vektor &masik) const
{
    if (darab==masik.darab)
    {
        Vektor eredmeny(darab);
        for (unsigned int i=0; i<darab; i++)
        {
            eredmeny.elemek[i]=elemek[i]+masik.elemek[i];
        }
        return eredmeny;
    }
    else
    {
        return *this;
    }
}

Vektor &Vektor::operator +=(const Vektor &masik){

    if(darab==masik.darab){
        for (unsigned int i=0; i < darab; i++)
        {
            elemek[i]+=masik.elemek[i];
        }
        return *this;
    }
    else{
        return *this;
    }
}

Vektor operator +(double ertek, const Vektor &vektor){

    Vektor visszaad(vektor.darab);
    for(unsigned int i=0; i < vektor.darab; i++){
        visszaad.elemek[i]=vektor.elemek[i]+ertek;
    }
    return visszaad;
}

Vektor &Vektor::operator =(const Vektor &masik){

    // Vektor visszaad(masik.darab); //így nem lehet!!!!
    // for (unsigned int i = 0; i < masik.darab; ++i) {
    //     visszaad.elemek[i]=masik.elemek[i];
    // }
    // return visszaad;

    if(this!=&masik){

        delete [] elemek;
        darab=masik.darab;
        elemek=new double[darab];
        for(unsigned int i=0;i<darab;i++){
            elemek[i]=masik.elemek[i];
        }
        return *this;
    }
    else return *this;
}
