#include <iostream>
using namespace std;

#include "building.h"
#include "landoffice.h"

#define PART1  // Epulet adatszerkezet
#define PART2  // LandOffice, betoltes
#define PART4  // print()
#define PART5  // listAll()
#define PART6  // Teljes terulet
#define PART7  // listAreas()
//#define PART8  // exportAreas()
//#define PART9 // Felujitasok
//#define PART10 // loadRenovations()
//#define PART11 // print() modositas

int main()
{
    cout << "main() eleje!" << endl << endl;

#if defined(PART1) && defined(PART2)
	cout << endl << "LandOffice loading" << endl;
	LandOffice office("simplebuildings.json", "multilevelbuildings.json", "buildingswithland.json");
#endif

#if defined(PART4) && defined(PART5)
	cout << endl << "Print all buildings:" << endl;
	office.listAll();
#endif

#if defined(PART6) && defined(PART7)
	cout << endl << "Total areas of buildings:" << endl;
	office.listAreas();
#endif

#if defined(PART6) && defined(PART8)
	cout << endl << "Exporting total areas" << endl;
	office.exportAreas("area_export.json");
#endif

#if defined(PART9) && defined(PART10) && defined(PART11)
	cout << endl << "Loading renovations ..." << endl;
	cout << "Printing data again" << endl;
	office.loadRenovations("renovations.json");
	office.listAll();
#endif

	cout << endl << "main() vege!" << endl;
    return 0;
}
