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

ArmingSword::ArmingSword()
{

}

ArmingSword::~ArmingSword()
{

}

int ArmingSword::modifyStamina(int stamina)
{
 return 0;
}

int ArmingSword::modifyStrength(int strength)
{
return 3;
}

GreatSword::GreatSword()
{

}

GreatSword::~GreatSword()
{

}

int GreatSword::modifyStamina(int stamina)
{
return -1;
}

int GreatSword::modifyStrength(int strength)
{
return 5;
}

Club::Club()
{

}

Club::~Club()
{

}

int Club::modifyStamina(int stamina)
{
return 0;
}

int Club::modifyStrength(int strength)
{
return static_cast<int> (strength / 2);
}

RapierOrDagger::RapierOrDagger()
{

}

RapierOrDagger::~RapierOrDagger()
{

}

int RapierOrDagger::modifyStamina(int stamina)
{
return 1;
}

int RapierOrDagger::modifyStrength(int strength)
{
return 2;
}

Gambeson::Gambeson()
{

}

Gambeson::~Gambeson()
{

}

int Gambeson::modifyStamina(int stamina)
{
return 1;
}

int Gambeson::modifyStrength(int strength)
{
return 0;
}

MailArmour::MailArmour()
{

}

MailArmour::~MailArmour()
{

}

int MailArmour::modifyStamina(int stamina)
{
return 3;
}

int MailArmour::modifyStrength(int strength)
{
return 0;
}

Shield::Shield()
{

}

Shield::~Shield()
{

}

int Shield::modifyStamina(int stamina)
{
return stamina;
}

int Shield::modifyStrength(int strength)
{
return -1;
}

FullPlateArmour::FullPlateArmour()
{

}

FullPlateArmour::~FullPlateArmour()
{

}

int FullPlateArmour::modifyStamina(int stamina)
{
return 6;
}

int FullPlateArmour::modifyStrength(int strength)
{
return -2;
}

    
        
    
        
 
