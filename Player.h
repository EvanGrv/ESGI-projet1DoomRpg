
#ifndef player

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "dependencies.h"



typedef struct {
    int pointDeVie;
    int playerDamage;
    int playerTour;
    int maxInventorySize;
}player;

typedef struct {
    char name[50];
    int damageBoost;
    int armorBoost;
} Item;

// Représentation temporaire de l'inventaire

typedef struct {
    Item weapon;
    Item armor;
    int gold;
} Inventory;


void playerIsAttack (int *pointDeVieNow, Pnj attack);
void monsterAttack(int *pointDeVieNow, Pnj *monsters, int numMonsters);
void playerAttack(int weaponsDamage, Pnj *pnj, int nbTourPlayer, Pnj attack);

#endif



