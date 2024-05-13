#include <iostream>
#include <string>
using namespace std;

class Kutya{
private:
	string nev;
	bool setal_e;
public:
	Kutya(const string &pnev):nev(pnev),setal_e(false){
	}
	void beallitNev(string pnev){
		nev=pnev;
	}
	void beallitSetal_e(bool psetel_e){
		setal_e=psetel_e;
	}
	string lekerNev() const {
		// const = nem módosít tagváltozót
		return nev;
	}
	void setal();
};

void Kutya::setal(){
	setal_e=true;
	cout<<nev<<" sétál. ";
}

class Ember{
private:
	string nev;
	Kutya kutyaja;
public:
	Ember(const string &pnev, const string &kutyaNev):nev(pnev),kutyaja(kutyaNev){
	}
	void beallitNev(string pnev){
		nev=pnev;
	}
	string lekerNev(){
		return nev;
	}
	void setaltat(){
		cout<<nev<<" sétáltatja "<<kutyaja.lekerNev()<<"-t. ";
		kutyaja.setal();
	}
};

int main(){
	Ember rozi("Rozi","Blöki");
	rozi.setaltat();
	return 0;
}

// Kimenet: Rozi sétáltatja Blöki-t.Blöki sétál.
