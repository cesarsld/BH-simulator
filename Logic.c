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


extern Hero hero[5];
extern dummypower, spdummy;

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
	int healmodifier = hero[l].power * 0.072;
	int healvalue = rand() % healmodifier + 0.324 * hero[l].power;

	bool critroll = RNGroll(hero[l].critchance);
	bool petroll = RNGroll(20);

	if (critroll) {
		healvalue *= hero[l].critdamage;
	}
	if (petroll) {
		for (i = 0; i<5; i++) {
			if (hero[i].hp >0) {
				hero[i].hp += healvalue;
				if (hero[i].hp >= hero[i].maxhp) {
					hero[i].hp = hero[i].maxhp;
				}
			}
		}
	}
}

void hpPerc() {
	int i;
	for (i = 0; i<5; i++) {
		hero[i].hpPerc = (float)hero[i].hp / hero[i].maxhp;
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

int TargetSelection(int method) {
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

int BossSkillSelection(int sp, float *finalAttack) {
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
	else if (sp < 4) {
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
			attackvalue = dummypower * skillmodifier;
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
		else if (skillRoll >= 95) {
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