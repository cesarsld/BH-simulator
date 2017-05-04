#include <stdbool.h>
#include "hero.h"
#include "enemy.h"
#pragma once

bool RNGroll(float a);
void offpetproc(Hero* hero, Enemy* boss);
void defpetproc(Hero* hero, Hero **party);
void heroattack(Hero* hero, Hero **party, Enemy* boss);
void bossattack(Hero* hero, Hero **party, Enemy* boss);
