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
#include "Logic.h"


void dummyFight() {
	long power = 500, stamina = 100, agility = 500, crit = 15, countermax = 100;
	double critdmg = 1.5, ds = 20, interval, counter = 0, prune = 1, arune = 1, critattack;
	float tr;
	bool petcheck;
	tr = turnRate(power, agility);
	power *= prune;
	stamina = 100;
	tr *= arune;
	critattack = power * critdmg;
	//4365
	//3525

	interval = countermax / tr;
	bool critroll, dsroll, petcrit;
	long i;
	long long cycle, hitdone = 0, normalhit = 0, crithit = 0;
	long long damagedone = 0;
	int attackmodifier, attackvalue, pethit = 0, petchance = 20;
	for (i = 0; i<1000000; i++) {
		for (cycle = 0; cycle <100; cycle++) {
			counter++;
			if (counter >= interval) {
				hitdone++;
				petcheck = RNGroll(petchance);
				if (petcheck) {
					attackmodifier = power * 0.54;
					attackvalue = rand() % attackmodifier + power * 0.63;
					petcrit = RNGroll(crit);
					if (petcrit) {
						attackvalue *= critdmg;
					}
					damagedone += attackvalue;
					pethit++;
				}
				dsroll = RNGroll(ds);

				if (dsroll) {
					critroll = RNGroll(crit);
					if (critroll) {
						damagedone += critattack;
						crithit++;
						petcheck = RNGroll(petchance);
						if (petcheck) {
							attackmodifier = power * 0.54;
							attackvalue = rand() % attackmodifier + power * 0.63;
							petcrit = RNGroll(crit);
							if (petcrit) {
								attackvalue *= critdmg;
							}
							damagedone += attackvalue;
							pethit++;
						}
					}
					else {
						damagedone += power;
						normalhit++;
						petcheck = RNGroll(petchance);
						if (petcheck) {
							attackmodifier = power * 0.54;
							attackvalue = rand() % attackmodifier + power * 0.63;
							petcrit = RNGroll(crit);
							if (petcrit) {
								attackvalue *= critdmg;
							}
							damagedone += attackvalue;
							pethit++;
						}
					}
					critroll = RNGroll(crit);
					if (critroll) {
						damagedone += critattack;
						crithit++;
						petcheck = RNGroll(petchance);
						if (petcheck) {
							attackmodifier = power * 0.54;
							attackvalue = rand() % attackmodifier + power * 0.63;
							petcrit = RNGroll(crit);
							if (petcrit) {
								attackvalue *= critdmg;
							}
							damagedone += attackvalue;
							pethit++;
						}
					}
					else {
						damagedone += power;
						normalhit++;
						petcheck = RNGroll(petchance);
						if (petcheck) {
							attackmodifier = power * 0.54;
							attackvalue = rand() % attackmodifier + power * 0.63;
							petcrit = RNGroll(crit);
							if (petcrit) {
								attackvalue *= critdmg;
							}
							damagedone += attackvalue;
							pethit++;
						}
					}
				}
				else {
					critroll = RNGroll(crit);
					if (critroll) {
						damagedone += critattack;
						crithit++;
						petcheck = RNGroll(petchance);
						if (petcheck) {
							attackmodifier = power * 0.54;
							attackvalue = rand() % attackmodifier + power * 0.63;
							petcrit = RNGroll(crit);
							if (petcrit) {
								attackvalue *= critdmg;
							}
							damagedone += attackvalue;
							pethit++;
						}
					}
					else {
						damagedone += power;
						normalhit++;
						petcheck = RNGroll(petchance);
						if (petcheck) {
							attackmodifier = power * 0.54;
							attackvalue = rand() % attackmodifier + power * 0.63;
							petcrit = RNGroll(crit);
							if (petcrit) {
								attackvalue *= critdmg;
							}
							damagedone += attackvalue;
							pethit++;
						}
					}
				}

				counter -= interval;

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
	printf("pet procs = %d\n", pethit);
	printf("turnrate = %f\n", tr);

}

void accsim() {
	int i;
	int sim = 1000000;
	int roll1 = 0, roll2 = 0, roll3 = 0;
	float deflectcount = 0, evadecount = 0, blockcount = 0;
	int deflect = 625, evade = 100, block = 25;
	float dmgreduction = 0;
	int proccount = 0;
	float dproc, eproc, bproc;
	for (i = 0; i<sim; i++) {
		roll1 = rand() % 10000 + 1;
		if (roll1 > deflect) {
			roll2 = rand() % 1000 + 1;
			if (roll2 > evade) {
				roll3 = rand() % 100 + 1;
				if (roll3 <= block) {
					blockcount++;
				}
			}
			else evadecount++;
		}
		else deflectcount++;
	}
	dproc = 100 * deflectcount / sim;
	eproc = 100 * (evadecount / sim);
	bproc = 100 * (blockcount / sim);

	printf("deflect: %f/%d = %f %% \nevade: %f/%d = %f %%\nblock: %f/%d = %f %%\n", deflectcount, sim, dproc, evadecount, sim, eproc, blockcount, sim, bproc);
	proccount = deflectcount + evadecount + blockcount;
	dmgreduction = 100 * (1 - ((sim - proccount + blockcount * 0.5) / sim));
	printf("Damage mitigation: %f%%\n", dmgreduction);
}
