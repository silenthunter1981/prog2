#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Kutya{
private:
	string nev;
	bool setal_e;
public:
	Kutya(const string &pnev="kutya"):nev(pnev),setal_e(false){
	}
	void beallitNev(string pnev){
		nev=pnev;
	}
	void beallitSetal_e(bool psetel_e){
		setal_e=psetel_e;
	}
	string lekerNev() const {
		// const = nem m�dos�t tagv�ltoz�t
		return nev;
	}
	void setal();
};

void Kutya::setal(){
	setal_e=true;
	cout<<nev<<" s�t�l. "<<endl;
}

class Ember{
private:
	string nev;
	vector<Kutya> kutyak; // t�mb t�pus� kuty�kat t�rol� t�rol�
public:
	Ember(const string &pnev, const string &kutyaNev, unsigned int kutyaSzam):nev(pnev){
		for(unsigned int i=0;i<kutyaSzam;i++)
			kutyak.push_back(
					Kutya( kutyaNev +string(1, '1'+i) )
			); // elem berak�sa v�g�re
	}
	void beallitNev(string pnev){
		nev=pnev;
	}
	string lekerNev(){
		return nev;
	}
	void setaltat(){
		for(unsigned int i=0;i<kutyak.size();i++) //.size() elemek sz�ma
		{
			cout<<nev<<" s�t�ltatja "<<kutyak[i].lekerNev()<<"-t. "; // elem lek�r�s sorsz�m szerint
			kutyak[i].setal();
		}
	}
};

int main(){
	Ember rozi("Rozi","Bl�ki",4);
	rozi.setaltat();
	return 0;
}

// Kimenet: Rozi s�t�ltatja Bl�ki-t.Bl�ki s�t�l.
