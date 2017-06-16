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


extern Hero hero[5];
extern hpdummy;

// offpetproc runs the code to simulate damaging pets of hero [l]
void offPetProc(int l) {
	int attackmodifier = hero[l].power * 0.54;
	int attackvalue = rand() % attackmodifier + hero[l].power * 0.63;


	bool critroll = RNGroll(hero[l].critchance);
	bool petroll = RNGroll(20);

	if (critroll) {
		attackvalue *= hero[l].critdamage;
	}
	if (petroll) {
		hpdummy -= attackvalue;
	}

}

void superOffPetProc(int l) {
	int attackmodifier = hero[l].power * 0.37;
	int attackvalue = rand() % attackmodifier + hero[l].power * 1.668;


	bool critroll = RNGroll(hero[l].critchance);
	bool petroll = RNGroll(10);

	if (critroll) {
		attackvalue *= hero[l].critdamage;
	}
	if (petroll) {
		hpdummy -= attackvalue;
	}

}

void spreadHealPet(int l) {
	int i;
	int target = 0;
	int healmodifier = hero[l].power * 0.14;
	int healvalue = rand() % healmodifier + 0.66 * hero[l].power;

	bool critroll = RNGroll(hero[l].critchance);
	bool petroll = RNGroll(20);

	if (critroll) {
		healvalue *= hero[l].critdamage;
	}
	if (petroll) {
		for (i = 0; i < healvalue; i++) {
			target = healLogic();
			hero[target].hp++;
			if (hero[target].hp > hero[target].maxhp) {
				hero[target].hp = hero[target].maxhp;
			}
		}
	}
}

// strcmp to find what pet hero is using
void petSelection(int k) {
	int petcheck;
	petcheck = strcmp(hero[k].pet, "gemmi");
	if (petcheck == 0) {
		teamHeal(k);
	}
	petcheck = strcmp(hero[k].pet, "nelson");
	if (petcheck == 0) {
		offPetProc(k);
	}
	petcheck = strcmp(hero[k].pet, "boogie");
	if (petcheck == 0) {
		spreadHealPet(k);
	}
	petcheck = strcmp(hero[k].pet, "nemo");
	if (petcheck == 0) {
		superOffPetProc(k);
	}

}