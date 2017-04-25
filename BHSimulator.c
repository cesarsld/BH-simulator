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


                        //struct will contain all stats and informations on hero. Will update its content when code gets more complex.
typedef struct {
    int power;
    int stamina;
    int agility;
    int hp;
    float tr;
    float interval;
    float counter;
} Hero;
Hero hero[5];           // size of array indicated max amount of heroes in team.

//int a,b;
int dummypower = 1600, dummystamina = 2880, dummyagility = 640, hpdummy, dummytr, dummyinterval;
//int critChance, critDamage, block, evade, deflect, DS, runePower, runeAgi;
int counter;
int countermax = 100;
float tr = 2, interval, dummycounter=0;
int cycle, attacktimer, j=0, attacksdone=0;
int playerNo;
int i;
bool teamalive = true;





float turnRate(int b, int a){
    tr = ((a + b)/2);
    tr = pow(tr, 2);
    tr = tr/(100*b);
    return tr;
}

void updateTimer(){
    attacktimer = interval * (1+ j);
}

//void perfom_turn(){
    
//}

int main() {
   // printf("How many heroes will you use?\n");
   // scanf("%d", &playerNo);
    playerNo = 5;
    hero[0].power = 500;
    hero[1].power = 500;
    hero[2].power = 500;
    hero[3].power = 500;
    hero[4].power = 500;
    hero[0].stamina = 200;
    hero[1].stamina = 200;
    hero[2].stamina = 200;
    hero[3].stamina = 200;
    hero[4].stamina = 200;
    hero[0].agility = 500;
    hero[1].agility = 500;
    hero[2].agility = 500;
    hero[3].agility = 500;
    hero[4].agility = 500;
    hpdummy = dummystamina * 10;
    dummytr = turnRate(dummypower, dummyagility);
    dummyinterval = countermax / dummytr;
    

    for(i=0 ; i<playerNo ; i++){
        /*printf("How much power on hero %d ?\n", i+1);
        scanf("%d", &hero[i].power);
        printf("How much stamina on hero %d ?\n", i+1);
        scanf("%d", &hero[i].stamina);
        printf("How much agility on hero %d ?\n", i+1);
        scanf("%d", &hero[i].agility);*/
        
        hero[i].hp = hero[i].stamina * 10;
        hero[i].tr = turnRate(hero[i].power, hero[i].agility);
        hero[i].interval = countermax / hero[i].tr;
        hero[i].counter=0;
    }
    
    
    while (hpdummy>0 && teamalive==true){
        for(cycle=1 ; cycle<=countermax ; cycle++){
            dummycounter++;
            for(i=0 ; i<playerNo ; i++){
                hero[i].counter++;
                if(hero[i].counter >= hero[i].interval && hero[i].hp > 0){
                    hpdummy -= hero[i].power;
                    hero[i].counter -= hero[i].interval;
                    attacksdone++;
                    if (hpdummy<=0){
                        printf("You killed the dummy!\n");
                        i = playerNo;
                        cycle = countermax;
                    }
                }
            }
            if (hpdummy > 0 && dummycounter >= dummyinterval){
                if (hero[0].hp > 0){
                    hero[0].hp -= dummypower;
                } else if (hero[1].hp > 0){
                    hero[1].hp -= dummypower;
                } else if (hero[2].hp > 0){
                    hero[2].hp -= dummypower;
                } else if (hero[3].hp > 0){
                    hero[3].hp -= dummypower;
                } else if (hero[4].hp > 0){
                    hero[4].hp -= dummypower;
                } else {
                    teamalive = false;
                    cycle = countermax;
                }
            }
            
        }
    }
    printf("hits done: %d\n", attacksdone);
    printf("hP: %d\n", hpdummy);
    


}
