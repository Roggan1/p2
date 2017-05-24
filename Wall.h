/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Wall.h
 * Author: stud
 *
 * Created on 21. Mai 2017, 14:13
 */

#ifndef WALL_H
#define WALL_H
#include "Tile.h"

class Wall : public Tile {

public:
    void onEnter(Character* c, Tile* fromTile) override;
    
    Wall();
    char getSymbol() override;

    virtual ~Wall();
private:

};

#endif /* WALL_H */

