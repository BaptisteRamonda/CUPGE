#ifndef __ID_H__
#define __ID_H__

/*Déclaration des logins et mots de passe*/
char loginControl[50];
char passwordControl[50];
char loginAdmin[50];
char passwordAdmin[50];
char loginUser[50];
char passwordUser[50];

/*PROTOTYPES DES FONCTIONS*/

void verifLogin(char pro[], char user[]); /*Vérifie le login*/
void verifPassword(char pro[], char user[]); /*Vérifie le mot de passe*/
void afficheModifId(); /*Affiche le menu de modification des identifiants*/
int read(char* passlog, int longueur ,FILE* fichier); /*Lit une chaîne dans un fichier*/
void initialiseIdAdmin(char* log1, char* pw1); /*Initialise les identifiants administrateur*/
void initialiseIdControl(char* log1, char* pw1); /*Initialise les identifiants contrôleur*/
void modificationIdControl(char* log1, char* pw1); /*Modifie les identifiants contrôleur (login + password)*/
void modificationIdAdmin(char* log1, char* pw1); /*Modifie les identifiants administrateur (login + password)*/
void ecritBillets(int*, char*); /*Ecrit un billet*/

#endif
