#include <iostream>
#include <string>
using namespace std;

class Kutya{
private:
	string nev;
	bool setal_e;
public:
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
	Kutya bloki;
	bloki.beallitNev("Blöki");
	bloki.beallitSetal_e(false);
	//bloki.setal_e=false; // private
	Ember rozi;
	rozi.beallitNev("Rozi");
	rozi.setaltat(bloki);
	return 0;
}

// Kimenet: Rozi sétáltatja Blöki-t.Blöki sétál.
