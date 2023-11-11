#include "Player.h"
#include "dependencies.h"
#include "monsterGeneration.c"
#include "attackPlayer .c"
#include "saveClasseDependencies.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// CHANGER LES DONNEES INVENTORY EN ROUGE AVEC LA FONCTION DEFINIE POUR LES INVENTAIRES

// Représentation temporaire de l'objet
void initGame(player *player, Zone zone) {
    // Initialisez les données du joueur
    player->pointDeVie = 100;
    player->playerDamage = 10;
    player->maxInventorySize = 5;
    player->inventory.gold = 0;

    // Initialisez l'inventaire du joueur
    strcpy(player->inventory.weapon.name, "Épée en bois");
    player->inventory.weapon.damageBoost = 5;
    player->inventory.armor.armorBoost = 2;

    Pnj *monster = generatedMonster(zone);
}


    void saveGame(player *player, Pnj *monster, int numMonsters){
    FILE *file = fopen("savegame.txt", "w");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier de sauvegarde.\n");
        return;
    }
    fprintf(file, "%d %d %d %d\n", player->pointDeVie, player->playerDamage, player->inventory.gold, player->maxInventorySize);

    fprintf(file, "%s %d %d\n", player->inventory.weapon.name, player->inventory.weapon.damageBoost,
            player->inventory.armor.armorBoost);

    for (int i = 0; i < numMonsters; i++) {
        fprintf(file, "%d %d %d %d\n", monster[i].hp, monster[i].attackMin, monster[i].attackMax, monster[i].rewardGold);
    }

    fclose(file);
    printf("Partie sauvegardée avec succès!\n");
}

void playGame(Player *player, Pnj *monsters, int numMonsters) {
    int choice;

    while (player->hp > 0) {  // Boucle tant que le joueur est en vie
        printf("Menu de jeu :\n");
        printf("1. Attaquer\n");
        printf("2. Consulter l'inventaire\n");
        printf("3. Sauvegarder et quitter\n");
        printf("Choisissez une option : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:

                playerAttack(player->inventory.weapon.damageBoost, player, monsters, numMonsters, generatedMonster());
                // generatedMonster est ce qui permet de selectionner le monstre voulu si c'est possible ou alors
                // tu peux laisser generatedMonster  .
                break;
            case 2:
                // Consulter l'inventaire et METTRE LA VALEUR CORRESPONDAT
                viewInventory(player);
                break;
            case 3:
                // Sauvegarder et quitter
                saveGame(player, monsters, numMonsters);
                exit(0);
            default:
                printf("Option non valide. Veuillez réessayer.\n");
        }
    }

    printf("Le joueur est mort. Fin de jeu.\n");
}


void loadGame(player *player, Pnj *monster, int numMonsters) {
    FILE *file = fopen("savegame.txt", "r");  // Ouvrir un fichier en mode lecture
    if (file == NULL) {
        printf("Aucune sauvegarde trouvée.\n");
        return;
    }

    // Charger les données du joueur depuis le fichier
    fscanf(file, "%d %d %d %d", &player->pointDeVie, &player->playerDamage, &player->inventory.gold, &player->maxInventorySize);

    // Charger l'inventaire du joueur depuis le fichier
    fscanf(file, "%s %d %d", player->inventory.weapon.name, &player->inventory.weapon.damageBoost,
           &player->inventory.armor.armorBoost);

    // Charger les données des monstres depuis le fichier
    for (int i = 0; i < numMonsters; i++) {
        fscanf(file, "%d %d %d %d", &monster[i].hp, &monster[i].attackMin, &monster[i].attackMax, &monsters[i].rewardGold);
    }

    fclose(file);  // Fermer le fichier
    printf("Partie chargée avec succès!\n");
}

void gameMenu(player *player, Pnj *monsters, int numMonsters) {
    int choice;

    while (1) {
        printf("Menu principal :\n");
        printf("1. Nouvelle partie\n");
        printf("2. Charger partie\n");
        printf("3. Quitter\n");
        printf("Choisissez une option : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                initGame(player, monsters, numMonsters);
                playGame(player, monsters, numMonsters);
                break;
            case 2:
                loadGame(player, monsters, numMonsters);
                playGame(player, monsters, numMonsters);
                break;
            case 3:
                exit(0);
            default:
                printf("Option non valide. Veuillez réessayer.\n");
        }
    }
}





