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
#include "dataBase.h"
#include "BHSimulator.h"
#include "BHungerGames.h"


Hero hero[5];           // size of array indicated max amount of heroes in team.


int dummypower = 1700, dummystamina = 3060, dummyagility = 680, hpdummy, spdummy=0;

// RNGroll serves as flag to say if roll is succesful (returns true) or not (returns false). Rolls on 1000 so that decimal aren't lost.

int rftoi(float valueToConvert){
	int intValueToConvert = (int)valueToConvert;
	valueToConvert -= intValueToConvert;
	if (valueToConvert >= 0.5) {
		intValueToConvert += 1;
	}
	return intValueToConvert;
}

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
void offPetProc(int l){
	int attackmodifier = hero[l].power * 0.54;
    int attackvalue = rand()% attackmodifier + hero[l].power * 0.63;
	
    
    bool critroll = RNGroll(hero[l].critchance);
    bool petroll = RNGroll(20);
    
    if (critroll){
        attackvalue *= hero[l].critdamage;
    }
    if (petroll){
        hpdummy -= attackvalue;
    }
    
}

void superOffPetProc(int l){
    int attackmodifier = hero[l].power * 0.37;
    int attackvalue = rand()% attackmodifier + hero[l].power * 1.668;
    
    
    bool critroll = RNGroll(hero[l].critchance);
    bool petroll = RNGroll(10);
    
    if (critroll){
        attackvalue *= hero[l].critdamage;
    }
    if (petroll){
        hpdummy -= attackvalue;
    }
    
}

