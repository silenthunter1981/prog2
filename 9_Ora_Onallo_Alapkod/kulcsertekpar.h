#ifndef KULCSERTEKPAR_H
#define KULCSERTEKPAR_H

template <class KulcsTipus, class ErtekTipus>
struct KulcsErtekPar
{
    KulcsTipus kulcs;
    ErtekTipus ertek;

    KulcsErtekPar() {}

    KulcsErtekPar(const KulcsTipus &__kulcs, const ErtekTipus &__ertek):
        kulcs(__kulcs),
        ertek(__ertek)
    {}
};

#endif // KULCSERTEKPAR_H
