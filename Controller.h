/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Controller.h
 * Author: stud
 *
 * Created on 23. Mai 2017, 17:37
 */

#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Character.h"

class Controller
{
public:
    Character* getCharacter() const;
    void setCharacter(Character* Character);
    virtual int move() const = 0;
    
    Controller(Character* Character);
    
    virtual ~Controller();
protected:
    
    Character* m_Player;

};

#endif /* CONTROLLER_H */

