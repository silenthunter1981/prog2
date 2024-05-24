#include "mage.h"

Mage::Mage(const string& _type,const string &_warId, int _price, double _magic):
    Warriors(_type,_warId,_price),
    magic(_magic)
{

}
void Mage::printW() const
{
    cout << "[" << type << " " << warId << ", price: " << price  << " magic: " <<
        magic << "]" <<endl;
}
