#ifndef SZAMOK_H
#define SZAMOK_H

namespace Tarolo
{

class Szamok
{
// private:
    double* tomb;
    int meret;
public:
    Szamok(int meret, double kezdo=0);
    ~Szamok();

    void megjelenit () const;

    int darabLeker () const;

    void ertekBeallit (int index,
                      double uj_ertek);

    double ertekLeker (int index) const;
};

} // namespace Tarolo

#endif // SZAMOK_H
