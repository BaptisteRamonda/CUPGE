#ifndef __MENU_H__
#define __MENU_H__

/*
PROTOTYPES DES FONCTIONS
*/

/*Affichage de menus*/
void afficheMenuPrincipal(); /*Affiche le menu principal*/
void afficheMenuVoyageur(); /*Affiche le menu voyageur*/
void afficheMenuControleur(); /*Affiche le menu contrôleur*/
void afficheMenuAdmin(); /*Affiche le menu administrateur*/
void afficheGestionTrajet(); /*Affiche le menu de gestion des trajets*/
void afficheExportation(); /*Affiche le menu pour l'exportation en JSON*/
void afficheParamAdmin(); /*Affiche le menu des paramètres administrateurs*/
void afficheMenuTrajet(); /*Affiche le menu de recherche d'un trajet*/


/*Menus*/
void menuVoyageur(int); /*Menu Voyageur*/
void menuControleur(int); /*Menu Controleur*/
void menuAdministrateur(int); /*Menu Administrateur*/

/*Messages*/ 
void messageBadChoice();
void messageExit();


#endif
