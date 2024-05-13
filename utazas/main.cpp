#include <iostream>
#include "utazas.h"
#include "korutazas.h"
using namespace std;


int main() {
    {
        Korutazas k1("Anglia 1", "Nagy Britt utazas", 6, 3);
        Korutazas k2("Parizs 1", "A Notre Dame alatt", 4, 4);
        k1+="London";
        k1+="Windsor";
        k1+="Luton";
        k1+="Bedford";
        k2+="Parizs";
        // k1.kiir(); // Anglia 1, Nagy Britt utazas, 6 nap, London, Windsor, Luton
        // k2.kiir(); // Parizs 1, A Notre Dame alatt, 4 nap, Parizs
    }

    // {
    //     Nyaralas ny1("Adria 1", "Napsutesben", 14, "Adriai");
    //     ny1.setTenger("Foldkozi");
    //     ny1.getTenger(); // Foldkozi
    //     ny1.kiir(); // Adria 1, Napsutesben, 14, Foldkozi
    // }

    // {
    //     ProgramKatalogus pk;
    //     cout << Utazas::dbUtazas; // 0 darab utazas obj. letezik
    //     pk.addUtazas(new Nyaralas("Egei 1", "Orok nyar", 10, "Egei"));
    //     pk.addUtazas(new Korutazas("Oslo 1", "Skandinav csoda", 8, 3));
    //     *((Korutazas*) pk[1]) +="Oslo";
    //     *((Korutazas*) pk[1]) +="Sandvika";
    //     *((Korutazas*) pk[1]) +="Roa";
    //     cout << Utazas::dbUtazas; // 2 darab utazas obj. letezik
    //     pk.addUtazas(new Korutazas("Berlin 1", "Nemet korut", 5, 2));
    //     *((Korutazas*) pk[2]) +="Berlin";
    //     *((Korutazas*) pk[2]) +="Herzberg";
    //     pk.addUtazas(new Korutazas("Roma 1", "Romai vakacio", 3, 1));
    //     *((Korutazas*) pk[3]) +="Roma";
    //     pk.listaz();
    //     cout << Utazas::dbUtazas; // 4 darab utazas obj. letezik
    // }
    // cout << Utazas::dbUtazas; // 0 darab utazas obj. letezik
    return 0;
}


