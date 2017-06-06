/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lever.cpp
 * Author: stud
 * 
 * Created on 4. Juni 2017, 15:38
 */

#include "Lever.h"

Lever::Lever()
{
    m_Used = false;
}

Lever::~Lever()
{
}

char Lever::getSymbol()
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

void Lever::onEnter(Character* Char, Tile* fromTile)
{
    m_Char = Char;
    
    if (m_Used)
    {
        m_Used = false;
        m_P_Objekt->setStatus(false);
    }
    else 
    {
        m_P_Objekt->setStatus(true);
        m_Used = true;
    }
}

