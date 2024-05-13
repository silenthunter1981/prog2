#include <iostream>
#include <string>
using namespace std;

namespace doboz
{

struct Doboz
{
    string nev;
    unsigned int x, y, z;
    // x: szelesseg, y: magassag, z: hosszusag
};

// kiirDobozTomb(t, N);
void kiirDobozTomb (Doboz* tomb, int meret)
{
    cout << "Dobozok (" << meret << " db):" << endl;
    for (int i=0;i<meret;i++)
    {
        cout << "  " << tomb[i].nev << ": ";
        cout << tomb[i].x << " x ";
        cout << tomb[i].y << " x ";
        cout << tomb[i].z << endl;
    }
}

// kiirFelszinTerfogat(t[0]);

void kiirFelszinTerfogat (const Doboz& d)
{
    unsigned A = 2*(d.x*d.y + d.y*d.z + d.z*d.x);
    unsigned V = d.x * d.y * d.z;
    cout << "Doboz, A=" << A << ", V=" << V << endl;
}

// ujrafoglal(t, N, P);

void ujrafoglal (Doboz*& tomb, int& meret, int plusz)
{
    Doboz* ujtomb = new Doboz[meret+plusz];
    for (int i=0;i<meret;i++)
        ujtomb[i] = tomb[i];
    // a feladat szovegevel ellentetben
    // itt most beolvassuk az uj dobozokat is azonnal
    for (int i=meret;i<meret+plusz;i++)
    {
        cin >> ujtomb[i].nev;
        cin >> ujtomb[i].x >> ujtomb[i].y >> ujtomb[i].z;
    }
    delete[] tomb;
    tomb = ujtomb;
    meret += plusz;
}

bool elfer (const Doboz& d1,
           unsigned x, unsigned y, unsigned z);

// bool e1 = elfer(t[0], t[1]);
bool elfer (const Doboz& d1, const Doboz& d2)
{
    return elfer(d1, d2.x, d2.y, d2.z);

    return d1.x<=d2.x && d1.y<=d2.y && d1.z<=d2.z;
}

// bool e2 = elfer(t[0], 2, 3, 4);
bool elfer (const Doboz& d1,
           unsigned x, unsigned y, unsigned z)
{
    // Doboz d2;
    // d2.x = x;
    // d2.y = y;
    // d2.z = z;
    // return elfer(d1,d2);

    return d1.x<=x && d1.y<=y && d1.z<=z;
}

// forgat(t[0]); // 20x30x40 -> 30x40x20
void forgat (Doboz& d)
{
    unsigned csere = d.x;
    d.x = d.y;
    d.y = d.z;
    d.z = csere;
}

} // namespace doboz

int main()
{
    using namespace doboz;

    int N; // dobozok szama
    cin >> N;
    Doboz* t = new Doboz[N];

    for (int i=0;i<N;i++)
    {
        cin >> t[i].nev;
        cin >> t[i].x >> t[i].y >> t[i].z;
    }

    kiirDobozTomb(t, N);

    kiirFelszinTerfogat(t[0]);
    kiirFelszinTerfogat(t[1]);

    kiirDobozTomb(t, N);

    int P; // ennyi plusz doboz lesz
    cin >> P;
    ujrafoglal(t, N, P);

    kiirDobozTomb(t, N);
    // hatas: N+P doboz, mind beolvasva

    bool e1 = elfer(t[0], t[1]);
    if (e1)
        cout << "t[0] elfer t[1]-ben" << endl;
    else
        cout << "t[0] nem fer el t[1]-ben" << endl;

    bool e2 = elfer(t[0], 2, 3, 4);
    if (e2)
        cout << "t[0] elfer (2,3,4)-ben" << endl;
    else
        cout << "t[0] nem fer el (2,3,4)-ben" << endl;

    kiirDobozTomb(t, N);
    forgat(t[0]);
    kiirDobozTomb(t, N);

    delete[] t;
    cout << "main() vege!" << endl;
    return 0;
}
