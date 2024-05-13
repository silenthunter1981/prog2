#ifndef TAROLO_H
#define TAROLO_H

class Tarolo
{
    int* tomb;
    int meret;
public:
    Tarolo(); // beolvas
    Tarolo(int meret); // 1, 2, ... meret
    ~Tarolo();

    void kiir () const;
    void hozzaad (int uj_elem);
    double atlag () const;

    int tartomany () const;
    void rendez (bool novekvo);
    void hozzafuz (const Tarolo& masik);
};

#endif // TAROLO_H
