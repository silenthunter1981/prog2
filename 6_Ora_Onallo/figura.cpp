#include "figura.h"
#include "iostream"



Figura::Figura(const string &pos):
	pozicio(pos)
{
}

const string &Figura::getPozicio() const
{
    return pozicio;
}


bool Figura::ervenyes(string pozicio){


    if(pozicio.size() == 2){
        if(pozicio[0]< 'I' && pozicio[0] >= 'A' && pozicio[1] < '9' && pozicio[1] > '0'){
            return true;
        }
        return false;
    }
    else return false;
}
