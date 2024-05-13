#include <iostream>
using namespace std;

#include "tarolo.h"
using EpicToolbox::Tarolo;

int main()
{
    Tarolo t1;
    Tarolo t2(7);

    t1.kiir();
    t2.kiir();

    cout << "main() vege!" << endl;
    return 0;
}
