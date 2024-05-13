#include <iostream>
using namespace std;

namespace Idokezelo_Eszkozok
{

struct Idopont
{
    // string esemeny_leiras;
    int ora, perc;
};

void kiir (const Idopont& p)
{
    cout << p.ora/10 << p.ora%10 << ":";
    cout << p.perc/10 << p.perc%10;
}

void kiir (Idopont* t, int N)
{
    cout << "Idopont tomb (" << N << " elem):" << endl;
    for (int i=0;i<N;i++)
    {
        cout << "  ";
        kiir(t[i]);
        cout << endl;
        // cout << "  " << t[i].ora << " ora ";
        // cout << t[i].perc << " perc" << endl;
    }
}

void plusz1perc (Idopont& p)
{
    p.perc++;
    if (p.perc == 60)
    {
        p.perc = 0;
        p.ora++;
    }
    if (p.ora == 24)
    {
        p.ora = 0;
    }
}

// megnovel(tomb[0],75);
void megnovel (Idopont& p, int mennyi_perccel)
{
    // for (int i=0;i<mennyi_perccel;i++)
    //     plusz1perc(p);

    p.perc += mennyi_perccel;
    if (p.perc >= 60)
    {
        p.ora += p.perc / 60;
        p.perc %= 60; // p.perc = p.perc % 60;
    }
    if (p.ora >= 24)
    {
        p.ora %= 24;
    }
}

// masik = ujtomb(kezdo,lepeskoz,meret);
Idopont* ujtomb (const Idopont& kezdo, int lepeskoz, int meret)
{
    Idopont* t = new Idopont[meret];
    // for (int i=0;i<meret;i++)
    // {
    //     t[i] = kezdo;
    //     megnovel(t[i],lepeskoz*i);
    // }

    t[0] = kezdo; // amennyiben meret>0
    for (int i=1;i<meret;i++) // i=1 fontos
    {
        t[i] = t[i-1];
        megnovel(t[i],lepeskoz);
    }

    return t;
}

// if (korabbi(masik[0],masik[1]))
bool korabbi (const Idopont& p1, const Idopont& p2)
{
    if (p1.ora < p2.ora)
        return true;
    if (p1.ora > p2.ora)
        return false;
    // ezen a ponton biztos, hogy p1.ora==p2.ora
    return p1.perc < p2.perc;
}

// return itt nem const string&, hanem string (masolas)
// azert, mert az eredmeny "helyben konstrualt" ertek (string)
string napszak (const Idopont& p)
{
    if (p.ora <= 5 || p.ora >= 22)
        return "ejszaka";
    if (p.ora <= 9)
        return "reggel";
    if (p.ora <= 11)
        return "delelott";
    if (p.ora <= 17)
        return "delutan";
    return "este";
}

} // namespace Idokezelo_Eszkozok

int main()
{
    using namespace Idokezelo_Eszkozok;
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
        tomb[i].ora = 12;
        tomb[i].perc = 9*i; // 0, 9, 18, 27 stb, ahol i=0, 1, 2,
    }
    kiir(tomb,db);

    kiir(tomb[0]); // 12:00
    cout << endl;

    // adjunk hozza 75 percet
    plusz1perc(tomb[0]); // 14:37 -> 14:38, 15:59 -> 16:00, 23:59 -> 00:00
    megnovel(tomb[0],75);

    kiir(tomb[0]); // 13:16
    cout << endl;
    delete[] tomb;

    Idokezelo_Eszkozok::Idopont* masik;
    Idopont kezdo;
    kezdo.ora = 10;
    kezdo.perc = 32;
    int lepeskoz = 450;
    int meret = 9;
    masik = ujtomb(kezdo,lepeskoz,meret);
    // kezdo ora, kezdo perc, lepeskoz (percben), hany db idopont
    kiir(masik,meret);

    // korabbi(): ket Idopont-ot kap, visszater: bool-lal
    // hogy korabbi-e az elso idopont, mint a masodik
    if (korabbi(masik[0],masik[1]))
    {
        kiir(masik[0]);
        cout << " korabbi, mint ";
        kiir(masik[1]);
        cout << endl;
    }
    else
    {
        kiir(masik[0]);
        cout << " NEM korabbi, mint ";
        kiir(masik[1]);
        cout << endl;
    }

    // napszak(): (minimum AM/PM) egy Idopont-ot kap,
    // string-et ad vissza

    cout << napszak(masik[0]) << endl;

    delete[] masik;

    cout << "main() vege!" << endl;
    return 0;
}
