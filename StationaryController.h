/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StationaryController.h
 * Author: stud
 *
 * Created on 4. Juni 2017, 16:47
 */

#ifndef STATIONARYCONTROLLER_H
#define STATIONARYCONTROLLER_H
#include "Controller.h"
#include <iostream>

using namespace std;

class StationaryController : public Controller
{
public:
    int move() const override;

    StationaryController(Character* Character);
    
    virtual ~StationaryController();
private:

};

#endif /* STATIONARYCONTROLLER_H */
