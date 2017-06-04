/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Switch.h
 * Author: stud
 *
 * Created on 21. Mai 2017, 14:34
 */

#ifndef SWITCH_H
#define SWITCH_H
#include "Active.h"
#include <iostream>
using namespace std;

class Switch : public Active
{
public:
    char getSymbol() override;
    void onEnter(Character* Char, Tile* fromTile) override;
    
    Switch();
    
    virtual ~Switch();
protected:

};

#endif /* SWITCH_H */

