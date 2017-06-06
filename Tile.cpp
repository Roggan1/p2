/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tile.cpp
 * Author: stud
 * 
 * Created on 7. Mai 2017, 13:42
 */

#include "Tile.h"

Tile::Tile()
{
    
    //m_Type = type;
    m_Char = nullptr;
    
}

Tile::~Tile()
{
   
}

//Tile::Tiletype Tile::getType()
//{
//    return m_Type;
//}

Character* Tile::getChar() 
{
    return m_Char;
}

bool Tile::hasCharacter() 
{ if (m_Char != 0)
    {
        return true;
    }
    return false;
}

void Tile::setCharacter(Character* c)
{
    m_Char = c;
}

void Tile::onLeave(Tile* toTile)
{
   // if(dynamic_cast<Floor*>(toTile))
   // {
        Character* temp = m_Char;
        m_Char = nullptr;
        toTile->onEnter(temp, this);
   // }
   // else 
   // {
   // cout << "Can not enter tile!" << endl;
   // }
}

void Tile::onEnter(Character* c, Tile* fromTile)
{
    m_Char = c;
    
}

bool Tile::isTransparent()
{
    return true;
}
