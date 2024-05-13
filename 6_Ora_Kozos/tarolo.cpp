#include "tarolo.h"

#include <iostream>
#include "hajo.h"
#include "repulo.h"

using namespace std;

Tarolo::Tarolo()
{
	for (unsigned int i=0; i<TAROLO_KAPACITAS; i++)
		tomb[i]=0;
}

Tarolo::~Tarolo()
{
	for (unsigned int i=0; i<TAROLO_KAPACITAS; i++)
		if (tomb[i]) delete tomb[i];
}

void Tarolo::beallit(unsigned int index, Jarmu *j)
{
	if (index<TAROLO_KAPACITAS)
	{
		if (tomb[index]) delete tomb[index];
		tomb[index]=j;
	}
}

void Tarolo::megjelenit() const
{
	cout << "tartalom:" << endl;
	for (unsigned int i=0; i<TAROLO_KAPACITAS; i++)
	{
		cout << i << ".: ";
		if (tomb[i]) tomb[i]->kiir();
		else cout << "ures" << endl;
    }
}

Tarolo::Tarolo(const Tarolo &masik)
{
    for(unsigned int i=0;i<TAROLO_KAPACITAS;i++)
        if (masik.tomb[i] != nullptr)
        {
          //this-> tomb[i] = masik.tomb[i]; //NEM JÓ!
          //this-> tomb[i] = new Jarmu(*masik.tomb[i]); //NEM JÓ!
           /* Hajo *h = dynamic_cast<Hajo*>(masik.tomb[i]);
            Repulo *r = dynamic_cast<Repulo*>(masik.tomb[i]);
            if (h) this ->tomb[i]= new Hajo(*h);
            else if (r) this ->tomb[i] = new Repulo (*r);
            else this->tomb[i]= nullptr;*/
          this->tomb[i]=masik.tomb[i]->clone();//clone metodus hívása
        }
        else this->tomb[i] = nullptr;
}