// teamHeal runs the code to simulate healing pets of hero[l]
void teamHeal(int l){
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

void hpPerc() {
    int i;
    for (i=0 ; i<5 ; i++){
        hero[i].hpPerc = (float) hero[i].hp / hero[i].maxhp;
    }
}

int healLogic(){
    int i;
    int lowest = 0;
    hpPerc();
    for (i=0 ; i<4 ; i++){
        if (hero[i].hpPerc <= hero[i+1].hpPerc){
            if (hero[i].alive){
                lowest = i;
            }
        } else {
            if (hero[i+1].alive){
                lowest = i+1;
            }
        }
    }
    return lowest;
}

void spreadHealingSkill(int k){
    int i;
    int target=0;
    int healingvalue = 0;
    int healingmodifier = 0.365 * hero[k].power;
    
    healingvalue = rand()% healingmodifier + 0.73 * hero[k].power;
    
    bool critroll = RNGroll(hero[k].critchance);
    if (critroll){
        healingvalue *= hero[k].critdamage;
    }
    
    for (i=0 ; i < healingvalue ; i++){
        target = healLogic();
        hero[target].hp++;
        if (hero[target].hp > hero[target].maxhp){
            hero[target].hp = hero[target].maxhp;
        }
    }
}

void spreadHealPet (int l){
    int i;
    int target = 0;
    int healmodifier = hero[l].power * 0.14;
    int healvalue = rand()% healmodifier + 0.66 * hero[l].power;
    
    bool critroll = RNGroll(hero[l].critchance);
    bool petroll = RNGroll(20);
    
    if (critroll){
        healvalue *= hero[l].critdamage;
    }
    if (petroll){
        for (i=0 ; i < healvalue ; i++){
            target = healLogic();
            hero[target].hp++;
            if (hero[target].hp > hero[target].maxhp){
                hero[target].hp = hero[target].maxhp;
            }
        }
    }
}

void petSelection(int k){
    int petcheck;
    petcheck = strcmp(hero[k].pet , "gemmi");
    if (petcheck == 0){
        teamHeal(k);
    }
    petcheck = strcmp(hero[k].pet , "nelson");
    if (petcheck == 0){
        offPetProc(k);
    }
    petcheck = strcmp(hero[k].pet , "boogie");
    if (petcheck == 0){
        spreadHealPet(k);
    }
    petcheck = strcmp(hero[k].pet , "nemo");
    if (petcheck == 0){
        superOffPetProc(k);
    }

}

// Calculates the turn rate of each entity in the fight by taking power and agility.
float turnRate(long b, long a){
    float tr = 0;
    tr = ((a + b)/2);
    tr = pow(tr, 2);
    tr = tr/(100*b);
    return tr;
}

int TargetSelection(int method){
    int target = 0;
    int i = 0;
    bool targetLocked = false;
	if (method == 1) {
		while (!targetLocked) {
			if (hero[i].alive) {
				target = i;
				targetLocked = true;
			}
			i++;
		}
	}
	if (method == 2) {
		i = 4;
		while (!targetLocked) {
			if (hero[i].alive) {
				target = i;
				targetLocked = true;
			}
			i--;
		}
	}
	if (method == 3) {
		while (!targetLocked) {
			i = rand() % 5;
			if (hero[i].alive) {
				target = i;
				targetLocked = true;
			}
		}
	}
    return target;
}

int BossSkillSelection(int sp,  float *finalAttack) {
	float attackvalue = 0;
	int skillRoll = 0;
	int attackmodifier = 0;
	int targetMethod = 0;

	if (sp < 2) {
		//normal attack
		attackmodifier = 0.2 * dummypower;
		attackvalue = rand() % attackmodifier + 0.9 * dummypower;
		targetMethod = 1;
	}
	else if (sp < 4 ) {
		// 1 sp skill AI
		skillRoll = rand() % 100;
		if (skillRoll < 20) {
			attackmodifier = 0.2 * dummypower;
			attackvalue = rand() % attackmodifier + 0.9 * dummypower;
			targetMethod = 1;
		}
		else if (skillRoll >= 20 && skillRoll < 60) {
			float skillmodifier = (rand() % 126 + 94);
			skillmodifier /= 100;
			attackvalue = dummypower*skillmodifier;
			spdummy -= 2;
			targetMethod = 1;
		}
		else if (skillRoll >= 60) {
			float skillmodifier = (rand() % 132 + 99);
			skillmodifier /= 100;
			attackvalue = dummypower*skillmodifier;
			spdummy -= 2;
			targetMethod = 2;
		}
	}
	else if (sp < 6) {
		// 1 - 2 sp skill AI
		skillRoll = rand() % 100;
		if (skillRoll < 15) {
			attackmodifier = 0.2 * dummypower;
			attackvalue = rand() % attackmodifier + 0.9 * dummypower;
			targetMethod = 1;
		}
		else if (skillRoll >= 15 && skillRoll < 55) {
			float skillmodifier = (rand() % 126 + 94);
			skillmodifier /= 100;
			attackvalue = dummypower*skillmodifier;
			spdummy -= 2;
			targetMethod = 1;
		}
		else if (skillRoll >= 55 && skillRoll < 95) {
			float skillmodifier = (rand() % 132 + 99);
			skillmodifier /= 100;
			attackvalue = dummypower*skillmodifier;
			spdummy -= 2;
			targetMethod = 2;
		}
		else if (skillRoll >= 95) {
			float skillmodifier = (rand() % 136 + 102);
			skillmodifier /= 100;
			attackvalue = dummypower*skillmodifier;
			spdummy -= 4;
			targetMethod = 3;
		}
	}
	else if (sp < 8) {
		// 1 - 2 sp skill AI
		skillRoll = rand() % 100;
		if (skillRoll < 5) {
			attackmodifier = 0.2 * dummypower;
			attackvalue = rand() % attackmodifier + 0.9 * dummypower;
			targetMethod = 1;
		}
		else if (skillRoll >= 5 && skillRoll < 50) {
			float skillmodifier = (rand() % 126 + 94);
			skillmodifier /= 100;
			attackvalue = dummypower*skillmodifier;
			spdummy -= 2;
			targetMethod = 1;
		}
		else if (skillRoll >= 50 && skillRoll < 95) {
			float skillmodifier = (rand() % 132 + 99);
			skillmodifier /= 100;
			attackvalue = dummypower*skillmodifier;
			spdummy -= 2;
			targetMethod = 2;
		}
		else if (skillRoll >= 95) {
			float skillmodifier = (rand() % 136 + 102);
			skillmodifier /= 100;
			attackvalue = dummypower * skillmodifier;
			spdummy -= 4;
			targetMethod = 3;
		}
	}
	else if (sp == 8) {
		// 1 - 2 sp skill AI
		skillRoll = rand() % 100;
		if (skillRoll < 0) {
			attackmodifier = 0.2 * dummypower;
			attackvalue = rand() % attackmodifier + 0.9 * dummypower;
			targetMethod = 1;
		}
		else if (skillRoll >= 0 && skillRoll < 45) {
			float skillmodifier = (rand() % 126 + 94);
			skillmodifier /= 100;
			attackvalue = dummypower*skillmodifier;
			spdummy -= 2;
			targetMethod = 1;
		}
		else if (skillRoll >= 45 && skillRoll < 95) {
			float skillmodifier = (rand() % 132 + 99);
			skillmodifier /= 100;
			attackvalue = dummypower*skillmodifier;
			spdummy -= 2;
			targetMethod = 2;
		}
		else if (skillRoll >= 90) {
			float skillmodifier = (rand() % 136 + 102);
			skillmodifier /= 100;
			attackvalue = dummypower*skillmodifier;
			spdummy -= 4;
			targetMethod = 3;
		}
	}
	*finalAttack = attackvalue;
	return targetMethod;
}

void heroattack(int k, bool dual){
    int skillSelection;
    float attackvalue = 0;
    int attackmodifier = 0.2 * hero[k].power;
    attackvalue = rand()% attackmodifier + 0.9 * hero[k].power;
    if (hero[k].sp >=2){
        skillSelection = rand() % 100;
		if (skillSelection < 20 && (hero[0].hpPerc < 0.85 || hero[4].hpPerc < 0.85)) {
			spreadHealingSkill(k);
			if (!dual) {
				hero[k].sp -= 2;
			}
		}
        else {
            float skillmodifier = (rand()% 50 +110);
            skillmodifier /=100;
            attackvalue = hero[k].power * skillmodifier;
			if (!dual) {
				hero[k].sp -= 2;
			}
        }
    }
    bool critroll = RNGroll(hero[k].critchance);
    if (critroll){
        attackvalue *= hero[k].critdamage;
    }
    bool evaderoll = RNGroll(2.5);
    if (!evaderoll){
        hpdummy -= attackvalue;
        petSelection(k);
    }
}

void bossattack(){
    int k;
	float attackvalue= 0;
	int target;
	target = BossSkillSelection(spdummy, &attackvalue);
	
	k = TargetSelection(target);
    
    bool blockroll, evaderoll, deflectroll, redirectroll;
    
    bool critroll = RNGroll(10);
    redirectroll = RNGroll(25);
    if (redirectroll){
        k = 4;
    }
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
                if (hero[k].hp <= 0){
                    hero[k].alive = false;
                } else {
                    petSelection(k);
                }
            } else {
                hero[k].hp -= attackvalue;
                if (hero[k].hp <= 0){
                    hero[k].alive = false;
                } else {
                    petSelection(k);
                }
            }
        }
    } else {
        hpdummy -= attackvalue;
        
    }
}

