/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Wall.cpp
 * Author: stud
 * 
 * Created on 21. Mai 2017, 14:13
 */

#include "Wall.h"

Wall::Wall()
{
}

Wall::~Wall()
{
}

char Wall::getSymbol()
{
    return '#';
}

void Wall::onEnter(Character* c, Tile* fromTile)
{
    m_Char = c;
    onLeave(fromTile);
    cout<<"Can not Enter Tile"<<endl;
}