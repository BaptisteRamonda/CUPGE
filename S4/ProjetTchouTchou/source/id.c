#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/id.h"
#include "../headers/menu.h"
#include "../headers/reseau.h"

/*Vérification des logins et passwords*/
void verifLogin(char pro[], char user[]){
    while (strcmp(pro,user) != 0){
        system("clear");
        printf("Login : ");
        scanf("%s", user);
    }
}

void verifPassword(char pro[], char user[]){
    while (strcmp(pro,user) != 0){
        printf("Password : ");
        scanf("%s", user);   
        system("clear");
    }
}

int read(char* passlog, int longueur ,FILE* fichier){
    char *start = NULL;

    if (fgets(passlog, longueur, fichier) != NULL){
        start = strchr(passlog, '\n');
        /*On remplace le retour à la ligne*/
        if (start != NULL){
            *start = '\0'; 
        }
        else
        	fflush(stdin);
        return 1;
    }
    else {
    	fflush(stdin);
        return 0;
    }
}

void ecritBillets(int* b, char * nom) {
    FILE* fichierBillet = fopen("identifiers/billets.txt","a");
    int i = 1;

    if (fichierBillet != NULL) {
        fprintf(fichierBillet, "%s - ", nom);
        while (b[i] != -1) {
            fprintf(fichierBillet, "  %s", returnNomDeVille(b[i]));
            i ++;
        }
    }
    fprintf(fichierBillet, "\n");
}

void initialiseIdAdmin(char* log1, char* pw1){
    FILE* fichierLog = fopen("identifiers/adminLog.txt","r");
    FILE* fichierPw = fopen("identifiers/adminPw.txt","r");

    if (fichierLog != NULL){
        read(log1, 30, fichierLog);
        fclose(fichierLog);
    }

    if (fichierPw != NULL){
        read(pw1, 30, fichierPw);
        fclose(fichierPw);
    }
}

void initialiseIdControl(char* log1, char* pw1){
    FILE* fichierLog = fopen("identifiers/controlLog.txt","r");
    FILE* fichierPw = fopen("identifiers/controlPw.txt","r");

    if (fichierLog != NULL){
        read(log1, 30, fichierLog);
        fclose(fichierLog);
    }
    if (fichierPw != NULL){
        read(pw1, 30, fichierPw);
        fclose(fichierPw);
    }
}

void modificationIdControl(char* log1, char* pw1){
    FILE* fichierLog = fopen("identifiers/controlLog.txt","w+");
    FILE* fichierPw = fopen("identifiers/controlPw.txt","w+");

    if (fichierLog != NULL){
        system("clear");
        printf("Veuiller entrer votre nouveau login: ");
        scanf("%s", log1);
        fflush(stdin);
        fprintf(fichierLog, "%s", log1);
        fclose(fichierLog);
    }
    if (fichierPw != NULL){
        printf("Veuillez entrer votre nouveau mot de passe: ");
        scanf("%s",pw1);
        fprintf(fichierPw, "%s", pw1);
        fclose(fichierPw);
    }
    system("clear");
    printf("Changement d'identifiants effectue.\n\n");    
}

void modificationIdAdmin(char* log1, char* pw1){
    FILE* fichierLog = fopen("identifiers/adminLog.txt","w+");
    FILE* fichierPw = fopen("identifiers/adminPw.txt","w+");

    if (fichierLog != NULL){
        system("clear");
        printf("Veuiller entrer votre nouveau login: ");
        scanf("%s", log1);
        fflush(stdin);
        fprintf(fichierLog, "%s", log1);
        fclose(fichierLog);
    }
    if (fichierPw != NULL){
        printf("Veuillez entrer votre nouveau mot de passe: ");
        scanf("%s",pw1);
        fprintf(fichierPw, "%s", pw1);
        fclose(fichierPw);
    }
    system("clear");
    printf("Changement d'identifiants effectue.\n\n");    
}
