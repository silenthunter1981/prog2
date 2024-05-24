#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Character
{
protected:
    string type;
    string charId;
    unsigned int maxHealth;
public:
    Character(const string& _type, const string& _charId,const unsigned int _maxHealth);
    virtual ~Character()= default;

    string getCaharId()const;
    string getType()const;
    int getMaxHealth()const;
    virtual unsigned int getHealth()const =0;
    virtual unsigned int getDamage()const =0;
    virtual unsigned int getHeal()const =0;
    virtual unsigned int getAbsorbe()const=0;
    virtual void setHealth(unsigned int _sHealth);
    virtual void printC()const =0;

};

#endif // CHARACTER_H
