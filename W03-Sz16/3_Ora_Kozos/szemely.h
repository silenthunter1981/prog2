#ifndef SZEMELY_H
#define SZEMELY_H

#include <string>

using namespace std;

class Szemely
{
	string vnev, knev;
protected: // furcsa() miatt
	unsigned int eletkor;
public:
    Szemely(const string &v, const string &k, unsigned int kor);
    string getVezetekNev() const;
	const string &getKeresztNev() const;
	string teljesNev() const;
	unsigned int getEletkor() const;
	void kiir() const;

    // if (sz1.fiatalabb(sz2)) ...
    // fiatalabb-e sz1, mint sz2
    bool fiatalabb (const Szemely& masik) const;
};

#endif // SZEMELY_H
