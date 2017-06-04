/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lever.h
 * Author: stud
 *
 * Created on 4. Juni 2017, 15:38
 */

#ifndef LEVER_H
#define LEVER_H
#include "Active.h"
#include <iostream>
using namespace std;

class Lever : public Active
{
public:
    char getSymbol() override;
    void onEnter(Character* Char, Tile* fromTile) override;

protected:

};

#endif /* LEVER_H */

