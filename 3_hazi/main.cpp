#include <iostream>
#include <string>

using namespace std;

class Jarmu
{
    string tipus;
    int gyartasEve;
public:
    Jarmu(const string &tipus, int gyartasEve):
        tipus(tipus),
        gyartasEve(gyartasEve)
    {}
    string getTipus() const{
        return tipus;
    }
    int getGyartasEve() const{
        return gyartasEve;
    }
    void kiir() const{
        cout << "tipus: " << tipus;
        cout << ", gyartva: " << gyartasEve;
        cout << endl;
    }
};

void jarmuKiir(const Jarmu &j){
    cout << j.getTipus() << " " << j.getGyartasEve() << endl;
}
// innen
class Kocsi : public Jarmu
{
    int ajtok;
public:
    Kocsi(int pgyartasEve,int pajtok):
        Jarmu("kocsi",pgyartasEve),
        ajtok(pajtok)
    {}
   void kiir () const{
       cout << "tipus: " <<  Jarmu::getTipus() << ", gyartva: " << Jarmu::getGyartasEve() << ", ajtok: " << ajtok << endl;
    }
};

class Repulo : public Jarmu
{
    int magassag;
public:
    Repulo(int pgyartasEve, int pmagassag):
        Jarmu("repulo",pgyartasEve),
        magassag(pmagassag)
    {}
    void kiir () const{
         cout << "tipus: " <<  Jarmu::getTipus() << ", gyartva: " << Jarmu::getGyartasEve() << ", magassag: " << magassag << endl;
    }
};





int main()
{
Kocsi k1(1996, 4);
Kocsi k2(2012, 2);
Repulo r1(1980, 1230);
Repulo r2(2001, 3200);
k1.kiir(); // tipus: kocsi, gyartva: 1996, ajtok: 4
k2.kiir(); // tipus: kocsi, gyartva: 2012, ajtok: 2
r1.kiir(); // tipus: repulo, gyartva: 1980, magassag: 1230
r2.kiir(); // tipus: repulo, gyartva: 2001, magassag: 3200
 cout << endl;
jarmuKiir(k1); // kocsi 1996
jarmuKiir(k2); // kocsi 2012
jarmuKiir(r1); // repulo 1980
jarmuKiir(r2); // repulo 2001
return 0;
}
