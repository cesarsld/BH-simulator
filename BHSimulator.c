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


                        //struct will contain all stats and informations on hero. Will update its content when code gets more complex.
typedef struct {
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
Hero hero[5];           // size of array indicated max amount of heroes in team.

int dummypower = 1700, dummystamina = 3060, dummyagility = 680, hpdummy, spdummy=0;

// RNGroll serves as flag to say if roll is succesful (returns true) or not (returns false). Rolls on 1000 so that decimal aren't lost.

int rftoi(float valueToConvert)
{
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
void offpetproc(int l){
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

// defpetproc runs the code to simulate healing pets of hero[l]
void defpetproc(int l){
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
			attackvalue = dummypower*skillmodifier;
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

void heroattack(int k){
    
    int petcheck;
    petcheck = strcmp(hero[k].pet , "gemmi");
    float attackvalue = 0;
    int attackmodifier = 0.2 * hero[k].power;
    attackvalue = rand()% attackmodifier + 0.9 * hero[k].power;
    if (hero[k].sp >=2){
        float skillmodifier = (rand()% 50 +110);
        skillmodifier /=100;
        attackvalue = hero[k].power * skillmodifier;
        hero[k].sp -=2;
        
    }
    bool critroll = RNGroll(hero[k].critchance);
    if (critroll){
        attackvalue *= hero[k].critdamage;
    }
    bool evaderoll = RNGroll(2.5);
    if (!evaderoll){
        hpdummy -= attackvalue;
        if (petcheck==0){
            defpetproc(k);
        } else {offpetproc(k);}
    }
}

void bossattack(){
    int k;
	float attackvalue= 10;
	//float *transfer = &attackvalue;
	int target;
	target = BossSkillSelection(spdummy, &attackvalue);
	
	k = TargetSelection(target);
    
    int petcheck;

    bool blockroll, evaderoll, deflectroll, redirectroll;
    
    
    
    //int attackmodifier = 0.2 * dummypower;
    
    //attackvalue = rand()% attackmodifier + 0.9 * dummypower;
    
    /*if (spdummy >=2){
        int skillSelection = rand()% 2;
        if (skillSelection == 0){
            float skillmodifier = (rand()% 126 +94);
            skillmodifier /=100;
            attackvalue = dummypower*skillmodifier;
            spdummy -=2;
        } else {
            float skillmodifier = (rand()% 126 +94);
            skillmodifier /=100;
            attackvalue = dummypower*skillmodifier;
            spdummy -=2;
        }
    }*/
    bool critroll = RNGroll(10);
    redirectroll = RNGroll(25);
    if (redirectroll){
        k = 4;
    }
    petcheck = strcmp(hero[k].pet , "gemmi");
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
                    if (petcheck==0){
                        defpetproc(k);
                    } else {offpetproc(k);}
                }
            } else {
                hero[k].hp -= attackvalue;
                if (hero[k].hp <= 0){
                    hero[k].alive = false;
                } else {
                    if (petcheck==0){
                        defpetproc(k);
                    } else {
                        offpetproc(k);
                    }
                }
            }
        }
    } else {hpdummy -= attackvalue;}
}

int healLogic(){
    int i;
    int lowest = 0;
    
    for (i=0 ; i<5 ; i++){
        hero[i].hpPerc = hero[i].hp / hero[i].maxhp;
    }
    for (i=0 ; i<4 ; i++){
        if (hero[i].hpPerc <= hero[i+1].hpPerc){
            lowest = i;
        } else { lowest = i+1;}
    }
    return lowest;
}

void spreadHealing(int k){
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
    }
}

