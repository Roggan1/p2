/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Character.h
 * Author: stud
 *
 * Created on 9. Mai 2017, 17:21
 */

#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>

using namespace std;

class Controller;

class Character
{
public:
    void setController(Controller* Controller);
    Controller* getController() const;
    char getFigur() const;
    int move() const;
    
    Character(char Figur);
    virtual ~Character();
private:

    char m_Figur;
    Controller* m_Controller;
};

#endif /* CHARACTER_H */

