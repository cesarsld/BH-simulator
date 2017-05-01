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
    int maxhp;
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
    
} Hero;
Hero hero[5];           // size of array indicated max amount of heroes in team.

int dummypower = 1700, dummystamina = 3060, dummyagility = 680, hpdummy;

// RNGroll serves as flag to say if roll is succesful (returns true) or not (returns false). Rolls on 1000 so that decimal aren't lost.
bool RNGroll(float a){
    bool outcome;
    float chance = a * 10;
    int roll = rand()% 1000 +1;
    if (roll <= chance){
        outcome = true;
    } else {
        outcome = false;
    }
    return outcome;
}


void petproc(int l){
    int i;
    int healmodifier = hero[l].power * 0.072;
    int healvalue = rand()% healmodifier + 0.324 * hero[l].power;
    bool critroll = RNGroll(hero[l].critchance);
    bool petroll = RNGroll(20);
    if (critroll){
        healvalue *= hero[l].critdamage;
    }
    if (petroll){
        for (i=0 ; i<5 ; i++){
            if (hero[i].hp >0){
                hero[i].hp += healvalue;
                if (hero[i].hp >= hero[i].maxhp){
                    hero[i].hp = hero[i].maxhp;
                }
            }
        }
    }
}

// Calculates the turn rate of each entity in the fight by taking power and agility.
float turnRate(int b, int a){
    float tr = 0;
    tr = ((a + b)/2);
    tr = pow(tr, 2);
    tr = tr/(100*b);
    return tr;
}

void heroattack(int k){
    float attackvalue = 0;
    int attackmodifier = 0.2 * hero[k].power;
    attackvalue = rand()% attackmodifier + 0.9 * hero[k].power;
    bool critroll = RNGroll(hero[k].critchance);
    if (critroll){
        attackvalue *= hero[k].critdamage;
    }
    bool evaderoll = RNGroll(2.5);
    if (!evaderoll){
        hpdummy -= attackvalue;
        petproc(k);
    }
}

void bossattack(int k){
    bool blockroll, evaderoll, deflectroll;
    float attackvalue= 0 ;
    int attackmodifier = 0.2 * dummypower;
    attackvalue = rand()% attackmodifier + 0.9 * dummypower;
    bool critroll = RNGroll(10);
    if (critroll){
        attackvalue *= 1.5;
    }
    deflectroll = RNGroll(hero[k].deflect);
    if (!deflectroll){
        evaderoll = RNGroll(hero[k].evade);
        if (!evaderoll){
            blockroll = RNGroll(hero[k].block);
            if (blockroll){
                hero[k].hp -= 0.5 * attackvalue;
                petproc(k);
            } else {hero[k].hp -= attackvalue;
                    petproc(k);
            }
        }
    } else {hpdummy -= attackvalue;}
}

int main() {
    int p;
    float win=0;
    float lose=0;
    float winrate;
    
    srand((unsigned int)time(NULL));
    
    for (p=0 ; p < 1000 ; p++){
    dummypower = 1700;
    dummystamina = 3060;
    dummyagility = 680;
    int countermax = 100;
    int playerNo;
    int i;
    int cycle;
    
    float dummytr;
    float dummycounter=0;
    float dummyinterval;
    
    bool DS;
    bool teamalive = true;
    
   // printf("How many heroes will you use?\n");
   // scanf("%d", &playerNo);
    playerNo = 5;
    hero[0].power = 100;
    hero[1].power = 761;
    hero[2].power = 762;
    hero[3].power = 761;
    hero[4].power = 100;
    hero[0].stamina = 1300;
    hero[1].stamina = 77;
    hero[2].stamina = 77;
    hero[3].stamina = 77;
    hero[4].stamina = 1300;
    hero[0].agility = 100;
    hero[1].agility = 662;
    hero[2].agility = 661;
    hero[3].agility = 662;
    hero[4].agility = 100;
    hero[0].critchance = 10;
    hero[1].critchance = 25;
    hero[2].critchance = 25;
    hero[3].critchance = 25;
    hero[4].critchance = 10;
    hero[0].critdamage = 1.5;
    hero[1].critdamage = 1.5;
    hero[2].critdamage = 1.5;
    hero[3].critdamage = 1.5;
    hero[4].critdamage = 1.5;
    hero[0].DSchance = 0;
    hero[1].DSchance = 12.5;
    hero[2].DSchance = 12.5;
    hero[3].DSchance = 12.5;
    hero[4].DSchance = 0;
    hero[0].block = 40;
    hero[1].block = 0;
    hero[2].block = 0;
    hero[3].block = 0;
    hero[4].block = 40;
    hero[0].evade = 12.5;
    hero[1].evade = 2.5;
    hero[2].evade = 2.5;
    hero[3].evade = 2.5;
    hero[4].evade = 12.5;
    hero[0].deflect = 5;
    hero[1].deflect = 0;
    hero[2].deflect = 0;
    hero[3].deflect = 0;
    hero[4].deflect = 5;
    hero[0].powerrune = 1;
    hero[1].powerrune = 1;
    hero[2].powerrune = 1;
    hero[3].powerrune = 1;
    hero[4].powerrune = 1;
    hero[0].agirune = 1;
    hero[1].agirune = 1;
    hero[2].agirune = 1;
    hero[3].agirune = 1;
    hero[4].agirune = 1;

        
    hpdummy = dummystamina * 10;
    dummytr = turnRate(dummypower, dummyagility);
    dummyinterval = countermax / dummytr;
    

    for(i=0 ; i<playerNo ; i++){
        //printf("How much power on hero %d ?\n", i+1);
        //scanf("%d", &hero[i].power);
        //printf("How much stamina on hero %d ?\n", i+1);
        //scanf("%d", &hero[i].stamina);
        //printf("How much agility on hero %d ?\n", i+1);
        //scanf("%d", &hero[i].agility);
        
        hero[i].power *= hero[i].powerrune;
        hero[i].agility *= hero[i].agirune;
        hero[i].hp = hero[i].stamina * 10;
        hero[i].maxhp = hero[i].hp;
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
                    petproc(i);
                    DS = RNGroll(hero[i].DSchance);
                    if (DS){
                        heroattack(i);
                        heroattack(i);
                    } else {heroattack(i);}
                    hero[i].counter -= hero[i].interval;
                    if (hpdummy<=0){
                        //printf("You killed the dummy!\n");
                        win++;
                        i = playerNo;
                        cycle = countermax;
                    }
                }
            }
            if (hpdummy > 0 && dummycounter >= dummyinterval){
                if (hero[0].hp > 0){
                    bossattack(0);
                    dummycounter -= dummyinterval;
                } else if (hero[1].hp > 0){
                    bossattack(1);
                    dummycounter -= dummyinterval;
                } else if (hero[2].hp > 0){
                    bossattack(2);
                    dummycounter -= dummyinterval;
                } else if (hero[3].hp > 0){
                    bossattack(3);
                    dummycounter -= dummyinterval;
                } else if (hero[4].hp > 0){
                    bossattack(4);
                    dummycounter -= dummyinterval;
                } else {
                    teamalive = false;
                    cycle = countermax;
                }
            }
            
        }
    }
    if (!teamalive){
        lose++;
    }

    }
    winrate = (win / 1000) * 100;
    printf("win = %f lost = %f\n", win, lose);
    printf("winrate = %f %%\n", winrate);
}
