#include <iostream>
//#include <fstream> // nincs most ra szukseg
#include "datumlista.h"

using namespace std;
using namespace Naptar;

void datumListaKiir(const DatumLista &dl)
{
    cout << dl.getMegjegyzes() << endl;
    for (unsigned int i=0; i<dl.getDarab(); i++)
    {
        const Datum &d=dl.getDatum(i); // Azért, hogy ne kelljen mindig leírni a gettert
        cout << "  " << i+1 << ". datum: " << d.getEv() << "." << d.getHonap() << "." << d.getNap() << endl;
    }
}

int main()
{
    // Létrehozás
    cout << "Kerek egy megjegyzest: ";
    string megj;
    getline(cin, megj);
    DatumLista dl1(3, megj);
    cout << dl1.getMegjegyzes() << endl;
    dl1.setMegjegyzes("At is allitom");
    cout << dl1.getMegjegyzes() << endl;

    // Dátumok bekérése és beállítása
    cout << endl;
    dl1.setDatum(10000, Datum(1,1,1)); // Ez nem csinál semmit
    for (unsigned int i=0; i<dl1.getDarab(); i++)
    {
        unsigned int e, h, n;
        cout << "Kerek egy datumot (ev, honap, nap): ";
        cin >> e >> h >> n;
        dl1.setDatum(i, Datum(e,h,n));
    }
    datumListaKiir(dl1);

    // Másolat készítése
    cout << endl;
    DatumLista dl2(dl1);
    datumListaKiir(dl1);
    datumListaKiir(dl2);
    dl2.setMegjegyzes("Ez a masodik");
    dl2.setDatum(0,Datum(1900,1,1));
    datumListaKiir(dl1);
    datumListaKiir(dl2);

    // Hozzáadás és legkorábbi
    cout << endl;
    dl1.hozzaad(Datum(2018,10,10));
    dl1.hozzaad(Datum(2019,11,11));
    datumListaKiir(dl1);
    const Datum &legkorabbi=dl1.legkorabbi();
    cout << "A legkorabbi datum: " << legkorabbi.getEv() << "." << legkorabbi.getHonap() << "." << legkorabbi.getNap() << endl;

    // Statikus max darabszám
    cout << "Max meret: " << DatumLista::getMaxDarab() << endl;
    dl1.hozzaad(Datum(2025,2,5)); // Ez még belefér
    dl1.hozzaad(Datum(2030,12,23)); // Ez már nem
    datumListaKiir(dl1);
    DatumLista::setMaxDarab(8);
    cout << "Max meret: " << DatumLista::getMaxDarab() << endl;
    dl1.hozzaad(Datum(2012,6,18)); // Mostmár belefér
    dl1.hozzaad(Datum(2015,7,30)); // Mostmár belefér
    dl1.hozzaad(Datum(2017,2,21)); //Ez már nem
    datumListaKiir(dl1);
    DatumLista::setMaxDarab(5);
    cout << "Max meret: " << DatumLista::getMaxDarab() << endl;
    dl2.hozzaad(Datum(2025,2,5)); // Ez még belefér
    dl2.hozzaad(Datum(2025,8,25)); // Ez még belefér
    dl2.hozzaad(Datum(2030,12,23)); // Ez már nem
    datumListaKiir(dl2);

	return 0;
}
