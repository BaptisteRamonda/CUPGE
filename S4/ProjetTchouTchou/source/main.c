#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/menu.h"
#include "../headers/id.h"
#include "../headers/reseau.h"

int main(){

    /*Déclaration des variables de choix*/
    int choixProfil;
    int choixVoya;
    int choixAdmin;
    int choixControl;

    /*Initialisation des mots de passe et login*/
    initialiseIdAdmin(loginAdmin, passwordAdmin);
    initialiseIdControl(loginControl, passwordControl);
   
    system("clear");
    menuPrincipal: /*Label menu principal*/
    afficheMenuPrincipal();
    scanf("%d", &choixProfil);
    system("clear");

    switch (choixProfil){
        /*CHOIX VOYAGEUR*/
        case 1:
            menuVoya: /*Label Menu Voyageur*/
            afficheMenuVoyageur();
            scanf("%d", &choixVoya);
            if (choixVoya == 4){
                system("clear");
                goto menuPrincipal;
            }
            else if (choixVoya >= 4){
                system("clear");
                goto menuVoya;
            }
            else
                menuVoyageur(choixVoya);
            break;
        /*CHOIX CONTROLEUR*/
        case 2:
            verifLogin(loginControl, loginUser);
            verifPassword(passwordControl, passwordUser);  

            menuControl: /*Label Menu Contrôleur*/
            afficheMenuControleur(); 
            scanf("%d", &choixControl);
            if (choixControl == 3){
                system("clear");
                goto menuPrincipal;
            } 
            else if (choixControl >= 3){
                system("clear");
                goto menuControl;
            }
            else
                menuControleur(choixControl);
            break;   
            
        /*CHOIX ADMINISTRATEUR*/
        case 3:
            verifLogin(loginAdmin,loginUser);
            verifPassword(passwordAdmin, passwordUser); 

            menuAdmin: /*Label Menu Administrateur*/
            afficheMenuAdmin();
            scanf("%d", &choixAdmin);
            if (choixAdmin == 4){
                system("clear");
                goto menuPrincipal;
            }
            else if (choixAdmin >= 4){
                system("clear");
                goto menuAdmin;
            }
            else
                menuAdministrateur(choixAdmin);
            break;
        
        /*QUITTER PROGRAMME*/
        case 4:
            messageExit();
            return 0;
        
        /*ERREUR STDIN*/
        default:
            system("clear");
            messageBadChoice();
            goto menuPrincipal;
            break;
    }
    system("clear");
    goto menuPrincipal;
    return 0;
}
