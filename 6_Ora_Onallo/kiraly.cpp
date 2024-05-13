#include "kiraly.h"


Kiraly::Kiraly(string pozicio):
    Figura(pozicio)
{

}

bool Kiraly::lephet(string lepes)
{
    if(lepes[1] - getPozicio()[1]==1 || getPozicio()[1] - lepes[1] ==1 || lepes[0] - getPozicio()[0] == 1 || getPozicio()[0] - lepes[0] ==1 || lepes[1] ){

    }

    else return false;
}
