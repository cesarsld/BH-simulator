//
//  BHSimulator.c
//  BH Simulator
//
//  Created by Cesar Salad Jaimes on 20/04/2017.
//  Copyright � 2017 Cesar Salad Jaimes. All rights reserved.
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
extern int dummypower, spdummy, hpdummy;


void bossattack() {
	int k;
	float attackvalue = 0;
	int target;
	target = BossSkillSelection(spdummy, &attackvalue);

	k = TargetSelection(target);

	bool blockroll, evaderoll, deflectroll, redirectroll;

	bool critroll = RNGroll(10);
	redirectroll = RNGroll(25);
	if (redirectroll) {
		k = 4;
	}
	if (critroll) {
		attackvalue *= 1.5;
	}
	deflectroll = RNGroll(hero[k].deflect); //following IFs statements to take account of defensive stats of Hero
	if (!deflectroll) {
		evaderoll = RNGroll(hero[k].evade);
		if (!evaderoll) {
			blockroll = RNGroll(hero[k].block);
			if (blockroll) {
				hero[k].hp -= 0.5 * attackvalue;
				if (hero[k].hp <= 0) {
					hero[k].alive = false;
				}
				else {
					petSelection(k);
				}
			}
			else {
				hero[k].hp -= attackvalue;
				if (hero[k].hp <= 0) {
					hero[k].alive = false;
				}
				else {
					petSelection(k);
				}
			}
		}
	}
	else {
		hpdummy -= attackvalue;

	}
}
