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
		// const = nem módosít tagváltozót
		return nev;
	}
	void setal();
};

void Kutya::setal(){
	setal_e=true;
	cout<<nev<<" sétál. "<<endl;
}

class Ember{
private:
	string nev;
	vector<Kutya> kutyak; // tömb típusú kutyákat tároló tároló
public:
	Ember(const string &pnev, const string &kutyaNev, unsigned int kutyaSzam):nev(pnev){
		for(unsigned int i=0;i<kutyaSzam;i++)
			kutyak.push_back(
					Kutya( kutyaNev +string(1, '1'+i) )
			); // elem berakása végére
	}
	void beallitNev(string pnev){
		nev=pnev;
	}
	string lekerNev(){
		return nev;
	}
	void setaltat(){
		for(unsigned int i=0;i<kutyak.size();i++) //.size() elemek száma
		{
			cout<<nev<<" sétáltatja "<<kutyak[i].lekerNev()<<"-t. "; // elem lekérés sorszám szerint
			kutyak[i].setal();
		}
	}
};

int main(){
	Ember rozi("Rozi","Blöki",4);
	rozi.setaltat();
	return 0;
}

// Kimenet: Rozi sétáltatja Blöki-t.Blöki sétál.
