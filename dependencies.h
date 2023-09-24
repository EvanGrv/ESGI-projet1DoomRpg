#ifndef DEPENDENCIES
#define DEPENDENCIES

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef enum
{
    MONSTER,
    BOSS,
    FRIEND,
    NEUTRAL,
}MonsterType;

typedef enum
{
    SHADOWTOMBCATACOMBS, 
    CRYSTALCAVERNS,
    TWILIGHTMINES,
    ENCHANTEDFOREST,
    VOIDABYSS, 
}ZoneType;

typedef struct
{
    MonsterType type;
    char name[50];
    int level;
    int hp;
    int ressurect;
    int mana;
    int attack;
    int speed;
    int armor;
    int resistance;
    int xp;
    char loot[10];
    char capacity[10];
}Pnj;

typedef struct
{
    ZoneType zoneType;
    int position[1][2];
    int maxLv;
    int minLv;
    char monsterType[5];
    int monsterNumber;
    char zoneMessage[150];
    int isZoneBoss;
}Zone;

Pnj *generatedMonster(Zone zone);


#endif
