#include "mage.h"

Mage::Mage(const string &_type, const string &_charId, int _maxHealth, unsigned int _magic):
    Character(_type,_charId,_maxHealth),
    magic(_magic)
{

}

unsigned int Mage::getHealth() const
{
    return health;
}

unsigned int Mage::getDamage() const
{
    return magic;
}

unsigned int Mage::getHeal() const
{
    return 0;
}

unsigned int Mage::getAbsorbe() const
{
    return 0;
}

void Mage::setHealth(unsigned int _sHealth)
{
    health = _sHealth;
}





void Mage::printC() const
{
    cout << "[HP " << health << "/" << maxHealth << " " << type
         << " " << charId << ", magic: " << magic << "]" << endl;
}