void simulation(){
    int p;
    float win=0;
    float lose=0;
    float winrate;
    int games = 10000;
    
    for (p=0 ; p < games ; p++){  // for loop to simulate as many fights as you want
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
        
        sils(0);
        sss(1);
        tobey(2);
        shadown(3);
        borealis(4);
        
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
        hero[0].powerrune = 1;
        hero[1].powerrune = 1.175;
        hero[2].powerrune = 1.2;
        hero[3].powerrune = 1.05;
        hero[4].powerrune = 1;
        hero[0].agirune = 1;
        hero[1].agirune = 1;
        hero[2].agirune = 1;
        hero[3].agirune = 1.025;
        hero[4].agirune = 1;
        
        //strcpy_s (hero[0].pet, 10, "nelson");
        //strcpy_s (hero[1].pet, 10, "gemmi");
        //strcpy_s (hero[2].pet, 10, "nelson");
        //strcpy_s (hero[3].pet, 10, "nelson");
        //strcpy_s (hero[4].pet, 10, "gemmi");

         
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

        
    hpdummy = dummystamina * 10;
    dummytr = turnRate(dummypower, dummyagility);
    dummyinterval = countermax / dummytr;
    

    for(i=0 ; i<playerNo ; i++){
        //initialises heroes' variables
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
    
    
    while (hpdummy>0 && teamalive==true){           //fight will stop if either party is dead
        for(cycle=1 ; cycle<=countermax ; cycle++){
            dummycounter++;
            for(i=0 ; i<playerNo ; i++){
                hero[i].counter++;
                if(hero[i].counter >= hero[i].interval && hero[i].alive){      //checks if it's player's turn to attack
                    hpPerc();
                    hero[i].sp ++;
                    petSelection(i);
                    DS = RNGroll(hero[i].DSchance);
                    if (DS){
                        heroattack(i, DS);
						DS = false;
                        heroattack(i, DS);
                        //printf("kal hp = %d\n", hpdummy);
                    } else {heroattack(i, DS);}
                        //printf("kal hp = %d\n", hpdummy);}
                    hero[i].counter -= hero[i].interval;
                    if (hpdummy<=0){
                        //printf("You killed the dummy!\n");
                        win++;
                        i = playerNo;
                        cycle = countermax;
                    }
                }
            }
            if (hpdummy > 0 && dummycounter >= dummyinterval){         //checks if it's boss' turn to attack
                spdummy++;
                bossattack();
                dummycounter -= dummyinterval;
                if (hpdummy<=0){
                    win++;
                    i = playerNo;
                    cycle = countermax;
                }

                if (!hero[0].alive && !hero[1].alive && !hero[2].alive && !hero[3].alive && !hero[4].alive){
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
    winrate = (win / games) * 100;
    printf("won = %f lost = %f\n", win, lose);
    printf("winrate = %f %%\n", winrate);         // winrate %. Change winrate denominator to adjust % value.

}

void dummyFight() {
    long power = 1200, stamina = 100, agility = 0, crit = 0, countermax = 100;
    double critdmg = 1, ds = 0, interval ,counter = 0, prune = 1.25, arune = 1, critattack;
    float tr;
    power *= prune;
    stamina = 100;
    agility *= arune;
    critattack = power * critdmg;

    tr = turnRate(power, agility);
    interval = countermax / tr;
    bool critroll, dsroll;
    long i;
    long long cycle, hitdone = 0, normalhit=0, crithit =0;
    long long damagedone=0;
    for (i=0;i<1000000;i++){
        for (cycle = 0 ; cycle <100 ; cycle++){
            counter++;
            if (counter >= interval){
                hitdone++;
                dsroll = RNGroll(ds);
                
                if(dsroll){
                    critroll = RNGroll(crit);
                    if(critroll){
                        damagedone += critattack;
                        crithit++;
                    } else {
                        damagedone += power;
                        normalhit++;
                    }
                    critroll = RNGroll(crit);
                    if(critroll){
                        damagedone += critattack;
                        crithit++;
                    } else {
                        damagedone += power;
                        normalhit++;
                    }
                }
                else {
                    critroll = RNGroll(crit);
                    if(critroll){
                        damagedone += critattack;
                        crithit++;
                    } else {
                    damagedone += power;
                    normalhit++;
                    }
                }
                
                counter -=interval;
                
            }
        }
    }
    long long dps;
    dps = damagedone / i;
    printf("damage = %lld\n", damagedone);
    printf("hits = %lld\n", hitdone);
    printf("normal hits = %lld\n", normalhit);
    printf(" crithits = %lld\n", crithit);
    printf("dps = %lld\n", dps);
    
}

void accsim(){
    int i;
    int sim=1000000;
    int roll1=0, roll2=0, roll3=0;
    float deflectcount=0, evadecount=0, blockcount=0;
    int deflect=625, evade=100, block = 25;
    float dmgreduction=0;
    int proccount=0;
    float dproc, eproc, bproc;
    for (i=0; i<sim; i++ ){
        roll1 = rand()%10000+1;
        if (roll1 > deflect){
            roll2 = rand()%1000+1;
            if (roll2 > evade){
                roll3 = rand()%100+1;
                if (roll3 <= block){
                    blockcount++;
                }
            } else evadecount++;
        } else deflectcount++;
    }
    dproc=100*deflectcount/sim;
    eproc=100*(evadecount/sim);
    bproc=100*(blockcount/sim);
    
    printf("deflect: %f/%d = %f %% \nevade: %f/%d = %f %%\nblock: %f/%d = %f %%\n", deflectcount, sim, dproc, evadecount, sim, eproc, blockcount, sim, bproc);
    proccount = deflectcount + evadecount + blockcount;
    dmgreduction = 100 * (1-((sim-proccount+blockcount * 0.5)/sim));
    printf("Damage mitigation: %f%%\n", dmgreduction);
}

int main(){
    srand((unsigned int)time(NULL));
    int i;
    for (i=0; i<1;i++){
        //dummyFight();
        //simulation();
       BHungerGames();
        //accsim();
		getchar();
    }
}
