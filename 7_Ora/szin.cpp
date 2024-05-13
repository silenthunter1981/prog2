#include "szin.h"

Szin::~Szin(){
}

char Szin::szamotHexava(int szam)
{
    if(szam >= 0 && szam <= 9){
        return szam + '0';
    }
    else if(szam >= 10 && szam <= 15){
        return szam - 10 + 'A';
    }
    else return 0;
}
int Szin::hexatSzamma(char hexa){
    if(hexa >= '0' && hexa <= '9' ){
        return hexa - '0';
    }
    else if(hexa >= 'A' && hexa <= 'F' ){
        return hexa -'A' + 10;
    }
    else return 0;
}
string Szin::printCode() const{
    unsigned r=R(), g=G(), b=B();
    string ertek = "#";
    ertek+=szamotHexava(r/16);
    ertek+=szamotHexava(r%16);
    ertek+=szamotHexava(g/16);
    ertek+=szamotHexava(g%16);
    ertek+=szamotHexava(b/16);
    ertek+=szamotHexava(b%16);

    return ertek;
}
bool Szin::megegyezik(const Szin &sz) const{
    return (R()==sz.R() && G()==sz.G() && B()==sz.B());
}
