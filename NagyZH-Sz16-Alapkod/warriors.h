#ifndef WARRIORS_H
#define WARRIORS_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Warriors
{
protected:
    string type;
    string warId;
    int price;
public:
    Warriors(const string& _type,const string& _warId,int _price);

    string getWarId()const;
    int getPrice()const;
    virtual void printW()const =0;
    virtual ~Warriors()=default;
};

#endif // WARRIORS_H
