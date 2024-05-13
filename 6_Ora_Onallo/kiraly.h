#ifndef KIRALY_H
#define KIRALY_H

#include "figura.h"

class Kiraly : public Figura
{
public:
    Kiraly(string pozicio);
    bool lephet(string lepes);
};

#endif // KIRALY_H
