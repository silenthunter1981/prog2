#include "soldier.h"
#include <iostream>

Soldier::Soldier(const string& _type,const string &_charId, int _maxHealth, unsigned int _power, unsigned int _armor):
    Character(_type,_charId,_maxHealth),
    power(_power),
    armor(_armor)
{}

unsigned int Soldier::getHealth() const
{

    return health;
}

unsigned int Soldier::getDamage() const
{
    return power;
}

unsigned int Soldier::getHeal() const
{
    return 0;
}

unsigned int Soldier::getAbsorbe() const
{
    return armor;
}

void Soldier::setHealth(unsigned int _sHealth)
{
    health = _sHealth;
}




void Soldier::printC() const
{
    cout << "[HP " << health << "/" << maxHealth << " " << type
         << " " << charId << ", power: " << power << ", armor: " << armor << "]" << endl;
}

