#ifndef FIGURA_H
#define FIGURA_H

#include <string>

using namespace std;

class Figura
{
	string pozicio;
public:
	Figura(const string &pos);
	const string &getPozicio() const;
    static bool ervenyes(string pozicio);
    virtual bool lephet(string lepes) =0;
};

#endif // FIGURA_H
