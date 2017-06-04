/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Trap.cpp
 * Author: stud
 * 
 * Created on 4. Juni 2017, 15:50
 */

#include "Trap.h"

Trap::Trap()
{
    m_Status = false;
}

Trap::~Trap()
{
}

char Trap::getSymbol()
{
    if (m_Status)
    {
        return 'T';
    }
    else
    {
        return '.';
    }
}

void Trap::onEnter(Character* Char, Tile* fromTile)
{
    m_Char = Char;
    //m_P_Objekt->setStatus(true);
    m_Status = true;
    m_Char->loseHP(20);
}
