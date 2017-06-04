/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Passive.cpp
 * Author: stud
 * 
 * Created on 21. Mai 2017, 14:18
 */

#include "Passive.h"


Passive::Passive()
{
    m_Status = false;
}

Passive::~Passive()
{
}

bool Passive::getStatus()
{
    return m_Status;    
}
char Passive::getSymbol()
{
   return '.';
}

void Passive::setStatus(bool Status)
{
    m_Status = Status;
}



