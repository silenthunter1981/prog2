#include "character.h"

Character::Character(const string &_type, const string &_charId, const unsigned int _maxHealth):
    type(_type),
    charId(_charId),
    maxHealth(_maxHealth)
{

}

string Character::getCaharId() const
{
    return charId;
}

string Character::getType() const
{
    return type;
}

int Character::getMaxHealth() const
{
    return maxHealth;
}

void Character::setHealth(unsigned int _sHealth)
{

}




