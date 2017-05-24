/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Controller.cpp
 * Author: stud
 * 
 * Created on 23. Mai 2017, 17:37
 */

#include "Controller.h"

Controller::Controller(Character* Character) : m_Player(Character) {
    m_Player->setController(this);
}

Controller::~Controller()
{
}

Character* Controller::getCharacter() const {
    return m_Player;
}

void Controller::setCharacter(Character* Character) {
    m_Player = Character;
}


