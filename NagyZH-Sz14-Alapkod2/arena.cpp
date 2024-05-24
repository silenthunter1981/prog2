#include "arena.h"
#include "json.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace nlohmann;


#include "mage.h"
#include "soldier.h"
#include "priest.h"






Arena::~Arena()
{
    for (unsigned i = 0; i < allCharacters.size(); i++) {
        if (allCharacters[i]) {
            delete allCharacters[i];
        }
    }
}

void Arena::load(const string& _jsonFile)
{
    ifstream input(_jsonFile);
    if (!input.is_open())
    {
        cout << "Cannot open input karakterek.json" << endl;
        return ;
    }

    json jDatas = json::parse(input);

    for (unsigned i=0; i<jDatas.size(); i++)
    {
        const json &data = jDatas[i];
        if (data["CharacterClass"]=="Soldier")
            allCharacters.push_back(new Soldier(data["CharacterClass"], data["Id"], data["MaxHP"], data["Power"], data["Armor"]));
        else if (data["CharacterClass"]=="Mage")
            allCharacters.push_back(new Mage(data["CharacterClass"], data["Id"], data["MaxHP"], data["Magic"]));
        else if (data["CharacterClass"]=="Priest")
            allCharacters.push_back(new Priest(data["CharacterClass"], data["Id"], data["MaxHP"], data["Magic"]));

    }
}




void Arena::printAll()
{
    for(unsigned int i=0;i<allCharacters.size();i++){
        allCharacters[i]->printC();
    }
}

void Arena::performAction(const string &characterI, const string &characterII)
{
    Character *warriorI=nullptr, *warriorII=nullptr;
    for(unsigned int i=0;i<allCharacters.size();i++){
        if(allCharacters[i]->getCaharId() == characterI){
            warriorI=allCharacters[i];
        }else if(allCharacters[i]->getCaharId()== characterII){
            warriorII=allCharacters[i];
        }
    }

    int dmg1 = warriorI->getDamage();
    int heal1 = warriorI->getHeal();
    int health2 = warriorII->getHealth();
    int absorb2 = warriorII->getAbsorbe();
    //cout << (dmg1-absorb2) << endl;
    if (warriorI->getHealth()==0 || warriorII->getHealth()==0){
       }
    else if(warriorI->getType()=="Soldier"){
        if((dmg1-absorb2) <= 0){
            health2 = health2-1;
        }
        else if (health2-(dmg1-absorb2)<= 0){
            health2=0;
        }
        else {health2=health2-(dmg1-absorb2);}
        //cout<< health2<<endl;
    }else if (warriorI->getType()=="Mage"){
        if((health2-dmg1) <= 0){
            health2=0;
        }
        else {health2=health2-dmg1;}
        //cout<< health2<<endl;
    }else if (warriorI->getType()=="Priest"){
        if((health2+heal1) >= warriorII->getMaxHealth()){
            health2=warriorII->getMaxHealth();
        }
        else {health2=health2+heal1;}
        //cout<< health2<<endl;
    }

        warriorII->setHealth(health2);
}

void Arena::print(const string &charId)
{
    for(unsigned int i=0;i<allCharacters.size();i++){
        if(allCharacters[i]->getCaharId()== charId){
            allCharacters[i]->printC();
        }
    }
}
