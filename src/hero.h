#pragma once

typedef struct {
    int power;
    int stamina;
    int agility;
    int hp;
    int maxhp;
    int sp;
    float tr;
    float interval;
    float counter;
    float critchance;
    float DSchance;
    float critdamage;
    int block;
    float evade;
    float deflect;
    float powerrune;
    float agirune;
    char pet [10];

} Hero;

Hero* newHero(int power, int stamina, int agility, int critchance,
              float critdamage, float DSchance, int block, float evade,
              float deflect, float powerrune, float agirune, int pet);

float turnRate(int b, int a);

void heroRestore(Hero *hero);
