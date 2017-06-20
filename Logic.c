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


extern Hero hero[5];
extern int dummyPower, spDummy;

bool RNGroll(float a) {
	bool outcome;
	float chance = a * 10;
	int roll = rand() % 1000 + 1;
	if (roll <= chance) {
		outcome = true;
	}
	else {
		outcome = false;
	}
	return outcome;
}

float turnRate(long b, long a) {
	float tr = 0;
	tr = ((a + b) / 2);
	tr = pow(tr, 2);
	tr = tr / (100 * b);
	return tr;
}

void teamHeal(int l) {
	int i;
	int healModifier = hero[l].power * 0.072;
	int healValue = rand() % healModifier + 0.324 * hero[l].power;

	bool critroll = RNGroll(hero[l].critChance);
	bool petRoll = RNGroll(20);

	if (critroll) {
		healValue *= hero[l].critDamage;
	}
	if (petRoll) {
		for (i = 0; i<5; i++) {
			if (hero[i].hp >0) {
				hero[i].hp += healValue;
				if (hero[i].hp >= hero[i].maxHP) {
					hero[i].hp = hero[i].maxHP;
				}
			}
		}
	}
}

void hpPerc() {
	int i;
	for (i = 0; i<5; i++) {
		hero[i].hpPerc = (float)hero[i].hp / hero[i].maxHP;
	}
}

int healLogic() {
	int i;
	int lowest = 0;
	hpPerc();
	for (i = 0; i<4; i++) {
		if (hero[i].hpPerc <= hero[i + 1].hpPerc) {
			if (hero[i].alive) {
				lowest = i;
			}
		}
		else {
			if (hero[i + 1].alive) {
				lowest = i + 1;
			}
		}
	}
	return lowest;
}

int targetSelection(int method) {
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

int bossSkillSelection(int sp, float *finalAttack) {
	float attackValue = 0;
	int skillRoll = 0;
	int attackModifier = 0;
	int targetMethod = 0;

	if (sp < 2) {
		//normal attack
		attackModifier = 0.2 * dummyPower;
		attackValue = rand() % attackModifier + 0.9 * dummyPower;
		targetMethod = 1;
	}
	else if (sp < 4) {
		// 1 sp skill AI
		skillRoll = rand() % 100;
		if (skillRoll < 20) {
			attackModifier = 0.2 * dummyPower;
			attackValue = rand() % attackModifier + 0.9 * dummyPower;
			targetMethod = 1;
		}
		else if (skillRoll >= 20 && skillRoll < 60) {
			float skillModifier = (rand() % 126 + 94);
			skillModifier /= 100;
			attackValue = dummyPower*skillModifier;
			spDummy -= 2;
			targetMethod = 1;
		}
		else if (skillRoll >= 60) {
			float skillModifier = (rand() % 132 + 99);
			skillModifier /= 100;
			attackValue = dummyPower*skillModifier;
			spDummy -= 2;
			targetMethod = 2;
		}
	}
	else if (sp < 6) {
		// 1 - 2 sp skill AI
		skillRoll = rand() % 100;
		if (skillRoll < 15) {
			attackModifier = 0.2 * dummyPower;
			attackValue = rand() % attackModifier + 0.9 * dummyPower;
			targetMethod = 1;
		}
		else if (skillRoll >= 15 && skillRoll < 55) {
			float skillModifier = (rand() % 126 + 94);
			skillModifier /= 100;
			attackValue = dummyPower*skillModifier;
			spDummy -= 2;
			targetMethod = 1;
		}
		else if (skillRoll >= 55 && skillRoll < 95) {
			float skillModifier = (rand() % 132 + 99);
			skillModifier /= 100;
			attackValue = dummyPower*skillModifier;
			spDummy -= 2;
			targetMethod = 2;
		}
		else if (skillRoll >= 95) {
			float skillModifier = (rand() % 136 + 102);
			skillModifier /= 100;
			attackValue = dummyPower*skillModifier;
			spDummy -= 4;
			targetMethod = 3;
		}
	}
	else if (sp < 8) {
		// 1 - 2 sp skill AI
		skillRoll = rand() % 100;
		if (skillRoll < 5) {
			attackModifier = 0.2 * dummyPower;
			attackValue = rand() % attackModifier + 0.9 * dummyPower;
			targetMethod = 1;
		}
		else if (skillRoll >= 5 && skillRoll < 50) {
			float skillModifier = (rand() % 126 + 94);
			skillModifier /= 100;
			attackValue = dummyPower*skillModifier;
			spDummy -= 2;
			targetMethod = 1;
		}
		else if (skillRoll >= 50 && skillRoll < 95) {
			float skillModifier = (rand() % 132 + 99);
			skillModifier /= 100;
			attackValue = dummyPower*skillModifier;
			spDummy -= 2;
			targetMethod = 2;
		}
		else if (skillRoll >= 95) {
			float skillModifier = (rand() % 136 + 102);
			skillModifier /= 100;
			attackValue = dummyPower * skillModifier;
			spDummy -= 4;
			targetMethod = 3;
		}
	}
	else if (sp == 8) {
		// 1 - 2 sp skill AI
		skillRoll = rand() % 100;
		if (skillRoll < 0) {
			attackModifier = 0.2 * dummyPower;
			attackValue = rand() % attackModifier + 0.9 * dummyPower;
			targetMethod = 1;
		}
		else if (skillRoll >= 0 && skillRoll < 45) {
			float skillModifier = (rand() % 126 + 94);
			skillModifier /= 100;
			attackValue = dummyPower*skillModifier;
			spDummy -= 2;
			targetMethod = 1;
		}
		else if (skillRoll >= 45 && skillRoll < 95) {
			float skillModifier = (rand() % 132 + 99);
			skillModifier /= 100;
			attackValue = dummyPower*skillModifier;
			spDummy -= 2;
			targetMethod = 2;
		}
		else if (skillRoll >= 95) {
			float skillModifier = (rand() % 136 + 102);
			skillModifier /= 100;
			attackValue = dummyPower*skillModifier;
			spDummy -= 4;
			targetMethod = 3;
		}
	}
	*finalAttack = attackValue;
	return targetMethod;
}
