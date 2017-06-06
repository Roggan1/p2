/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Door.cpp
 * Author: stud
 * 
 * Created on 21. Mai 2017, 14:35
 */

#include "Door.h"

Door::Door()
{
    m_Status=false;
}

Door::~Door()
{
}

char Door::getSymbol()
{
    if (m_Status == true)
    {
        return '/';
    }
    else
    {
        return 'X';
    }
}

void Door::onEnter(Character* Char, Tile* fromTile)
{
    if (m_Status == false)
    {
        cout << "Die Tür ist verschlossen" << endl;
        m_Char = Char;
    onLeave(fromTile);
    }
    else
    {
        m_Char = Char;
    }
}

bool Door::isTransparent()
{
    if(m_Status)
    {
        return true;
    }else{
        return false;
    }
}
