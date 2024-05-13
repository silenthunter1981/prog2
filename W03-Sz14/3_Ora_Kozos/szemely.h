#ifndef SZEMELY_H
#define SZEMELY_H

#include <string>

using namespace std;

class Szemely
{
	string vnev, knev;
protected: // a furcsa() fuggveny miatt
	unsigned int eletkor;
public:
    Szemely(const string &v, const string &k, unsigned int kor);
	const string &getVezetekNev() const;
	const string &getKeresztNev() const;
	string teljesNev() const;
	unsigned int getEletkor() const;
	void kiir() const;

    // if (sz1.fiatalabb(sz2))
    bool fiatalabb (const Szemely& masik) const;
};

#endif // SZEMELY_H
