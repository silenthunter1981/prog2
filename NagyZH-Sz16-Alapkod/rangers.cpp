#include "rangers.h"

Rangers::Rangers(const string& _type,const string &_warId, int _price, int _agility):
    Warriors(_type,_warId,_price),
    agility(_agility)
{

}

void Rangers::printW() const
{
    cout << "[" << type << " " << warId << ", price: " << price  << " agility: " <<
        agility << "]" <<endl;
}
