#include "warriors.h"

Warriors::Warriors(const string& _type,const string &_warId, int _price):
    type(_type),
    warId(_warId),
    price(_price)
{

}

string Warriors::getWarId() const
{
    return warId;
}

int Warriors::getPrice() const
{
    return price;
}
