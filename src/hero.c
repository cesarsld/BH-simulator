//
//  BHSimulator.c
//  BH Simulator
//
//  Created by Cesar Salad Jaimes on 20/04/2017.
//  Copyright © 2017 Cesar Salad Jaimes. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#define COUNTERMAX 100
//struct will contain all stats and informations on hero.
//TODO: Will update its content when code gets more complex.
typedef struct {
    int power;
    int stamina;
    int agility;
    int hp;
    int maxhp;
    int sp;
    float tr;
    float interval;
    float counter;
    float critchance;
    float DSchance;
    float critdamage;
    int block;
    float evade;
    float deflect;
    float powerrune;
    float agirune;
    int pet;

} Hero;


// Calculates the turn rate of each entity in the fight by taking power and agility.
float turnRate(int b, int a){
    float tr = 0;
    tr = ((a + b)/2);
    tr = pow(tr, 2);
    tr = tr/(100*b);
    return tr;
}

Hero* newHero(int power, int stamina, int agility, int critchance,
              float critdamage, float DSchance, int block, float evade,
              float deflect, float powerrune, float agirune, int pet){
    Hero *hero=(Hero*)malloc(sizeof(Hero));
    hero->power = power * powerrune;
    hero->stamina = stamina;
    hero->agility = agility * agirune;
    hero->hp = stamina * 10;
    hero->maxhp = stamina*10;
    hero->sp = 0;
    hero->tr = turnRate(power, agility);;
    hero->interval = COUNTERMAX / turnRate(power, agility);
    hero->counter = 0;
    hero->critchance = critchance;
    hero->DSchance = DSchance;
    hero->critdamage = critdamage;
    hero->block = block;
    hero->evade = evade;
    hero->deflect = deflect;
    hero->powerrune = powerrune;
    hero->agirune = agirune;
    hero->pet = pet;
    return hero;
}

void heroRestore(Hero *hero){
    hero->hp = hero->stamina*10;
    hero->sp = 0;
    hero->counter=0;
}
