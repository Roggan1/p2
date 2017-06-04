/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Switch.cpp
 * Author: stud
 * 
 * Created on 21. Mai 2017, 14:34
 */

#include "Switch.h"

Switch::Switch()
{
    m_Used = false;
}

Switch::~Switch()
{
}

char Switch::getSymbol()
{
    if(m_Used == false)
    {
       return '?';
    }
    else
    {
       return '!';
    }
}

void Switch::onEnter(Character* Char, Tile* fromTile)
{
    m_Char = Char;
    m_P_Objekt->setStatus(true);
    m_Used = true;
}