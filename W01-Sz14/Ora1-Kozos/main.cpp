#include <iostream>
#include <string>
using namespace std;

namespace doboz
{

struct Doboz
{
    string nev;
    unsigned int sz, m, h;
};

// kiirDobozTomb(tomb, N);
void kiirDobozTomb (Doboz* t, int meret)
{
    cout << "Dobozok (" << meret << " darab):" << endl;
    for (int i=0;i<meret;i++)
    {
        cout << "  " << t[i].nev << ": ";
        cout << t[i].sz << " x ";
        cout << t[i].m << " x ";
        cout << t[i].h << endl;
    }
}

// kiirFelszinTerfogat(tomb[0]);
void kiirFelszinTerfogat (const Doboz& d)
{
    unsigned int A = 2*(d.sz*d.m + d.sz*d.h + d.m*d.h);
    unsigned int V = d.sz*d.m*d.h;
    cout << "Doboz felszine: " << A << endl;
    cout << "Doboz terfogata: " << V << endl;
}

void beolvas (Doboz& d);

// ujrafoglal(tomb, N, P);
void ujrafoglal (Doboz*& tomb, int& N, int P)
{
    Doboz* ujtomb = new Doboz [N+P];
    for (int i=0;i<N;i++)
    {
        ujtomb[i] = tomb[i];
    }
    for (int i=N;i<N+P;i++)
    {
        // cin >> ujtomb[i].nev >> ujtomb[i].sz;
        // cin >> ujtomb[i].m >> ujtomb[i].h;
        beolvas(ujtomb[i]);
    }
    delete[] tomb;
    tomb = ujtomb;
    N += P; // N = N + P;
}

// Doboz* ujrafoglal2 (Doboz* t, int N, int P);

void beolvas (Doboz& d)
{
    cin >> d.nev >> d.sz >> d.m >> d.h;
}

// bool l1 = elfer(tomb[0],tomb[1]);
bool elfer (const Doboz& d1, const Doboz& d2)
{
    return d1.sz<=d2.sz && d1.m<=d2.m && d1.h<=d2.h;
}

// bool l2 = elfer(tomb[0],4,5,6);
bool elfer (const Doboz& d, unsigned sz, unsigned m, unsigned h)
{
    Doboz masik;
    masik.sz = sz;
    masik.m = m;
    masik.h = h;
    return elfer(d,masik);
}

// forgat(tomb[0]); // 20x30x40 -> 30x40x20
void forgat (Doboz& d)
{
    unsigned int csere = d.sz;
    d.sz = d.m;
    d.m = d.h;
    d.h = csere;
}

} // namespace doboz

int main()
{
    // int x = 20;
    // cout << x << endl;
    // cout << "Hello World!" << endl;
    using namespace doboz;

    int N; // dobozok szama
    cin >> N;
    Doboz* tomb = new Doboz [N];

    for (int i=0;i<N;i++)
    {
        // // tomb[i] doboz beolvasasa
        // cin >> tomb[i].nev >> tomb[i].sz;
        // cin >> tomb[i].m; // lehetne tovabb lancolni
        // cin >> tomb[i].h;
        beolvas(tomb[i]);
    }

    kiirDobozTomb(tomb, N);

    kiirFelszinTerfogat(tomb[0]);
    kiirFelszinTerfogat(tomb[1]);

    kiirDobozTomb(tomb, N); // ugyanaz az eredmeny

    int P; // plusz dobozok szama;
    cin >> P;
    ujrafoglal(tomb, N, P);

    // tomb = ujrafoglal2(tomb, N, P);

    kiirDobozTomb(tomb, N);

    bool l1 = elfer(tomb[0],tomb[1]);
    if (l1)
        cout << "Igen, tomb[0] elfer a tomb[1]-ben." << endl;
    else
        cout << "Nem, tomb[0] nem fer el a tomb[1]-ben." << endl;

    bool l2 = elfer(tomb[0],4,5,6);
    if (l2)
        cout << "Igen, tomb[0] elfer a tomb[1]-ben." << endl;
    else
        cout << "Nem, tomb[0] nem fer el a tomb[1]-ben." << endl;

    kiirDobozTomb(tomb, N);
    forgat(tomb[0]);
    kiirDobozTomb(tomb, N);

    delete[] tomb;
    return 0;
}
