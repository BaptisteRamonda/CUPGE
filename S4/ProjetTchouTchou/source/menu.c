#include <stdio.h>
#include <stdlib.h>
#include "../headers/menu.h"
#include "../headers/id.h"
#include "../headers/reseau.h"
#include <string.h>

/*Affichage des différents messages*/
void messageBadChoice(){
    printf("\nChoix non reconnu, veuillez reessayer.\n");
}

void messageExit(){
    printf("\n-------------------- MERCI ET A BIENTOT CHEZ NOTRE COMPAGNIE! --------------------\n\n");
}

void messageWorking(){
    printf("\nNous travaillons actuellement sur ce programme, merci de bien vouloir revenir plus tard ^^\n\n");
}

/*Affichage des différents menus */
void afficheMenuPrincipal(){
    printf("\n############### BIENVENUE CHEZ NOTRE COMPAGNIE! ###############\n\n");
    printf("\n-------------------- MENU PRINCIPAL ---------------------\n");
    printf("|                                                       |\n");
    printf("|                   1- VOYAGEUR                         |\n");
    printf("|                   2- CONTROLEUR                       |\n");
    printf("|                   3- ADMINISTRATEUR                   |\n");
    printf("|                   4- QUITTER                          |\n");
    printf("|                                                       |\n");
    printf("---------------------------------------------------------\n");
    printf("\n               Quel est votre profil: ");
}

void afficheMenuVoyageur(){
    printf("\n-------------------- MENU VOYAGEUR ----------------------\n");
    printf("|                                                       |\n");
    printf("|               1- RECHERCHE D'UN TRAJET                |\n");
    printf("|               2- RESERVATION D'UN TRAJET              |\n");
    printf("|               3- RETOUR                               |\n");
    printf("|                                                       |\n");
    printf("---------------------------------------------------------\n");
    printf("\n               Quel est votre choix: ");
}

void afficheMenuControleur(){
    printf("\n-------------------- MENU CONTROLEUR --------------------\n");
    printf("|                                                       |\n");
    printf("|               1- RECHERCHE D'UN TRAJET                |\n");
    printf("|               2- PARAMETRES DU COMPTE                 |\n");
    printf("|               3- RETOUR                               |\n");
    printf("|                                                       |\n");
    printf("---------------------------------------------------------\n");
    printf("\n               Quel est votre choix: ");
}

void afficheMenuAdmin(){
    printf("\n------------------ MENU ADMINISTRATEUR ------------------\n");
    printf("|                                                       |\n");
    printf("|               1- GESTION DE TRAJET                    |\n");
    printf("|               2- EXPORTATION DES DONNEES              |\n");
    printf("|               3- PARAMETRES DU COMPTE                 |\n");
    printf("|               4- RETOUR                               |\n");
    printf("|                                                       |\n");
    printf("---------------------------------------------------------\n");
    printf("\n               Quel est votre choix: ");
}

void afficheGestionTrajet(){
    printf("\n----------------- MENU GESTION TRAJET ------------------\n");
    printf("|                                                       |\n");
    printf("|               1- AJOUTER GARE                         |\n");
    printf("|               2- SUPPRIMER GARE                       |\n");
    printf("|               3- AJOUTER TRAJET                       |\n"); 
    printf("|               4- SUPPRIMER TRAJET                     |\n");
    printf("|               5- AJOUTER TRAIN                        |\n");
    printf("|               6- SUPPRIMER TRAIN                      |\n");
    printf("|               7- MODIFIER TRAIN                       |\n");
    printf("|               8- RETOUR                               |\n");
    printf("|                                                       |\n");
    printf("---------------------------------------------------------\n");
    printf("\n               Quel est votre choix: ");
}

void afficheExportation(){
    printf("\n-------------------- MENU EXPORTATION ------------------\n");
    printf("|                                                       |\n");
    printf("|                  1- TRAINS                            |\n");
    printf("|                  2- VOYAGEURS                         |\n");
    printf("|                  3- RETOUR                            |\n");
    printf("|                                                       |\n");
    printf("---------------------------------------------------------\n");
    printf("\n      Choisissez le type de données a exporter: ");
}

void paramAdmin(){
    int choixParam;

    printf("\n--------------------- MENU PARAMETRES ------------------\n");
    printf("|                                                       |\n");
    printf("|               1- CONTROLEUR                           |\n");
    printf("|               2- ADMINISTRATEUR                       |\n");
    printf("|               3- QUITTER                              |\n");
    printf("|                                                       |\n");
    printf("---------------------------------------------------------\n");
    printf("\n  De qui souhaitez-vous modifier les identifiants: ");
    
    scanf("%d", &choixParam);
    switch (choixParam){
    case 1:
        system("clear");
        modificationIdControl(loginControl, passwordControl);
        break;
    case 2:
        system("clear");
        modificationIdAdmin(loginAdmin, passwordAdmin);
    default:
        break;
    }
}


void afficheMenuTrajet(){
   Reseau r = creerReseau();
    int i = 1;
    int nbVillesBillet = 1;
    int nvb;
    int depart;
    int arrivee;
    int** matrice = matAdj(r);
    int* billet;
    
    afficheAllVilles(r);
    printf("\nVeuillez entrer votre ville de départ : ");
    
    scanf("%d", &depart);
    system("clear");
    afficheAllVilles(r);
    printf("\nVeuillez entrer votre ville d'arrivée : ");
    scanf("%d", &arrivee);
    
    billet = dijkstra(matrice, depart, arrivee, 15);

    while (billet[i] != -1) {
        nbVillesBillet ++;
        i ++;
    }

    printf( "Voici votre trajet : \n");
    for (nvb = nbVillesBillet; nvb > 0; nvb --) {
        printf("%s", returnNomDeVille(billet[nvb]));
        if (nvb >= 1) 
            printf(" --- ");
    }

    printf("\n -- Trajet complet effectué en %d minutes -- \n\n\n", billet[0]);
    printf("\nSi vous souhaitez reserver ce trajet, allez sur la rubrique RESERVATION D'UN TRAJET dans le menu voyageur\n");
}

/*Fonctions des différents menus*/
void menuVoyageur(int choixVoya){
    switch (choixVoya) {
    case 1:
        system("clear");
        afficheMenuTrajet();
        break;
    case 2:
        system("clear");
        afficheMenuReservation();
        break;
    default:     
        break;
    }
}

void menuControleur(int choixControl){
    switch (choixControl) {
    case 1:
        system("clear");
        afficheMenuTrajet();
        break;
    case 2:
        system("clear");
        modificationIdControl(loginControl, passwordControl);
        break;
    default:
        break;
    }
}

void menuAdministrateur(int choixAdmin){
    switch (choixAdmin) {
    case 1:
        system("clear");
        afficheGestionTrajet();
        break;
    case 2:
        system("clear");
        afficheExportation();
        break;
    case 3:
        system("clear");
        paramAdmin();
    default:     
        break;
    }
}
