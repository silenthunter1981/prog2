#ifndef UTAZAS_H
#define UTAZAS_H
#include <iostream>
using namespace std;

class Utazas
{
private:
    string nev;
    string leiras;
    int napokSzama;

public:
    Utazas(const string &nev,const string &leiras,int napokSzama);
    ~Utazas();
    void setName(const string &utNev);
    string getName()const;
    void setLeiras(const string &utLeiras);
    string getLeiras() const;
    void setNapokSzama(int &utNapokSzama);
    int getNapokSzama() const;

    virtual void kiir()const =0;
};

#endif // UTAZAS_H
