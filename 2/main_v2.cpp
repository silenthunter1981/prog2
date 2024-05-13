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
public:
	Ember(const string &pnev):nev(pnev){
	}
	void beallitNev(string pnev){
		nev=pnev;
	}
	string lekerNev(){
		return nev;
	}
	void setaltat(Kutya& kutya){
		cout<<nev<<" sétáltatja "<<kutya.lekerNev()<<"-t. ";
		kutya.setal();
	}
};

int main(){
	Kutya bloki("Blöki");
	Ember rozi("Rozi");
	rozi.setaltat(bloki);
	return 0;
}

// Kimenet: Rozi sétáltatja Blöki-t.Blöki sétál.
