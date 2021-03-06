/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Floor.cpp
 * Author: stud
 * 
 * Created on 21. Mai 2017, 14:13
 */

#include "Floor.h"

Floor::Floor()
{
    ItemGround = nullptr;
}

Floor::~Floor()
{
}

char Floor::getSymbol()
{

    if (ItemGround)
    {
        return '*';
    }
    else
    {
        return '.';
    }
}

void Floor::onEnter(Character* c, Tile* fromTile) {
    m_Char = c;
    if (ItemGround) {
        m_Char->addItem(ItemGround);
        ItemGround = nullptr;
    }
}

void Floor::placeItem(Item* ItemG)
{
    ItemGround=ItemG;
}
