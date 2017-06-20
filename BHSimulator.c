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
#include "dataBase.h"
#include "BHSimulator.h"
#include "Logic.h"
#include "PetLogic.h"
#include "HeroLogic.h"
#include "BossLogic.h"


Hero hero[5];           // size of array indicated max amount of heroes in team.

int dummyPower = 1700, dummyStamina = 3060, dummyAgility = 680, hpDummy, spDummy=0; //heroic Kaleido parameters

void simulation(){
    int p;
    int i;
    
    float win=0;
    float lose=0;
    float winRate;
    
    int games = 10000; //number of times fight will run.
    int playerNo;
    int counterMax = 100;
    int cycle;
    
    float dummyTR;
    float dummyInterval;
    float dummyCounter=0;
    
    bool DS;
    bool teamAlive = true;
    
    
    for (p=0 ; p < games ; p++){  // for loop to simulate as many fights as you want.
        teamAlive = true;
        playerNo = 5;
        
        sils(0);
        sss(1);
        tobey(2);
        shadown(3);
        borealis(4);

        // Next lines of code can be used if you want a specfic setup. Otherwise use players from existing database.

        /*hero[0].power = 440;
        hero[1].power = 580;
        hero[2].power = 930;
        hero[3].power = 568;
        hero[4].power = 100;
        hero[0].stamina = 692;
        hero[1].stamina = 185;
        hero[2].stamina = 186;
        hero[3].stamina = 205;
        hero[4].stamina = 1010;
        hero[0].agility = 101;
        hero[1].agility = 450;
        hero[2].agility = 240;
        hero[3].agility = 555;
        hero[4].agility = 100;
        hero[0].sp = 4;
        hero[1].sp = 4;
        hero[2].sp = 4;
        hero[3].sp = 4;
        hero[4].sp = 4;
        hero[0].critchance = 10;
        hero[1].critchance = 15;
        hero[2].critchance = 25;
        hero[3].critchance = 25;
        hero[4].critchance = 10;
        hero[0].critdamage = 1.5;
        hero[1].critdamage = 1.5;
        hero[2].critdamage = 1.5;
        hero[3].critdamage = 2;
        hero[4].critdamage = 1.5;
        hero[0].DSchance = 0;
        hero[1].DSchance = 15;
        hero[2].DSchance = 7.5;
        hero[3].DSchance = 5;
        hero[4].DSchance = 0;
        hero[0].block = 30;
        hero[1].block = 0;
        hero[2].block = 0;
        hero[3].block = 0;
        hero[4].block = 40;
        hero[0].evade = 14;
        hero[1].evade = 2.5;
        hero[2].evade = 2.5;
        hero[3].evade = 2.5;
        hero[4].evade = 12.5;
        hero[0].deflect = 5;
        hero[1].deflect = 0;
        hero[2].deflect = 0;
        hero[3].deflect = 0;
        hero[4].deflect = 5;
        hero[0].powerRune = 1;
        hero[1].powerRune = 1.175;
        hero[2].powerRune = 1.2;
        hero[3].powerRune = 1.05;
        hero[4].powerRune = 1;
        hero[0].agiRune = 1;
        hero[1].agiRune = 1;
        hero[2].agiRune = 1;
        hero[3].agiRune = 1.025;
        hero[4].agiRune = 1;         
        strcpy (hero[0].pet, "nelson");
        strcpy (hero[1].pet, "gemmi");
        strcpy (hero[2].pet, "nelson");
        strcpy (hero[3].pet, "nelson");
        strcpy (hero[4].pet, "gemmi");
        hero[0].alive = true;
        hero[1].alive = true;
        hero[2].alive = true;
        hero[3].alive = true;
        hero[4].alive = true;*/

        
        hpDummy = dummyStamina * 10;
        dummyTR = turnRate(dummyPower, dummyAgility);
        dummyInterval = counterMax / dummyTR;
    

        for(i=0 ; i<playerNo ; i++){  //initialisation
            hero[i].tr = turnRate(hero[i].power, hero[i].agility);
            hero[i].power *= hero[i].powerRune;
            hero[i].tr *= hero[i].agiRune;
            hero[i].hp = hero[i].stamina * 10;
            hero[i].maxHP = hero[i].hp;
            hero[i].interval = counterMax / hero[i].tr;
            hero[i].counter=0;
        }
    
    
        while (hpDummy>0 && teamAlive==true){           //fight will stop if either party is dead
            for(cycle=1 ; cycle<=counterMax ; cycle++){
                dummyCounter++;
                for(i=0 ; i<playerNo ; i++){
                    hero[i].counter++;
                    if(hero[i].counter >= hero[i].interval && hero[i].alive){      //checks if it's player's turn to attack
                        hpPerc();
                        hero[i].sp ++;  
                        petSelection(i);
                        DS = RNGroll(hero[i].DSchance);
                        if (DS){
                            heroAttack(i, DS);
                            DS = false;
                            heroAttack(i, DS);
                        } else {heroAttack(i, DS);}
                        hero[i].counter -= hero[i].interval;
                        if (hpDummy<=0){
                            win++;
                            i = playerNo;
                            cycle = counterMax;
                            dummyCounter = 0;
                        }
                    }
                }
                if (hpDummy > 0 && dummyCounter >= dummyInterval){         //checks if it's boss' turn to attack
                    spDummy++;
                    bossAttack();
                    dummyCounter -= dummyInterval;
                    if (hpDummy<=0){
                        win++;
                        i = playerNo;
                        cycle = counterMax;
                        dummyCounter = 0;
                    }
                    if (!hero[0].alive && !hero[1].alive && !hero[2].alive && !hero[3].alive && !hero[4].alive){
                        teamAlive = false;
                        cycle = counterMax;
                    }
                }
            }
        }
        if (!teamAlive){
            lose++;
            dummyCounter = 0;
        }
    }
    winRate = (win / games) * 100;
    printf("won = %f lost = %f\n", win, lose);
    printf("winRate = %f %%\n", winRate);         
}

int main(){
    srand((unsigned int)time(NULL));
    int i;
    for (i=0; i<1;i++){
        simulation();

		//dummyFight();
        //BHungerGames();
        //accsim();
    }
	getchar();
}
