/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Trap.h
 * Author: stud
 *
 * Created on 4. Juni 2017, 15:50
 */

#ifndef TRAP_H
#define TRAP_H
#include "Active.h"

class Trap : public Passive
{
public:
    char getSymbol() override;
    void onEnter(Character* c, Tile* fromTile) override;



    Trap();

    virtual ~Trap();
private:

};

#endif /* TRAP_H */