void simulation(){
    int p;
    float win=0;
    float lose=0;
    float winrate;
    
    for (p=0 ; p < 100000 ; p++){  // for loop to simulate as many fights as you want
    dummypower = 1700;
    dummystamina = 3060;
    dummyagility = 680;
    int countermax = 100;
    int playerNo;
    int i;
    int cycle;
        int petcheck;
    
    float dummytr;
    float dummycounter=0;
    float dummyinterval;
    
    bool DS;
    bool teamalive = true;
    
   // printf("How many heroes will you use?\n");
   // scanf("%d", &playerNo);
    playerNo = 5;
        hero[0].power = 444;
        hero[1].power = 515;
        hero[2].power = 615;
        hero[3].power = 559;
        hero[4].power = 100;
        hero[0].stamina = 692;
        hero[1].stamina = 185;
        hero[2].stamina = 186;
        hero[3].stamina = 205;
        hero[4].stamina = 1010;
        hero[0].agility = 101;
        hero[1].agility = 515;
        hero[2].agility = 567;
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
        hero[1].DSchance = 19.5;
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
        hero[1].powerrune = 1.125;
        hero[2].powerrune = 1.2;
        hero[3].powerrune = 1.05;
        hero[4].powerrune = 1;
        hero[0].agirune = 1;
        hero[1].agirune = 1;
        hero[2].agirune = 1;
        hero[3].agirune = 1.025;
        hero[4].agirune = 1;
        /*
        strcpy_s (hero[0].pet, 10, "nelson");
        strcpy_s (hero[1].pet, 10, "gemmi");
        strcpy_s (hero[2].pet, 10, "nelson");
        strcpy_s (hero[3].pet, 10, "nelson");
        strcpy_s (hero[4].pet, 10, "gemmi");

         */
        strcpy (hero[0].pet, "nelson");
        strcpy (hero[1].pet, "gemmi");
        strcpy (hero[2].pet, "nelson");
        strcpy (hero[3].pet, "nelson");
        strcpy (hero[4].pet, "gemmi");
        hero[0].alive = true;
        hero[1].alive = true;
        hero[2].alive = true;
        hero[3].alive = true;
        hero[4].alive = true;

        
        /*hero[0].power = 443;
        hero[1].power = 512;
        hero[2].power = 502;
        hero[3].power = 615;
        hero[4].power = 448;
        hero[0].stamina = 684;
        hero[1].stamina = 205;
        hero[2].stamina = 200;
        hero[3].stamina = 167;
        hero[4].stamina = 525;
        hero[0].agility = 101;
        hero[1].agility = 555;
        hero[2].agility = 502;
        hero[3].agility = 560;
        hero[4].agility = 216;
        hero[0].sp = 0;
        hero[1].sp = 0;
        hero[2].sp = 0;
        hero[3].sp = 0;
        hero[4].sp = 0;
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
        hero[1].powerrune = 1.15;
        hero[2].powerrune = 1.15;
        hero[3].powerrune = 1.15;
        hero[4].powerrune = 1.15;
        hero[0].agirune = 1;
        hero[1].agirune = 1;
        hero[2].agirune = 1;
        hero[3].agirune = 1;
        hero[4].agirune = 1;*/


        
    hpdummy = dummystamina * 10;
    dummytr = turnRate(dummypower, dummyagility);
    dummyinterval = countermax / dummytr;
    

    for(i=0 ; i<playerNo ; i++){            //initialises heroes' variables
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
                    hero[i].sp ++;
                    petcheck = strcmp(hero[i].pet , "gemmi");
                    if (petcheck==0){
                        defpetproc(i);
                    } else {offpetproc(i);}
                    DS = RNGroll(hero[i].DSchance);
                    if (DS){
                        heroattack(i);
                        heroattack(i);
                        //printf("kal hp = %d\n", hpdummy);
                    } else {heroattack(i);}
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
                if (!hero[0].alive && !hero[1].alive && !hero[2].alive && !hero[3].alive && !hero[4].alive){
                    teamalive = false;
                    cycle = countermax;
                }
                /*if (hero[0].hp > 0){
                    bossattack(0);
                    dummycounter -= dummyinterval;
                    //printf("hero 0 hp = %d\n", hero[0].hp);
                } else if (hero[1].hp > 0){
                    bossattack(1);
                    dummycounter -= dummyinterval;
                    //printf("hero 1 hp = %d\n", hero[1].hp);

                } else if (hero[2].hp > 0){
                    bossattack(2);
                    dummycounter -= dummyinterval;
                    //printf("hero 2 hp = %d\n", hero[2].hp);

                } else if (hero[3].hp > 0){
                    bossattack(3);
                    dummycounter -= dummyinterval;
                    //printf("hero 3 hp = %d\n", hero[3].hp);

                } else if (hero[4].hp > 0){
                    bossattack(4);
                    dummycounter -= dummyinterval;
                    //printf("hero 4 hp = %d\n", hero[4].hp);

                } else {
                    teamalive = false;
                    cycle = countermax;
                }*/
            }
            
        }
    }
    if (!teamalive){
        lose++;
    }

    }
    winrate = (win / 100000) * 100;
    printf("win = %f lost = %f\n", win, lose);
    printf("winrate = %f %%\n", winrate);         // winrate %. Change winrate denominator to adjust % value.

	//getchar();
}

void dummyfight() {
    float power = 1000, stamina = 100, agility = 100, crit = 10, countermax = 100;
    float tr, critdmg = 1, ds = 0, interval ,counter = 0, prune = 1, arune = 1, critattack;
    power *= prune;
    stamina = 100;
    agility *= arune;
    critattack = power * critdmg;

    tr = turnRate(power, agility);
    interval = countermax / tr;
    bool critroll, dsroll;
    long i;
    int cycle, hitdone = 0, normalhit=0, crithit =0;
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
                critroll = RNGroll(crit);
                if(critroll){
                    damagedone += critattack;
                    crithit++;
                } else {
                    damagedone += power;
                    normalhit++;
                }
                counter -=interval;
                
            }
        }
    }
    long long dps;
    dps = damagedone / i;
    printf("damage = %lld\n", damagedone);
    //printf("hits = %d\n", hitdone);
    //printf("normal hits = %d\n", normalhit);
   // printf(" crithits = %d\n", crithit);
 //   printf("dps = %lld\n", dps);
    
}

int main(){
    srand((unsigned int)time(NULL));
    //simulation();
    int i;
    for (i=0; i<5;i++){
        dummyfight();
    }
}
