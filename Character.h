/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Character.h
 * Author: stud
 *
 * Created on 9. Mai 2017, 17:21
 */

#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <vector>
#include "Item.h"

using namespace std;

class Controller;

class Character
{
public:
    void setController(Controller* Controller);
    Controller* getController() const;
    char getFigur() const;
    int move() const;
    
    int getMaxHP();
    int getStrength();
    int getStamina();
    
    void addItem(Item*);
    
    void showInfo();
    
    Character(char Figur,int Str, int Sta);
    virtual ~Character();
private:
    int strength;
    int stamina;
    int hitpoints;
    
    char m_Figur;
    Controller* m_Controller;
    vector<Item*> Items;
};

#endif /* CHARACTER_H */

