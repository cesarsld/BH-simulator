//
//  heroSetup.c
//  BH Simulator
//
//  Created by Cesar Salad Jaimes on 01/06/2017.
//  Copyright © 2017 Cesar Salad Jaimes. All rights reserved.
//

#include "BHSimulator.h"
//#include "heroSetup.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

/*typedef struct {
    int power;
    int stamina;
    int agility;
    int hp;
    int maxhp;
    int sp;
    float hpPerc;
    float tr;
    float interval;
    float counter;
    int critchance;
    int DSchance;
    float critdamage;
    int block;
    int evade;
    int deflect;
    float powerrune;
    float agirune;
    char pet [10];
    bool alive;
    
} Hero;
 
 Hero hero[5];*/

Hero hero[5];

void encon(int i) {
    
    hero[i].power = 477;
    
    hero[i].stamina = 206;
    
    hero[i].agility = 477;
    
    hero[i].sp = 4; // no need to change this variable
    
    hero[i].critchance = 17; // input crit chance
    
    hero[i].critdamage = 1.5; // if you have +50% crit damage, input 1.5
    
    hero[i].DSchance = 1.5; // input Dual strik chance
    
    hero[i].block = 0; // input block chance
    
    hero[i].evade = 2.5; // input evade chance
    
    hero[i].deflect = 0; // input delfect chance
    
    hero[i].powerrune = 1.07; // if you have 5% damage runes, imput 1.05
    
    hero[i].agirune = 1; // if you have 10% speed runes, input 1.1
    
    strcpy (hero[i].pet, "nelson"); //For now I only have gemmi and nelson so put either
    
    hero[i].alive = true; // no need to change this value
    
    
    
}

int test(int a, int b){
    int c;
    c = a + b;
    return c;
}
