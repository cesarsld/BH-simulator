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

// unity skill code
void spreadHealingSkill(int k) {
	int i;
	int target = 0;
	int healingValue = 0;
	int healingModifier = 0.365 * hero[k].power;

	healingValue = rand() % healingModifier + 0.73 * hero[k].power;

	bool critRoll = RNGroll(hero[k].critChance);
	if (critRoll) {
		healingValue *= hero[k].critDamage;
	}

	for (i = 0; i < healingValue; i++) {
		target = healLogic();
		hero[target].hp++;
		if (hero[target].hp > hero[target].maxHP) {
			hero[target].hp = hero[target].maxHP;
		}
	}
}

void heroAttack(int k, bool dual) {
	int skillSelection;
	int attackValue = 0;
	bool hasHealed = false;
	int attackModifier = 0.2 * hero[k].power;
	attackValue = rand() % attackModifier + 0.9 * hero[k].power;
	if (hero[k].sp >= 2) {
		skillSelection = rand() % 100;
		if (skillSelection < 20 && (hero[0].hpPerc < 0.85 || hero[4].hpPerc < 0.85)) {
			spreadHealingSkill(k);
			hasHealed = true;
			if (!dual) {
				hero[k].sp -= 2;
			}
		}
		else {
			float skillModifier = (rand() % 50 + 110);
			skillModifier /= 100;
			attackValue = hero[k].power * skillModifier;
			if (!dual) {
				hero[k].sp -= 2;
			}
		}
	}
	bool critRoll = RNGroll(hero[k].critChance);
	if (critRoll) {
		attackValue *= hero[k].critDamage;
	}
	bool evadeRoll = RNGroll(2.5);
	if (!evadeRoll && !hasHealed) {
		printf("boss = %d\n", hpDummy);
		hpDummy -= attackValue;
		petSelection(k);
	}
}
