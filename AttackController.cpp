/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AttackController.cpp
 * Author: stud
 * 
 * Created on 19. Juni 2017, 19:42
 */

#include "AttackController.h"

AttackController::AttackController(Character* Char, Character* player, DungeonMap* newMap)  : Controller(Char), target(player), map(newMap)
{

}

AttackController::~AttackController()
{
}

int AttackController::move() const {
    Position from = map->findCharacter(this->getCharacter());
    Position to = map->findCharacter(target);
    int toMove = map->getPathTo(from, to);
    
    return toMove;
}