#ifndef JARMU_H
#define JARMU_H

class Jarmu
{
protected:
	unsigned int tomeg, sebesseg;
public:
	Jarmu(unsigned int t, unsigned int s);
    virtual void kiir() const =0; // Tisztán virtuálissá teszi,a "jármű" osztály absztrakt lesz.
    virtual ~Jarmu() = default;
    virtual Jarmu *clone() const =0; // Tisztán virtuális.
};
/*
void kiir() cost; ------> 0xfe3456 memória cím
destruktor is bekerül a virtuális táblába




*/


#endif // JARMU_H
