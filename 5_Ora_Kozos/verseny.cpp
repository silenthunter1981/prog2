#include "verseny.h"

Verseny::Verseny(const string &fajlnev)
{
    ifstream input(fajlnev);
    if(!input.is_open()){
        cout << "Cannot open file!" << fajlnev << endl;
        return;
    }
    input >> megnevezes;
    //input.eof();
    string nev;
    double tav;
    bool ervenyes;
    input >> nev;
    while(!input.eof())  //while (nev!=*) lezáró karakteres
    {
        input >> tav >> ervenyes;
        probalkozasok.push_back(Probalkozas(nev,tav,ervenyes));
        input >> nev;
    }
}

/*void Verseny::kiir() const
{
    cout << megnevezes << endl;
    for (unsigned i=0;i<probalkozasok.size();i++){
        cout << probalkozasok[i].getNev() << " "
            << probalkozasok[i].getTavolsag() << " "
            << probalkozasok[i].getErvenyes();
    }
}*/

void Verseny::kiir(const string &fajlnev) const
{

    ofstream output(fajlnev);
    kiir(output);
    /*output << megnevezes << endl;
    for (unsigned i=0;i<probalkozasok.size();i++){
        output << probalkozasok[i].getNev() << " "
             << probalkozasok[i].getTavolsag() << " "
             << probalkozasok[i].getErvenyes();
    }*/
}

void Verseny::kiir(ostream &os) const
{
    os << megnevezes << endl;
    for (unsigned i=0;i<probalkozasok.size();i++){
        os << probalkozasok[i].getNev() << " "
               << probalkozasok[i].getTavolsag() << " "
           << probalkozasok[i].getErvenyes() << endl;
    }
}

void Verseny::uj(string nev, double tavolsag, bool ervenyes)
{
    probalkozasok.push_back(Probalkozas(nev,tavolsag,ervenyes));
}

vector<double> Verseny::ervenyesDobasok()
{
    vector<double> kigyujt;
    for (unsigned i=0;i<probalkozasok.size();i++){
        if (probalkozasok[i].getErvenyes()== 1){
            kigyujt.push_back(probalkozasok[i].getTavolsag()) ;
        }

    }
    return kigyujt;
}
