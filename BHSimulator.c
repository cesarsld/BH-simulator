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

int a,b;
int power, stamina, agility, hp;
int critChance, critDamage, block, evade, deflect, DS, runePower, runeAgi;
int counter;
int hpdummy=100000;
int countermax=100;
float tr=2, interval, privatecounter=0;
int cycle, attacktimer, j=0, attacksdone=0;




void turnRate(int a, int b){
    tr = ((a + b)/2);
    tr= pow(tr, 2);
    tr=tr/(100*b);
    
}

void updateTimer(){
    attacktimer = interval * (1+ j);
}

void perfom_turn(){
    
}

int main() {
    scanf("%d", &power);
    scanf("%d", &stamina);
    scanf("%d", &agility);
    hp = stamina * 10;
    turnRate(power, agility);
    interval = countermax / tr;
    //updateTimer();
    //printf("attacktimer: %d\n", attacktimer);
    //printf("%f", tr);
    while (hp>0 && hpdummy>0){
        for(cycle=1 ; cycle<=countermax ; cycle++){
            privatecounter++;
            if(privatecounter >= interval){
                hpdummy -= power;
                privatecounter -= interval;
                attacksdone++;
                
            }
        }
        
        
    }
    printf("hits done: %d\n", attacksdone);
    printf("hP: %d\n", hpdummy);
    
    
}



