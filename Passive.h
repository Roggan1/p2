/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Passive.h
 * Author: stud
 *
 * Created on 21. Mai 2017, 14:18
 */

#ifndef PASSIVE_H
#define PASSIVE_H
#include "Tile.h"

class Passive : public Tile {
    
public:
    
    bool getStatus();
    void setStatus(bool Status);
    
    virtual char getSymbol() override;

    virtual void onEnter(Character* c, Tile* fromTile) override;



    Passive();

    virtual ~Passive();
protected:

    bool m_Status;
    
};

#endif /* PASSIVE_H */

