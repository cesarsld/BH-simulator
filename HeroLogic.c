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

// unity skill code
void spreadHealingSkill(int k) {
	int i;
	int target = 0;
	int healingvalue = 0;
	int healingmodifier = 0.365 * hero[k].power;

	healingvalue = rand() % healingmodifier + 0.73 * hero[k].power;

	bool critroll = RNGroll(hero[k].critchance);
	if (critroll) {
		healingvalue *= hero[k].critdamage;
	}

	for (i = 0; i < healingvalue; i++) {
		target = healLogic();
		hero[target].hp++;
		if (hero[target].hp > hero[target].maxhp) {
			hero[target].hp = hero[target].maxhp;
		}
	}
}

void heroattack(int k, bool dual) {
	int skillSelection;
	float attackvalue = 0;
	int attackmodifier = 0.2 * hero[k].power;
	attackvalue = rand() % attackmodifier + 0.9 * hero[k].power;
	if (hero[k].sp >= 2) {
		skillSelection = rand() % 100;
		if (skillSelection < 20 && (hero[0].hpPerc < 0.85 || hero[4].hpPerc < 0.85)) {
			spreadHealingSkill(k);
			if (!dual) {
				hero[k].sp -= 2;
			}
		}
		else {
			float skillmodifier = (rand() % 50 + 110);
			skillmodifier /= 100;
			attackvalue = hero[k].power * skillmodifier;
			if (!dual) {
				hero[k].sp -= 2;
			}
		}
	}
	bool critroll = RNGroll(hero[k].critchance);
	if (critroll) {
		attackvalue *= hero[k].critdamage;
	}
	bool evaderoll = RNGroll(2.5);
	if (!evaderoll) {
		hpdummy -= attackvalue;
		petSelection(k);
	}
}
