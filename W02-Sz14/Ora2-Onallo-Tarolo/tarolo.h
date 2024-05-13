#ifndef TAROLO_H
#define TAROLO_H

namespace EpicToolbox
{

class Tarolo
{
    int* tomb;
    int meret;
public:
    Tarolo();
    Tarolo(int meret);
    ~Tarolo();

    void kiir () const;
    void hozzaad (int uj_elem);
    double atlag () const;
    int tartomany () const;
    void rendez (bool novekvo);
    void hozzafuz (const Tarolo& masik_tarolo);
};

} // namespace EpicToolbox

#endif // TAROLO_H
