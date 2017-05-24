/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Character.cpp
 * Author: stud
 * 
 * Created on 9. Mai 2017, 17:21
 */

#include "Character.h"
#include "Controller.h"

Character::Character(char Figur)
{
    m_Figur = Figur;
    m_Controller = nullptr;
}

Character::~Character()
{
}

char Character::getFigur() const
{
    return m_Figur;
}

int Character::move() const
{
    return m_Controller->move();
}

Controller* Character::getController() const {
    return m_Controller;
}

void Character::setController(Controller* Controller) {
    m_Controller = Controller;
}
