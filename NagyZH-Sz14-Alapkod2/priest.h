#ifndef PRIEST_H
#define PRIEST_H

#include "character.h"

class Priest : public Character
{
    unsigned int magic;
public:
    Priest(const string& _type, const string& _charId, const unsigned int _maxHealth, unsigned int _magic);

    unsigned int getHealth()const override;
    unsigned int health = maxHealth;
    unsigned int getDamage()const override;
    unsigned int getHeal() const override;
    unsigned int getAbsorbe() const override;
    void setHealth(unsigned int _sHealth)override;
    void printC()const override;

};

#endif // PRIEST_H
