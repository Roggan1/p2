/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Character.cpp
 * Author: stud
 * 
 * Created on 9. Mai 2017, 17:21
 */

#include <vector>

#include "Character.h"
#include "Controller.h"


Character::Character(char Figur,int Str, int Sta)
{
    m_Figur = Figur;
    m_Controller = nullptr;
    
    strength=Str;
    stamina=Sta;
    hitpoints=getMaxHP();
}

Character::~Character()
{
    for(int i=0; i<Items.size();i++)
    {
        delete Items[i];
    }
}

char Character::getFigur() const
{
    return m_Figur;
}

int Character::move() const
{
    return m_Controller->move();
}

Controller* Character::getController() const {
    return m_Controller;
}

void Character::setController(Controller* Controller) {
    m_Controller = Controller;
}

int Character::getMaxHP()
{
    return getStamina() * 5 + 20;
}

void Character::showInfo()
{
    cout<<"Stamina: "<<stamina<<endl;
    cout<<"Strength: "<<strength<<endl;
    cout<<"Hitpoints: "<<hitpoints<<"/"<<getMaxHP()<<endl;
    
}

void Character::addItem(Item* Item)
{
    Items.push_back(Item);
}

int Character::getStamina()
{
    int StamGes=0;
    for(int i=0; i<Items.size();i++)
    {
        StamGes=StamGes+Items[i]->modifyStamina(stamina);
    }
    return stamina+StamGes;
}

int Character::getStrength()
{
    int StreGes=0;
    for(int i=0; i<Items.size();i++)
    {
        StreGes=StreGes+Items[i]->modifyStrength(strength);
    }
    return strength+StreGes;
}
