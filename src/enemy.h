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
    int critchance;
    int DSchance;
    float critdamage;
    int block;
    int evade;
    int deflect;

} Enemy;

Enemy* newEnemy(int power, int stamina, int agility);

void enemyRestore(Enemy *enemy);
