/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Active.cpp
 * Author: stud
 * 
 * Created on 21. Mai 2017, 14:18
 */

#include "Active.h"

Active::Active()
{
    m_Used = false;
}

Active::~Active()
{
}

bool Active::getUsed()
{
    return m_Used;
}

char Active::getSymbol()
{
    return '.';
}

void Active::setUsed(bool Used)
{
    m_Used = Used;
}

void Active::setP_Objekt(Passive* P_Objekt)
{
    m_P_Objekt = P_Objekt;
}

void Active::onEnter(Character* c, Tile* fromTile)
{
    
}

