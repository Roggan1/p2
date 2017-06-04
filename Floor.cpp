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

