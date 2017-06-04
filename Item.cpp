/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Item.cpp
 * Author: stud
 * 
 * Created on 1. Juni 2017, 00:27
 */

#include "Item.h"

Item::Item()
{
}

Item::~Item()
{
    
}

class ArmingSword : public Item {
public:

    ArmingSword() {
    };

    virtual ~ArmingSword() {
    };

    int modifyStamina(int stamina) override {
        return 0;
    };

    int modifyStrength(int strength) override {
        return 3;
    };
};

class GreatSword : public Item {
public:

    GreatSword() {
    };

    virtual ~GreatSword() {
    };

    int modifyStamina(int stamina) override {
        return -1;
    };

    int modifyStrength(int strength) override {
        return 5;
    };
};

class Club : public Item {
public:

    Club() {
    };

    virtual ~Club() {
    };

    int modifyStamina(int stamina) override {
        return 0;
    };

    int modifyStrength(int strength) override {
        return static_cast<int> (strength / 2);
    };
};

class RapierOrDagger : public Item {
public:

    RapierOrDagger() {
    };

    virtual ~RapierOrDagger() {
    };

    int modifyStamina(int stamina) override {
        return 1;
    };

    int modifyStrength(int strength) override {
        return 2;
    };
};

class Gambeson : public Item {
public:

    Gambeson() {
    };

    virtual ~Gambeson() {
    };

    int modifyStamina(int stamina) override {
        return 1;
    };

    int modifyStrength(int strength) override {
        return 0;
    };
};

class MailArmour : public Item {
public:

    MailArmour() {
    };

    virtual ~MailArmour() {
    };

    int modifyStamina(int stamina) override {
        return 3;
    };

    int modifyStrength(int strength) override {
        return 0;
    };
};

class Shield : public Item {
public:

    Shield() {
    };

    virtual ~Shield() {
    };

    int modifyStamina(int stamina) override {
        return stamina;
    };

    int modifyStrength(int strength) override {
        return -1;
    };
};

class FullPlateArmour : public Item {
public:

    FullPlateArmour() {
    };

    virtual ~FullPlateArmour() {
    };

    int modifyStamina(int stamina) override {
        return 6;
    };

    int modifyStrength(int strength) override {
        return -2;
    };
};