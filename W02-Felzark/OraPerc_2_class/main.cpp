#include <iostream>
using namespace std;

#include "idopont.h"

int main()
{
    // olvassunk be egy egesz szamot (db)
    // hozzunk letre ennyi db idopontot
    // dinamikusan (foglalt memoria)
    // 12:00-tol 9 percenkent, tehat 12:09, 12:16, stb
    // irjuk ki ezeket igy: "12 ora 9 perc"
    int db;
    cin >> db;
    Idopont* tomb = new Idopont[db];
    for (int i=0;i<db;i++)
    {
        // tomb[i] beallitasa
        tomb[i].setOra(12);
        tomb[i].setPerc(9*i); // 0, 9, 18, 27 stb, ahol i=0, 1, 2,
    }
    kiir(tomb,db);

    tomb[0].kiir(); // 12:00
    cout << endl;

    // adjunk hozza 75 percet
    tomb[0].plusz1perc(); // 14:37 -> 14:38, 15:59 -> 16:00, 23:59 -> 00:00
    tomb[0].megnovel(75);

    tomb[0].kiir(); // 13:16
    cout << endl;
    delete[] tomb;

    // Idokezelo_Eszkozok::Idopont* masik;
    // Idopont kezdo;
    // kezdo.ora = 10;
    // kezdo.perc = 32;
    // int lepeskoz = 450;
    // int meret = 9;
    // masik = ujtomb(kezdo,lepeskoz,meret);
    // // kezdo ora, kezdo perc, lepeskoz (percben), hany db idopont
    // kiir(masik,meret);

    // // korabbi(): ket Idopont-ot kap, visszater: bool-lal
    // // hogy korabbi-e az elso idopont, mint a masodik
    // if (korabbi(masik[0],masik[1]))
    // {
    //     kiir(masik[0]);
    //     cout << " korabbi, mint ";
    //     kiir(masik[1]);
    //     cout << endl;
    // }
    // else
    // {
    //     kiir(masik[0]);
    //     cout << " NEM korabbi, mint ";
    //     kiir(masik[1]);
    //     cout << endl;
    // }

    // // napszak(): (minimum AM/PM) egy Idopont-ot kap,
    // // string-et ad vissza

    // cout << napszak(masik[0]) << endl;

    // delete[] masik;

    // cout << "main() vege!" << endl;
    return 0;
}
