//  BH Simulator
//
//  Created by Shadown88 on 01/06/2017.
//  Copyright © 2017 Shadown88. All rights reserved.
//
#include <stdbool.h>
#pragma once

// RNGroll serves as flag to say if roll is succesful (returns true) or not (returns false). Rolls on 1000 so that decimal aren't lost.
bool RNGroll(float a);

float turnRate(long b, long a);

// teamHeal runs the code to simulate team healing of hero[l]
void teamHeal(int l);

void hpPerc();

int healLogic();

int targetSelection(int method);

int bossSkillSelection(int sp, float *finalAttack);