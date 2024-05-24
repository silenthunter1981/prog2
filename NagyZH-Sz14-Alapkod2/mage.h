#ifndef MAGE_H
#define MAGE_H

#include "character.h"

class Mage : public Character
{
    unsigned int magic;
public:
    Mage(const string& _type,const string& _charId,int _maxHealth,unsigned int _magic);




    unsigned int getHealth()const override;
    unsigned int health = maxHealth;

    unsigned int getDamage()const override;
    unsigned int getHeal()const override;
    unsigned int getAbsorbe()const override;
    void setHealth(unsigned int _sHealth)override;
    void printC()const override;



};

#endif // MAGE_H
