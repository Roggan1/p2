/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AttackController.h
 * Author: stud
 *
 * Created on 19. Juni 2017, 19:42
 */

#ifndef ATTACKCONTROLLER_H
#define ATTACKCONTROLLER_H
#include "Controller.h"
#include "DungeonMap.h"

class AttackController : public Controller
{
public:
 
    AttackController(Character* newCharacter, Character* newEnemy, DungeonMap* newMap);    
    
    virtual ~AttackController();
    int move() const override;
    
private:

     DungeonMap* map;
    Character* target;
    
};

#endif /* ATTACKCONTROLLER_H */

