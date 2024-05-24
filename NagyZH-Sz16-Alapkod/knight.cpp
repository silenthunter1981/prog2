#include "knight.h"

Knight::Knight(const string& _type, const string &_warId, int _price, int _strength):
    Warriors(_type,_warId,_price),
    strength(_strength)
{

}
void Knight::printW() const
{
    cout << "[" << type << " " << warId << ", price: " << price  << " strange: " <<
        strength << "]" <<endl;
}
