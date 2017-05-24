/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Active.h
 * Author: stud
 *
 * Created on 21. Mai 2017, 14:18
 */

#ifndef ACTIVE_H
#define ACTIVE_H
#include "Tile.h"
#include "Passive.h"

class Active : public Tile {

public:
    
    bool getUsed();
    void setUsed(bool Used);
 
    void setP_Objekt(Passive* P_Objekt);
    virtual void onEnter(Character* c, Tile* fromTile) override;
    virtual char getSymbol() override;
    
    Active();
    
    virtual ~Active();
protected:

    bool m_Used;
    Passive* m_P_Objekt;
    
};

#endif /* ACTIVE_H */

