//
//  BHSimulator.c
//  BH Simulator
//
//  Created by Shadown88 on 20/04/2017.
//  Copyright � 2017 Shadown88. All rights reserved.
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


extern Hero hero[5];
extern int dummyPower, spDummy, hpDummy;


void bossAttack() {
	int k;
	int attackValue = 0;
	int target;
	target = bossSkillSelection(spDummy, &attackValue);

	k = targetSelection(target);

	bool blockRoll, evadeRoll, deflectRoll, redirectRoll;

	bool critRoll = RNGroll(10);
	redirectRoll = RNGroll(25);
	if (redirectRoll) {
		printf("redirect successful\n");
		k = 4;
	}
	if (critRoll) {
		attackValue *= 1.5;
	}
	deflectRoll = RNGroll(hero[k].deflect); //following IFs statements to take account of defensive stats of Hero
	if (!deflectRoll) {
		evadeRoll = RNGroll(hero[k].evade);
		if (!evadeRoll) {
			blockRoll = RNGroll(hero[k].block);
			if (blockRoll) {
				printf("block successful\n");
				hero[k].hp -= 0.5 * attackValue;
				if (hero[k].hp <= 0) {
					hero[k].alive = false;
				}
				else {
					petSelection(k);
				}
			}
			else {
				hero[k].hp -= attackValue;
				if (hero[k].hp <= 0) {
					hero[k].alive = false;
				}
				else {
					petSelection(k);
				}
			} 
		} else { printf("evade successful\n"); }
	}
	else {
		printf("deflect successful\n");
		hpDummy -= attackValue;

	}
}
