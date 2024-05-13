#include <iostream>
using namespace std;

#include "szamok.h"

int main()
{
    // using namespace Tarolo;
    using Tarolo::Szamok;
    Tarolo::Szamok s1(5,9);
    Szamok s2(3,7.2);

    s1.megjelenit(); // 9 9 9 9 9
    s2.megjelenit(); // 7.2 7.2 7.2

    cout << s1.darabLeker() << endl; // 5

    s2.ertekBeallit(1,99.9);
    s2.ertekBeallit(99,111111);

    s2.megjelenit(); // 7.2 99.9 7.2

    for (int i=-1;i<=3;i++)
        cout << s2.ertekLeker(i) << " ";
    cout << endl;
    // -1e+08 7.2 99.9 7.2 -1e+08

    cout << "main() vege!" << endl;
    return 0;
}
