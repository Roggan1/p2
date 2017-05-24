/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConsoleController.h
 * Author: stud
 *
 * Created on 23. Mai 2017, 18:11
 */

#ifndef CONSOLECONTROLLER_H
#define CONSOLECONTROLLER_H
#include "Controller.h"
#include <iostream>

using namespace std;

class ConsoleController : public Controller
{
public:
    int move() const override;
    
    ConsoleController(Character* Character);
    
    virtual ~ConsoleController();
private:

};

#endif /* CONSOLECONTROLLER_H */

