#include "priest.h"

Priest::Priest(const string &_type, const string &_charId, const unsigned int _maxHealth, unsigned int _magic):
    Character(_type,_charId,_maxHealth),
    magic(_magic)
{

}

unsigned int Priest::getHealth() const
{
    return health;
}

unsigned int Priest::getDamage() const
{
    return 0;
}

unsigned int Priest::getHeal() const
{
    return magic;
}

unsigned int Priest::getAbsorbe() const
{
    return 0;
}

void Priest::setHealth(unsigned int _sHealth)
{
    health = _sHealth;
}



void Priest::printC() const
{
    cout << "[HP " << health << "/" << maxHealth << " " << type
         << " " << charId << ", magic: " << magic << "]" << endl;
}
