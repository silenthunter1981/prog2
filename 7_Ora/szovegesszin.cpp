#include "szovegesszin.h"

SzovegesSzin::SzovegesSzin(const string &sz):
    szinnev(sz)
{
    if(szinnev=="fekete"){
        r=0;
        g=0;
        b=0;
    }
    else if(szinnev=="feher"){
        r=255;
        g=255;
        b=255;
    }
    else if(szinnev=="kek"){
        r=0;
        g=0;
        b=255;
    }
    else if(szinnev=="zold"){
        r=0;
        g=255;
        b=0;
    }
    else if(szinnev=="piros"){
        r=255;
        g=0;
        b=0;
    }
    else if(szinnev=="cian"){
        r=0;
        g=255;
        b=255;
    }
    else if(szinnev=="magenta"){
        r=255;
        g=0;
        b=255;
    }
    else if(szinnev=="sarga"){
        r=255;
        g=255;
        b=0;
    }
    else if(szinnev[0]=='#' && szinnev.length()>=7){
        r=hexatSzamma(szinnev[1])*16+hexatSzamma(szinnev[2]);
        g=hexatSzamma(szinnev[3])*16+hexatSzamma(szinnev[4]);
        b=hexatSzamma(szinnev[5])*16+hexatSzamma(szinnev[6]);
    }
    else {
        szinnev="fekete";
        r=0;
        g=0;
        b=0;
    }


}
string SzovegesSzin::printCode() const{
    return szinnev;
}
