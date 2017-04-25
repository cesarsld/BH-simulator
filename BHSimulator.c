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
int dummypower, dummystamina, dummyagility, hpdummy=100000;
int critChance, critDamage, block, evade, deflect, DS, runePower, runeAgi;
int counter;
int countermax = 100;
float tr = 2, interval, dummycounter=0;
int cycle, attacktimer, j=0, attacksdone=0;
int playerNo;
int i;




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
    

    for(i=0 ; i<playerNo ; i++){
        /*printf("How much power on hero %d ?\n", i+1);
        scanf("%d", &hero[i].power);
        printf("How much stamina on hero %d ?\n", i+1);
        scanf("%d", &hero[i].stamina);
        printf("How much agility on hero %d ?\n", i+1);
        scanf("%d", &hero[i].agility);*/
        
        hero[i].hp = hero[i].stamina * 101;
        hero[i].tr = turnRate(hero[i].power, hero[i].agility);
        hero[i].interval = countermax / hero[i].tr;
        hero[i].counter=0;
    }
    
    
    while (hpdummy>0){
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
            if (hpdummy > 0  ){}
        }
    }
    printf("hits done: %d\n", attacksdone);
    printf("hP: %d\n", hpdummy);
    


}
