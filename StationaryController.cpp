/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StationaryController.cpp
 * Author: stud
 * 
 * Created on 4. Juni 2017, 16:47
 */

#include "StationaryController.h"

StationaryController::StationaryController(Character* Character) : Controller(Character) {
}

StationaryController::~StationaryController()
{
}

int StationaryController::move() const
{
    return '5';
}
