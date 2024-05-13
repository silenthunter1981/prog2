#include <iostream>
using namespace std;

#include "szamok.h"

void kiir (const Tarolo::Szamok& s)
{
    for (int i=0;i<s.darabLeker();i++)
    {
        // if (i>0)
        //     cout << ", ";
        cout << (i ? ", " : "");
        cout << s.ertekLeker(i);
    }
    cout << endl;
}

int main()
{
    // using namespace Tarolo;
    using Tarolo::Szamok;
    Tarolo::Szamok s1(5,9);
    Szamok s2(3,4.9);

    s1.megjelenit();
    s2.megjelenit();

    cout << s1.darabLeker() << endl; // 5

    s2.ertekBeallit(1,1111);
    s2.ertekBeallit(1111,1);

    s2.megjelenit();

    for (int i=-1;i<=3;i++)
        cout << s2.ertekLeker(i) << " ";
    cout << endl;

    kiir(s1);
    kiir(s2);

    cout << "main() vege!" << endl;
    return 0;
}
