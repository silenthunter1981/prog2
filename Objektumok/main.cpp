#include <iostream>

using namespace std;

class Tomb
{
	unsigned meret;
	int *adatok;
public:
	unsigned meretLeker() const
	{
		return meret;
	}
	Tomb(unsigned _meret)
	{
		this->meret = _meret;
		adatok = new int[meret];
	}
	~Tomb()
	{
		delete [] adatok;
	}
	void ertekBeallit(unsigned index, int ertek)
	{
		if (index < meret)
			adatok[index] = ertek;
	}
	int ertekLeker(unsigned index) const
	{
		if (index < meret)
			return adatok[index];
		else
			return -1000000000;
	}
	Tomb(const Tomb &masik)
	{
		this->meret = masik.meret;
		this->adatok = new int[this->meret];
		for (unsigned i=0; i<this->meret; i++)
			this->adatok[i] = masik.adatok[i];
	}
};

void tombKiir(const Tomb &t)
{
	for (unsigned i=0; i<t.meretLeker(); i++)
	{
		cout << i << ". eleme: " << t.ertekLeker(i) << endl;
	}
}

void rendezveKiir(Tomb t)
{
	for (unsigned i=0; i<t.meretLeker()-1; i++)
	{
		unsigned min_idx = i;
		for (unsigned k=i+1; k<t.meretLeker(); k++)
		{
			if (t.ertekLeker(k) < t.ertekLeker(min_idx))
				min_idx = k;
		}
		if (min_idx != i)
		{
			int csere = t.ertekLeker(i);
			t.ertekBeallit(i, t.ertekLeker(min_idx));
			t.ertekBeallit(min_idx, csere);
		}
	}
	for (unsigned i=0; i<t.meretLeker(); i++)
	{
		cout << i << ". eleme: " << t.ertekLeker(i) << endl;
	}
}

int main()
{
	{
		Tomb t(4), t2(10);
		cout << t.meretLeker() << endl;
		cout << t2.meretLeker() << endl;

		t.ertekBeallit(0,14);
		t.ertekBeallit(1,-32);
		t.ertekBeallit(2,122);
		t.ertekBeallit(3,0);

        //tombKiir(t);
		rendezveKiir(t);
		{
			Tomb t3(t2);
			Tomb t4=t;
		}
	}

	{
		Tomb *dt;
		dt = new Tomb(6);
		cout << dt->meretLeker() << endl;
		delete dt;
	}
	return 0;
}



