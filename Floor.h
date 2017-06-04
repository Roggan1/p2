/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Floor.h
 * Author: stud
 *
 * Created on 21. Mai 2017, 14:13
 */

#ifndef FLOOR_H
#define FLOOR_H
#include "Tile.h"

class Floor : public Tile
{
public:
    Floor();
    char getSymbol() override;

    virtual ~Floor();
private:

    Item* Item;
    
};

#endif /* FLOOR_H */

