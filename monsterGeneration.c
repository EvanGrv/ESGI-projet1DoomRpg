#include "dependencies.h"

#define ALPHALEVEL 1.05

Pnj *generatedMonster(Zone zone)
{
    Pnj *result = malloc(sizeof(Pnj) * zone.monsterNumber);
    srand(time(NULL));

    for(int i = 0; i < zone.monsterNumber; i++)
    {

        int calculatedLevel = zone.isZoneBoss == 0 
            ? zone.minLv + rand() % (zone.maxLv + 1 - zone.minLv)
            : (zone.minLv + rand() % (zone.maxLv + 1 - zone.minLv)) + 5;

        Pnj monster = 
        {
            .type = MONSTER,
            .level = calculatedLevel,
            .hp = (80 + rand() % (100 + 1 - 80)) * pow(ALPHALEVEL, calculatedLevel),
            .mana = 0,
            .attack = (10 + rand() % (20 + 1 - 10)) * pow(ALPHALEVEL, calculatedLevel),
            .speed = (2 + rand() % (10 + 1 - 2)) * pow(ALPHALEVEL, calculatedLevel),
            .armor = 0,
            .resistance = 0,
            .xp = (10 + rand() % 21) * pow(ALPHALEVEL, calculatedLevel),
            .loot = {0},
            .capacity = {0},
            .attackMax = 20,
            .attackMin = 10,
        };

        sprintf(monster.name, "goblin %d", i),
        
        *(result + i) = monster;
        fprintf
        (
            stderr, 
            "The monster %s have been created successfuly !\ntype : %d;\tlevel : %d\thp : %d\tmana : %d\tattack : %d\tspeed : %d\tarmor : %d\tresistance : %d\txp : %d\n"
            , monster.name, monster.type, monster.level, monster.hp, monster.mana, monster.attack, monster.speed, monster.armor, monster.resistance, monster.xp
        );
    }
}