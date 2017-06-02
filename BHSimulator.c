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
        
        byleth(0);
        byleth(1);
        byleth(2);
        byleth(3);
        byleth(4);
        
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
    printf("won = %f lost = %f\n", win, lose);
    printf("winrate = %f %%\n", winrate);         // winrate %. Change winrate denominator to adjust % value.

	//getchar();
}

void dummyFight() {
    long power = 100, stamina = 100, agility = 1100, crit = 0, countermax = 100;
    double critdmg = 1, ds = 0, interval ,counter = 0, prune = 1, arune = 1.25, critattack;
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

void Scenarios(char name[20], char nameA[20], char nameB[20], int player){
    int a = rand() % 5;
    if (a ==0 && player > 2){
        printf ("%s made an alliance with %s to kill %s. But %s shouldn't have trusted %s... %s has killed %s.\n" ,name, nameA, nameB, name, nameA, nameA, name);
    } else if (a==1){
        printf("%s stepped on a mine. What a shame.\n", name);
    } else if (a==2){
        printf("%s is extremely hungry. He hasn't eaten for days. He sees %s eating some berries in the forest but %s drops dead. ''I wonder what human flesh tastes like!'' tells %s to himself.\n", nameA, name, name, nameA);
    } else if (a==3){
        printf("%s got mauled by genetically modified Korgz.\n", name);
    } else if (a==4){
        printf("%s died of a wound infection inflicted by %s whilst fighting for some ressources.\n", name, nameA);
    } else if (a==5) {
        printf ("A giant rock fell on %s's head... But how?\n", name);
    } else if (a==6){
        printf ("It's a miracle! %s escaped from the deadly Nosdoodoo! Oh wait! Never mind, %s just got eaten by Blubber...\n", name ,name);
    }
}

void BHungerGames(){
    //
    
    typedef struct BHG {
        char name[20];
        float chance;
        bool result;
        bool alive;
    } Contestants;
    
    Contestants contestants[15];
    
    strcpy(contestants[0].name, "Hai");
    strcpy(contestants[1].name, "Trakomo");
    strcpy(contestants[2].name, "Yozu");
    strcpy(contestants[3].name, "Remmark");
    strcpy(contestants[4].name, "Taphos");
    strcpy(contestants[5].name, "Smiley");
    strcpy(contestants[6].name, "Yamanba");
    strcpy(contestants[7].name, "Murtida");
    strcpy(contestants[8].name, "Angery");
    strcpy(contestants[9].name, "Lagenda");
    strcpy(contestants[10].name, "Herkk");
    strcpy(contestants[11].name, "Broxy");
    strcpy(contestants[12].name, "Phear");
    strcpy(contestants[13].name, "Miskat");
    strcpy(contestants[14].name, "Brandc");

    
    
    contestants[0].chance = 90;
    contestants[1].chance = 90;
    contestants[2].chance = 90;
    contestants[3].chance = 90;
    contestants[4].chance = 90;
    contestants[5].chance = 90;
    contestants[6].chance = 90;
    contestants[7].chance = 90;
    contestants[8].chance = 90;
    contestants[9].chance = 90;
    contestants[10].chance = 90;
    contestants[11].chance = 90;
    contestants[12].chance = 90;
    contestants[13].chance = 90;
    contestants[14].chance = 90;
    
    contestants[0].alive = true;
    contestants[1].alive = true;
    contestants[2].alive = true;
    contestants[3].alive = true;
    contestants[4].alive = true;
    contestants[5].alive = true;
    contestants[6].alive = true;
    contestants[7].alive = true;
    contestants[8].alive = true;
    contestants[9].alive = true;
    contestants[10].alive = true;
    contestants[11].alive = true;
    contestants[12].alive = true;
    contestants[13].alive = true;
    contestants[14].alive = true;

    
    contestants[0].alive = false;
    contestants[1].alive = false;
    contestants[2].alive = false;
    contestants[3].alive = false;
    contestants[4].alive = false;
    contestants[5].alive = false;
    contestants[6].alive = false;
    //contestants[7].alive = false;
    contestants[8].alive = false;
    //contestants[9].alive = false;
    contestants[10].alive = false;
    contestants[11].alive = false;
    contestants[12].alive = false;
    contestants[13].alive = false;
    contestants[14].alive = false;
    
    int playerAlive=0;
    int j;
    for (j=0;j<15;j++){
        if (contestants[j].alive){
            playerAlive++;
        }
    }
    int i;
    int a = 0, b = 0;
    for (i=0 ; i<15 ; i++){
        if (contestants[i].alive){
            contestants[i].result = RNGroll(contestants[i].chance);
            if (!contestants[i].result){
                bool target1 = false, target2 = false;
                while (!target1){
                     a = rand()%15;
                    if (contestants[a].alive){
                        target1 = true;
                    }
                }
                while (!target2){
                     b = rand()%15;
                    if (contestants[b].alive && a != b){
                        target2 = true;
                    }
                }
                Scenarios(contestants[i].name, contestants[a].name, contestants[b].name, playerAlive);
            }
        }
    }
    


    
    /*
Hello Bit Heroes!
Welcome to the 8th BHungerGames!
I come to you as I can offer something you greatly want.... A place in my friendlist... You read right!
I will give a friend slot to one of you..... IF you manage to outclass the other contenders...
You will be placed in an arena.. an RNG arena. Each contestant has 90% of chance to survive in the arena....
I will take **15 contestants**. Who dares come forward?
Put a :shadown: if you want to participate. First 15 will enter the game.
May the odds be ever in your favour.

     */
}

int main(){
    srand((unsigned int)time(NULL));
    int i;
    for (i=0; i<1;i++){
        //dummyFight();
        //simulation();
        BHungerGames();
    }
    //int a = test(2, 3);
    //printf("%d", a);
}
