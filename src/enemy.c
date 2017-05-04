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
    int critchance;
    int DSchance;
    float critdamage;
    int block;
    int evade;
    int deflect;
} Enemy;


// Calculates the turn rate of each entity in the fight by taking power and agility.
float enemyTurnRate(int b, int a){
    float tr = 0;
    tr = ((a + b)/2);
    tr = pow(tr, 2);
    tr = tr/(100*b);
    return tr;
}

Enemy* newEnemy(int power, int stamina, int agility){
    Enemy *enemy=(Enemy*)malloc(sizeof(Enemy));
    enemy->power = power;
    enemy->stamina = stamina;
    enemy->agility = agility;
    enemy->hp = stamina * 10;
    enemy->maxhp = stamina * 10;
    enemy->sp = 0;
    enemy->tr = enemyTurnRate(power, agility);;
    enemy->interval = COUNTERMAX / enemyTurnRate(power, agility);
    enemy->counter = 0;
    enemy->critchance = 10;
    enemy->DSchance = 10;
    enemy->critdamage = 1.5;
    enemy->block = 10;
    enemy->evade = 10;
    enemy->deflect = 10;
    return enemy;
}

void enemyRestore(Enemy *enemy){
    enemy->hp = enemy->stamina*10;
    enemy->sp = 0;
    enemy->counter = 0;
}
