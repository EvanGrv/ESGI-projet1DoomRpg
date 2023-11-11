#include "Player.h"
#include "dependencies.h"
#include "monsterGeneration.c"


player initiale =
        {
        .pointDeVie=100,
        .playerDamage=10,
        .playerTour=2,
        };

void playerIsAttack (int *pointDeVieNow, Pnj attack){
    *pointDeVieNow -= (rand() % (attack.attackMax - attack.attackMin + 1) + attack.attackMin)

}

void monsterAttack(int *pointDeVieNow, Pnj *monsters, int numMonsters) {
    for (int i=0; i < numMonsters; i++){
        if (monsters[i].hp >0){
            int damage = (rand() %);
            *pointDeVieNow -= damage;
        }
    }
}

void playerAttack(int weaponsDamage, Pnj *pnj, int nbTourPlayer, Pnj attack) {
    int termineLeTour = 0;
    srand(time(NULL);  // Initialisez le générateur de nombres aléatoires

    while (pnj->hp > 0) {
        for (int i = 0; i < nbTourPlayer; i++) {
            termineLeTour = 0;
            printf("Vous infligez %d dégats\n", weaponsDamage);
            pnj->hp -= (initiale.playerDamage + weaponsDamage);

            printf("Voulez-vous terminer le tour? (0 pour continuer, 1 pour terminer) : ");
            scanf("%d", &termineLeTour);

            while (termineLeTour != 0 && termineLeTour != 1) {
                printf("Veuillez saisir à nouveau la valeur (0 pour continuer, 1 pour terminer) : ");
                scanf("%d", &termineLeTour);
            }

            if (termineLeTour == 1) {
                printf("Votre tour est terminé.\n");
                i = nbTourPlayer;
            }
        }

        if (pnj->hp <= 0) {
            printf("Le monstre est vaincu!\n");
        }

        // Phase où les monstres attaquent
        if (pnj->hp > 0) {
            monsterAttack(&initiale.pointDeVie, pnj, Pnj -> monsterNumber);
            if (initiale.pointDeVie <= 0) {
                printf("Le joueur est mort. Fin de jeu.\n");
                return;
            }
        }
    }
}














