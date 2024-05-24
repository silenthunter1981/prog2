#ifndef SOLDIER_H
#define SOLDIER_H

#include "character.h"

class Soldier : public Character
{
    unsigned int power;
    unsigned int armor;
public:
    Soldier(const string& _type,const string& _charId, int _maxHealth,unsigned int _power, unsigned int _armor);

    unsigned int getHealth()const override;
    unsigned int health = maxHealth;
    unsigned int getDamage()const override;
    unsigned int getHeal()const override;
    unsigned int getAbsorbe() const override;
    void setHealth(unsigned int _sHealth)override;

    void printC()const override;

};

#endif // SOLDIER_H
