//  BH Simulator
//
//  Created by Shadown88 on 20/04/2017.
//  Copyright © 2017 Shadown88. All rights reserved.
//

#ifndef BHSimulator_h
#define BHSimulator_h

#include <stdbool.h>
#pragma once
struct HeroStruct;

//struct will contain all stats and informations on hero. Will update its content when code gets more complex.

typedef struct HeroStruct {
    int power;
    int stamina;
    int agility;
    int hp;
    int maxHP;
    int sp;
    float hpPerc;
    float tr;
    float interval;
    float counter;
	float critChance;
	float DSchance;
    float critDamage;
	float block;
	float evade;
	float deflect;
    float powerRune;
    float agiRune;
    char pet [10];
    bool alive;
    char name [20];
    
} Hero;

bool RNGroll(float a);


#endif /* BHSimulator_h */



