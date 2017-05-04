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
#include "hero.h"
#include "enemy.h"

enum pet{nelson = 0, gemmi = 1};
// RNGroll serves as flag to say if roll is succesful (returns true) or not
//(returns false). Rolls on 1000 so that decimal aren't lost.
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

// offpetproc runs the code to simulate damaging pets of hero [l]
void offpetproc(Hero* hero, Enemy* boss){
    int attackmodifier = hero->power * 0.54;
    int attackvalue = rand()% attackmodifier + hero->power * 0.63;

    bool critroll = RNGroll(hero->critchance);
    bool petroll = RNGroll(20);

    if (critroll){
        attackvalue *= hero->critdamage;
    }
    if (petroll){
        boss->hp -= attackvalue;
    }

}

// defpetproc runs the code to simulate healing pets of hero[l]
void defpetproc(Hero* hero, Hero **party){
    int healmodifier = hero->power * 0.072;
    int healvalue = rand()% healmodifier + 0.324 * hero->power;

    bool critroll = RNGroll(hero->critchance);
    bool petroll = RNGroll(20);

    if (critroll){
        healvalue *= hero->critdamage;
    }

    if (petroll){
        for (int i = 0 ; i < 5 ; i++){
            if (hero->hp > 0){
                party[i]->hp += healvalue;
                if (party[i]->hp >= party[i]->maxhp){
                    party[i]->hp = party[i]->maxhp;
                }
            }
        }
    }
}

void heroattack(Hero* hero, Hero **party, Enemy* boss){
    float attackvalue = 0;
    int attackmodifier = 0.2 * hero->power;
    attackvalue = rand()% attackmodifier + 0.9 * hero->power;
    if (hero->sp >=2){
        float skillmodifier = (rand()% 50 +110);
        skillmodifier /=100;
        attackvalue = hero->power * skillmodifier;
        hero->sp -= 2;
    }
    bool critroll = RNGroll(hero->critchance);
    if (critroll){
        attackvalue *= hero->critdamage;
    }
    bool evaderoll = RNGroll(2.5);
    if (!evaderoll){
        boss->hp -= attackvalue;
        if (*hero->pet == gemmi){
            defpetproc(hero, party);
        } else {offpetproc(hero, boss);}
    }
}

void bossattack(Hero* hero, Hero **party, Enemy* boss){
    bool blockroll, evaderoll, deflectroll;
    float attackvalue = 0 ;
    int attackmodifier = 0.2 * boss->power;
    attackvalue = rand()% attackmodifier + 0.9 * boss->power;

    if (boss->sp >=2){
        float skillmodifier = (rand()% 126 +94);
        skillmodifier /=100;
        attackvalue *= skillmodifier;
        boss->sp -=2;
    }
    bool critroll = RNGroll(10);
    if (critroll){
        attackvalue *= 1.5;
    }
    deflectroll = RNGroll(hero->deflect);
    if (!deflectroll){
        evaderoll = RNGroll(hero->evade);
        if (!evaderoll){
            blockroll = RNGroll(hero->block);
            if (blockroll){
                hero->hp -= 0.5 * attackvalue;
                defpetproc(hero, party);
            } else { hero->hp -= attackvalue;
                if (*hero->pet == gemmi){
                    defpetproc(hero, party);
                } else {offpetproc(hero, boss);}
            }
        }
    } else {boss->hp -= attackvalue;}
}
