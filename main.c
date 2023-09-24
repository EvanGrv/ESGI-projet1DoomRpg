// step 1 -> function to déterminate number of monstre
// step 2 -> function to generate stat of monster 
// step 3 -> function to generate skin of monster 
#include <stdio.h>
#include <stdlib.h>
#include "dependencies.h"

void main ()
{
    //generation of Pnj;
    Zone zone = 
    {
        .zoneType = SHADOWTOMBCATACOMBS,
        .position[0][0] = 1,
        .position[0][1] = 2,
        .maxLv = 10,
        .minLv = 5,
        .monsterType[0] = MONSTER,
        .monsterNumber = 2,
        .zoneMessage = "Vous arrivez dans une pièce lugurbe et 2 monstre vous attaque",
        .isZoneBoss = 0,
    };

    Pnj *monster = generatedMonster(zone);

}