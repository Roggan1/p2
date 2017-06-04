/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Door.h
 * Author: stud
 *
 * Created on 21. Mai 2017, 14:35
 */

#ifndef DOOR_H
#define DOOR_H
#include "Passive.h"

class Door : public Passive
{
public:
    void onEnter(Character* Char,Tile* fromTile) override;
    char getSymbol() override;
    
    Door();
    
    virtual ~Door();
protected:

};

#endif /* DOOR_H */

