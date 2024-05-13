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
		// const = nem m�dos�t tagv�ltoz�t
		return nev;
	}
	void setal();
};

void Kutya::setal(){
	setal_e=true;
	cout<<nev<<" s�t�l. ";
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
		cout<<nev<<" s�t�ltatja "<<kutya.lekerNev()<<"-t. ";
		kutya.setal();
	}
};

int main(){
	Kutya bloki;
	bloki.beallitNev("Bl�ki");
	bloki.beallitSetal_e(false);
	//bloki.setal_e=false; // private
	Ember rozi;
	rozi.beallitNev("Rozi");
	rozi.setaltat(bloki);
	return 0;
}

// Kimenet: Rozi s�t�ltatja Bl�ki-t.Bl�ki s�t�l.
