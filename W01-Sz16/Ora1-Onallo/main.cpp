#include <iostream>
#include <string>
using namespace std;

struct Targy
{
    string kod;
    unsigned db;
    unsigned* jegyek;
};

int main()
{
    // melyik a jobb?
    // Targy a, b, c;
    Targy t[3]; // inkabb ez
    // Targy* t = new Targy[3];

    for (int i=0;i<3;i++)
    {
        cin >> t[i].kod >> t[i].db;
        t[i].jegyek = new unsigned[t[i].db];
        for (unsigned j=0;j<t[i].db;j++)
            cin >> t[i].jegyek[j];
    }

    for (int i=0;i<3;i++)
    {
        cout << t[i].kod << ":";
        for (unsigned j=0;j<t[i].db;j++)
            cout << " " << t[i].jegyek[j];
        cout << endl;
    }

    for (int i=0;i<3;i++)
        delete[] t[i].jegyek;

    cout << "main() vege!" << endl;
    return 0;
}
