/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tile.h
 * Author: stud
 *
 * Created on 7. Mai 2017, 13:42
 */

#ifndef TILE_H
#define TILE_H
#include <iostream>
#include "Character.h"
#include <string>

using namespace std;

class Tile
{
public:
    //enum Tiletype{Floor ,Wall};
    
    //Tiletype getType();
    Character* getChar();
    bool hasCharacter();
    void setCharacter(Character* c);
    virtual void onLeave(Tile* toTile);
    virtual void onEnter(Character* c, Tile* fromTile);
    virtual char getSymbol() = 0;
    
    virtual bool isTransparent();
    Tile(); //(Tiletype type)
    
    virtual ~Tile();
    
protected:

    //Tiletype m_Type;
    Character* m_Char;
    
};

#endif /* TILE_H */