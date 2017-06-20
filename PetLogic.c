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


extern Hero hero[5];
extern int hpDummy;

// offpetproc runs the code to simulate damaging pets of hero [l]
void offPetProc(int l) {
	int attackModifier = hero[l].power * 0.54;
	int attackValue = rand() % attackModifier + hero[l].power * 0.63;


	bool critRoll = RNGroll(hero[l].critChance);
	bool petRoll = RNGroll(20);

	if (critRoll) {
		attackValue *= hero[l].critDamage;
	}
	if (petRoll) {
		hpDummy -= attackValue;
	}

}

void superOffPetProc(int l) {
	int attackModifier = hero[l].power * 0.37;
	int attackValue = rand() % attackModifier + hero[l].power * 1.668;


	bool critRoll = RNGroll(hero[l].critChance);
	bool petRoll = RNGroll(10);

	if (critRoll) {
		attackValue *= hero[l].critDamage;
	}
	if (petRoll) {
		hpDummy -= attackValue;
	}

}

void spreadHealPet(int l) {
	int i;
	int target = 0;
	int healModifier = hero[l].power * 0.14;
	int healValue = rand() % healModifier + 0.66 * hero[l].power;

	bool critRoll = RNGroll(hero[l].critChance);
	bool petRoll = RNGroll(20);

	if (critRoll) {
		healValue *= hero[l].critDamage;
	}
	if (petRoll) {
		for (i = 0; i < healValue; i++) {
			target = healLogic();
			hero[target].hp++;
			if (hero[target].hp > hero[target].maxHP) {
				hero[target].hp = hero[target].maxHP;
			}
		}
	}
}

// strcmp to find what pet hero is using
void petSelection(int k) {
	int petCheck;
	petCheck = strcmp(hero[k].pet, "gemmi");
	if (petCheck == 0) {
		teamHeal(k);
	}
	petCheck = strcmp(hero[k].pet, "nelson");
	if (petCheck == 0) {
		offPetProc(k);
	}
	petCheck = strcmp(hero[k].pet, "boogie");
	if (petCheck == 0) {
		spreadHealPet(k);
	}
	petCheck = strcmp(hero[k].pet, "nemo");
	if (petCheck == 0) {
		superOffPetProc(k);
	}

}
