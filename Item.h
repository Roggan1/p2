/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Item.h
 * Author: stud
 *
 * Created on 1. Juni 2017, 00:27
 */

#ifndef ITEM_H
#define ITEM_H

class Item
{
public:
    Item();
    virtual ~Item();
    
    virtual int modifyStrength(int strength)=0;
    virtual int modifyStamina(int stamina)=0;
private:

};

class GreatSword : public Item {
public:

    GreatSword(); 
    virtual ~GreatSword() ;

    int modifyStamina(int stamina) override ;
    int modifyStrength(int strength) override ;
private:  
};
#endif /* ITEM_H */

class ArmingSword : public Item {
public:

    ArmingSword();
    virtual ~ArmingSword(); 

    int modifyStamina(int stamina) override;
    int modifyStrength(int strength) override;
};

class Club : public Item {
public:

    Club();
    virtual ~Club();

    int modifyStamina(int stamina) override;
    int modifyStrength(int strength) override;
};

class RapierOrDagger : public Item {
public:

    RapierOrDagger();
    virtual ~RapierOrDagger();

    int modifyStamina(int stamina) override;
    int modifyStrength(int strength) override;
};

class Gambeson : public Item {
public:

    Gambeson();
    virtual ~Gambeson();

    int modifyStamina(int stamina) override;
    int modifyStrength(int strength) override;
};

class MailArmour : public Item {
public:

    MailArmour();
    virtual ~MailArmour();

    int modifyStamina(int stamina) override;
    int modifyStrength(int strength) override;
};

class Shield : public Item {
public:

    Shield();
    virtual ~Shield();

    int modifyStamina(int stamina) override;
    int modifyStrength(int strength) override;
};

class FullPlateArmour : public Item {
public:

    FullPlateArmour();
    virtual ~FullPlateArmour();
    
    int modifyStamina(int stamina) override;
    int modifyStrength(int strength) override;
};