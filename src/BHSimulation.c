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
#include "logic.h"
#include "hero.h"
#include "enemy.h"
#define FIGHTCOUNT 100000
#define HERO_COUNT 5

enum pet{ nelson = 0, gemmi = 1};

void func()
{
    int p;
    float win=0;
    float lose=0;
    float winrate;
    // Boss stats
    // Initialize heroes
    //                  pwr, stam, agi, cc, cd,   ds, bl,  ev,  def,pwr_r/agi_r, pet
    Hero * h0 = newHero(443, 1034, 101, 10, 1.5, 0,    40, 12.5, 5, 1, 1,    nelson);
    Hero * h1 = newHero(712, 205,  705, 20, 2,   12.5,  0,  2.5, 0, 1, 1,    gemmi);
    Hero * h2 = newHero(702, 200,  652, 20, 2,   12.5,  0,  2.5, 0, 1, 1,    gemmi);
    Hero * h3 = newHero(815, 167,  710, 25, 1.5, 12.5,  0,  2.5, 0, 1, 1.15, nelson);
    Hero * h4 = newHero(448, 875,  216, 10, 1.5, 12.5, 40, 12.5, 5, 1, 1,    gemmi);
    // put into party array
    Hero *party[HERO_COUNT] = {h0,h1,h2,h3,h4};

    //init Boss
    Enemy * boss = newEnemy(1700, 3060, 680);
    srand((unsigned int)time(NULL));

    for (p=0 ; p < FIGHTCOUNT ; p++){  // for loop to simulate as many fights as you want
        enemyRestore(boss);
        for (int i=0; i<HERO_COUNT; i++){
            heroRestore(party[i]);
        }

        int countermax = 100;
        int i;
        int cycle;
        bool DS;
        bool teamalive = true;

        //fight will stop if either party is dead
        while (boss->hp > 0 && teamalive == true){
            for(cycle = 1; cycle <= countermax; cycle++){
                boss->counter++;
                for(i=0 ; i<HERO_COUNT ; i++){
                    party[i]->counter++;
                    //checks if it's player's turn to attack
                    if(party[i]->counter >= party[i]->interval && party[i]->hp > 0){
                        party[i]->sp ++;
                        if (*party[i]->pet == gemmi){
                            defpetproc(party[i], party);
                        } else {offpetproc(party[i], boss);}
                        DS = RNGroll(party[i]->DSchance);
                        if (DS){
                            heroattack(party[i], party, boss);
                            heroattack(party[i], party, boss);
                            //printf("kal hp = %d\n", boss->hp);
                        } else {heroattack(party[i],party,boss);}
                        //printf("kal hp = %d\n", boss->hp);}
                        party[i]->counter -= party[i]->interval;
                        if (boss->hp<=0){
                            //printf("You killed the dummy!\n");
                            win++;
                            i = HERO_COUNT;
                            cycle = countermax;
                        }
                    }
                }
                //checks if it's boss' turn to attack
                if (boss->hp > 0 && boss->counter >= boss->interval){
                    boss->sp++;
                    if (party[0]->hp > 0){
                        bossattack(party[0], party, boss );
                        boss->counter -= boss->interval;
                        //printf("hero 0 hp = %d\n", hero[0]->hp);
                    } else if (party[1]->hp > 0){
                        bossattack(party[1], party, boss );
                        boss->counter -= boss->interval;
                        //printf("hero 1 hp = %d\n", hero[1]->hp);

                    } else if (party[2]->hp > 0){
                        bossattack(party[2], party, boss );
                        boss->counter -= boss->interval;
                        //printf("hero 2 hp = %d\n", hero[2]->hp);

                    } else if (party[3]->hp > 0){
                        bossattack(party[3], party, boss );
                        boss->counter -= boss->interval;
                        //printf("hero 3 hp = %d\n", hero[3]->hp);

                    } else if (party[4]->hp > 0){
                        bossattack(party[4], party, boss );
                        boss->counter -= boss->interval;
                        //printf("hero 4 hp = %d\n", hero[4]->hp);

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
    winrate = (win / 100000) * 100;
    printf("win = %f lost = %f\n", win, lose);
    // winrate %. Change winrate denominator to adjust % value.
    printf("winrate = %f %%\n", winrate);
}
