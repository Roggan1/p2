/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConsoleController.cpp
 * Author: stud
 * 
 * Created on 23. Mai 2017, 18:11
 */

#include "ConsoleController.h"

ConsoleController::ConsoleController(Character* Character) : Controller(Character) {
}

ConsoleController::~ConsoleController()
{
}

int ConsoleController::move() const
{
    char input;
    
    cout << "Enter the direction you want to move! " << endl;
    cin >> input;
    switch (input)
    {
    case '0': return 0;
    
    case '1': return 1;

    case '2': return 2;

    case '3': return 3;

    case '4': return 4;

    case '5': return 5;

    case '6': return 6;

    case '7': return 7;

    case '8': return 8;

    case '9': return 9;


    default: return 5;
    }
}
