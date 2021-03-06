#include <stdio.h>
#include <stdlib.h>
#include "../headers/reseau.h"
#include <assert.h>
#include "../headers/id.h"

#define NBVILLE 100
#define NBPLACES 10
#define inf 2147483647

enum eVille {PARIS = 0, TOURS, BORDEAUX, BIARRITZ, ORLEANS, LIMOGES, BRIVE, MONTAUBAN, TOULOUSE, LYON, MARSEILLE, AGEN, NARBONNE, MONTPELLIER, NICE};


struct s_ville {
    int nomVille;
};

struct s_trajet {
    Ville depart;
    Ville arrivee;
    int temps; /* en minutes*/
    int nbPlacesRestantes; /* chaque trajet est initialisé avec NBPLACES disponibles /jour*/
};

struct s_ligne {
    Ville * tEtapes;
    int nbEtapes;
    Trajet * tTrajetsPartiels;

};

struct s_reseau {
    Ligne * tLignes;/* lignes de trains, pondérées*/
    int nbLigne; 
    Ville * tVille;  /*toutes les villes accessibles grace au réseau*/
    int nbVille;
    int nbTrajet;
    Trajet * tTrajets; /*tous les trajets possibles, de proche en proche*/
    
};
/** 
 * prototype non nécéssaires a mettre dans le point h
 */
Trajet initialiseTrajet(Ville, Ville);


void afficheNomDeVille(Ville v) {
    switch (v->nomVille)
    {
    case PARIS:
        printf("PARIS");
        break;
    case TOULOUSE:
        printf("TOULOUSE");
        break;
    case BRIVE:
        printf("BRIVE");
        break;
    case MONTPELLIER:
        printf("MONTPELLIER");
        break;
    case AGEN:
        printf("AGEN");
        break;
    case MARSEILLE:
        printf("MARSEILLE");
        break;
    case TOURS:
        printf("TOURS");
        break; 
    case ORLEANS:
        printf("ORLEANS");
        break;
    case NARBONNE:
        printf("NARBONNE");
        break;
    case BORDEAUX:
        printf("BORDEAUX");
        break;
    case LYON:
        printf("LYON");
        break;
    case LIMOGES:
        printf("LIMOGES");
        break;
    case MONTAUBAN:
        printf("MONTAUBAN");
        break;
    case NICE:
        printf("NICE");
        break;
    case BIARRITZ:
        printf("BIARRITZ");
        break;   
    default:
        printf("%d", v->nomVille);
        break;
    }
}

void afficheNomDeVilleInt(int i) {
    switch (i)
    {
    case PARIS:
        printf("PARIS");
        break;
    case TOULOUSE:
        printf("TOULOUSE");
        break;
    case BRIVE:
        printf("BRIVE");
        break;
    case MONTPELLIER:
        printf("MONTPELLIER");
        break;
    case AGEN:
        printf("AGEN");
        break;
    case MARSEILLE:
        printf("MARSEILLE");
        break;
    case TOURS:
        printf("TOURS");
        break; 
    case ORLEANS:
        printf("ORLEANS");
        break;
    case NARBONNE:
        printf("NARBONNE");
        break;
    case BORDEAUX:
        printf("BORDEAUX");
        break;
    case LYON:
        printf("LYON");
        break;
    case LIMOGES:
        printf("LIMOGES");
        break;
    case MONTAUBAN:
        printf("MONTAUBAN");
        break;
    case NICE:
        printf("NICE");
        break;
    case BIARRITZ:
        printf("BIARRITZ");
        break;   
    default:
        printf("%d", i);
        break;
    }
}

char* returnNomDeVille(int i) {
    switch (i)
    {
    case PARIS:
        return("PARIS");
        break;
    case TOULOUSE:
        return("TOULOUSE");
        break;
    case BRIVE:
        return("BRIVE");
        break;
    case MONTPELLIER:
        return("MONTPELLIER");
        break;
    case AGEN:
        return("AGEN");
        break;
    case MARSEILLE:
        return("MARSEILLE");
        break;
    case TOURS:
        return("TOURS");
        break; 
    case ORLEANS:
        return("ORLEANS");
        break;
    case NARBONNE:
        return("NARBONNE");
        break;
    case BORDEAUX:
        return("BORDEAUX");
        break;
    case LYON:
        return("LYON");
        break;
    case LIMOGES:
        return("LIMOGES");
        break;
    case MONTAUBAN:
        return("MONTAUBAN");
        break;
    case NICE:
        return("NICE");
        break;
    case BIARRITZ:
        return("BIARRITZ");
        break;   
    default:
        return("erreur, veuillez entrer un nom de ville comprise dans le réseau");
        break;
    }
}



Trajet initialiseTrajet(Ville depart, Ville arrivee) {
    Trajet t = (Trajet)malloc(sizeof(struct s_trajet));
    t->depart = (Ville)malloc(sizeof(struct s_ville));
    t->arrivee = (Ville)malloc(sizeof(struct s_ville));
    t->depart->nomVille = depart->nomVille;
    t->arrivee->nomVille = arrivee->nomVille;
    /*t->nbPlacesRestantes = NBPLACES;*/
    return t;
}

Ligne ParisToulouse() {
    int i;
    Ligne l = (Ligne)malloc(sizeof(struct s_ligne)); 
    l->nbEtapes = 6;
    l->tEtapes = calloc(l->nbEtapes,sizeof(Ville)); 
    for (i = 0; i < l->nbEtapes; i ++) {
        l->tEtapes[i] = (Ville)malloc(sizeof(struct s_ville));
    }
    l->tEtapes[0]->nomVille = PARIS;
    l->tEtapes[1]->nomVille = ORLEANS;
    l->tEtapes[2]->nomVille = LIMOGES;
    l->tEtapes[3]->nomVille = BRIVE;
    l->tEtapes[4]->nomVille = MONTAUBAN;
    l->tEtapes[5]->nomVille = TOULOUSE;

    l->tTrajetsPartiels = (Trajet *)malloc(sizeof(struct s_trajet)*(l->nbEtapes - 1));    
    for (i = 0; i < (l->nbEtapes - 1); i ++){
        l->tTrajetsPartiels[i] = initialiseTrajet(l->tEtapes[i], l->tEtapes[i + 1]);
        l->tTrajetsPartiels[i]->nbPlacesRestantes = NBPLACES;
    }
    l->tTrajetsPartiels[0]->temps = 60;
    l->tTrajetsPartiels[1]->temps = 150;
    l->tTrajetsPartiels[2]->temps = 60;
    l->tTrajetsPartiels[3]->temps = 60;
    l->tTrajetsPartiels[4]->temps = 30;


    return l;
}

Ligne BordeauxNice() {
    int i;
    Ligne l = (Ligne)malloc(sizeof(struct s_ligne)); 
    l->nbEtapes = 8;
    l->tEtapes = calloc(l->nbEtapes,sizeof(Ville)); 
    for (i = 0; i < l->nbEtapes; i ++) {
        l->tEtapes[i] = (Ville)malloc(sizeof(struct s_ville));
    }
    l->tEtapes[0]->nomVille = BORDEAUX;
    l->tEtapes[1]->nomVille = AGEN;
    l->tEtapes[2]->nomVille = MONTAUBAN;
    l->tEtapes[3]->nomVille = TOULOUSE;
    l->tEtapes[4]->nomVille = NARBONNE;
    l->tEtapes[5]->nomVille = MONTPELLIER;
    l->tEtapes[6]->nomVille = MARSEILLE;
    l->tEtapes[7]->nomVille = NICE;

    l->tTrajetsPartiels = (Trajet *)malloc(sizeof(struct s_trajet)*((l->nbEtapes) - 1));    
    for (i = 0; i < (l->nbEtapes - 1); i ++){
        l->tTrajetsPartiels[i] = initialiseTrajet(l->tEtapes[i], l->tEtapes[i + 1]);
        l->tTrajetsPartiels[i]->nbPlacesRestantes = NBPLACES;
    }
    l->tTrajetsPartiels[0]->temps = 60;
    l->tTrajetsPartiels[1]->temps = 40;
    l->tTrajetsPartiels[2]->temps = 20;
    l->tTrajetsPartiels[3]->temps = 120;
    l->tTrajetsPartiels[4]->temps = 60;
    l->tTrajetsPartiels[5]->temps = 60;
    l->tTrajetsPartiels[6]->temps = 150;


    return l;
}

Ligne ParisMarseille() {
    int i;
    Ligne l = (Ligne)malloc(sizeof(struct s_ligne)); 
    l->nbEtapes = 3;
    l->tEtapes = calloc(l->nbEtapes,sizeof(Ville)); 
    for (i = 0; i < l->nbEtapes; i ++) {
        l->tEtapes[i] = (Ville)malloc(sizeof(struct s_ville));
    }
    l->tEtapes[0] = malloc(sizeof(struct s_ville));
    l->tEtapes[0]->nomVille = PARIS;
    l->tEtapes[1]->nomVille = LYON;
    l->tEtapes[2]->nomVille = MARSEILLE;

    l->tTrajetsPartiels = (Trajet *)malloc(sizeof(struct s_trajet)*((l->nbEtapes)-1));    
    for (i = 0; i < (l->nbEtapes - 1); i ++){
        l->tTrajetsPartiels[i] = initialiseTrajet(l->tEtapes[i], l->tEtapes[i + 1]);
        l->tTrajetsPartiels[i]->nbPlacesRestantes = NBPLACES;
    }
    l->tTrajetsPartiels[0]->temps = 90;
    l->tTrajetsPartiels[1]->temps = 90;


    return l;
}

Ligne ParisBiarritz() {
    int i;
    Ligne l = (Ligne)malloc(sizeof(struct s_ligne)); /* on alloue la mémoire pour creer la structure Ligne*/
    l->nbEtapes = 4; /* on initialise le nombre de villes que la ligne comprend*/
      /* on alloue la memoire pour chaque element de chaque tableau*/
    l->tEtapes = calloc(l->nbEtapes,sizeof(Ville)); 
    for (i = 0; i < l->nbEtapes; i ++) {
        l->tEtapes[i] = (Ville)malloc(sizeof(struct s_ville));
    }
    l->tEtapes[0] = malloc(sizeof(struct s_ville));
    l->tEtapes[0]->nomVille = PARIS;
    l->tEtapes[1]->nomVille = TOURS;
    l->tEtapes[2]->nomVille = BORDEAUX;
    l->tEtapes[3]->nomVille = BIARRITZ;
    /** 
     * deuxieme étape : on alloue l'espace pour le tableau de trajet cette fois ci avec la fonction initialise trajet et on complete avec le temps de chaque
     * trajet partiel (autrement dit on pondere les arcs)
     */ 
    l->tTrajetsPartiels = (Trajet *)malloc(sizeof(struct s_trajet)*((l->nbEtapes)-1));
    for (i = 0; i < l->nbEtapes - 1; i ++) {
        l->tTrajetsPartiels[i] = initialiseTrajet(l->tEtapes[i], l->tEtapes[i + 1]);
        l->tTrajetsPartiels[i]->nbPlacesRestantes = NBPLACES;
    }
    l->tTrajetsPartiels[0]->temps = 60;
    l->tTrajetsPartiels[1]->temps = 60;
    l->tTrajetsPartiels[2]->temps = 90;


    return l;
}

Reseau creerReseau() { /* la seule fonction qu'on utilisera vraiment*/
    int i;
    int l;
    int n;
    Reseau r = (Reseau)malloc(sizeof(struct s_reseau));
    r->nbLigne = 4;
    r->tLignes = calloc(r->nbLigne,sizeof(Ligne));
    for (i = 0; i < r->nbLigne; i ++) {
        r->tLignes[i] = (Ligne)malloc(sizeof(struct s_ligne));
    }
    r->tLignes[0] = ParisBiarritz();
    r->tLignes[1] = ParisMarseille();
    r->tLignes[2] = ParisToulouse();
    r->tLignes[3] = BordeauxNice();

    r->tVille = calloc(NBVILLE,sizeof(Ville));
    r->nbVille = 0;
    /**
     * on remplit le tableau de villes G du reseau X (X = (G, U))
     */ 
    for (l = 0; l < r->nbLigne; l ++) {
        for (i = 0; i < r->tLignes[l]->nbEtapes; i ++) {
            int dejaDedans = 0;                     /*on ne veut pas de doublons alors*/
            for (n = 0; n < r->nbVille; n ++) { /* on verifie que la ville qu'on ajoute au tableau n'est pas déja comprise dans le tableau*/
                if (r->tLignes[l]->tEtapes[i]->nomVille == r->tVille[n]->nomVille) {
                    dejaDedans = 1;
                }
            }
            if (dejaDedans == 0) {
                r->tVille[r->nbVille] = (Ville)malloc(sizeof(struct s_ville));
                r->tVille[r->nbVille]->nomVille = r->tLignes[l]->tEtapes[i]->nomVille;
                r->nbVille ++;
            }
        }
    }

    r->tTrajets = calloc(NBVILLE, sizeof(Trajet));
    r->nbTrajet = 0;
    for (l = 0; l < r->nbLigne; l ++) {
        for (i = 0; i < (r->tLignes[l]->nbEtapes - 1); i ++) {
            int dejaDedans = 0;                     /*on ne veut pas de doublons alors*/
            for (n = 0; n < r->nbTrajet; n ++) { /* on verifie que la ville qu'on ajoute au tableau n'est pas déja comprise dans le tableau*/
                if (r->tLignes[l]->tTrajetsPartiels[i]->depart == r->tTrajets[n]->depart && r->tLignes[l]->tTrajetsPartiels[i]->arrivee == r->tTrajets[n]->arrivee && r->tLignes[l]->tTrajetsPartiels[i]->temps == r->tTrajets[n]->temps) {
                    dejaDedans = 1;
                }
            }
            if (dejaDedans == 0) {
                r->tTrajets[r->nbTrajet] = initialiseTrajet(r->tLignes[l]->tEtapes[i], r->tLignes[l]->tEtapes[i + 1]);
                r->tTrajets[r->nbTrajet]->temps = r->tLignes[l]->tTrajetsPartiels[i]->temps;
                r->nbTrajet ++;
            }
        }
    }
    return r;
}

/* renvoie true si le réseau contient la ville en quesiton */

int contientVille(Reseau r, int ville) {
    int i;
    for (i = 0; i < r->nbVille; i ++) {
        if (r->tVille[i]->nomVille == ville)
            return 0;
    }
    return 1;

}

void afficheAllVilles(Reseau r) {
    int i;
    for (i = 0; i < r->nbVille; i ++) {
        printf("%d . " , i);
        afficheNomDeVilleInt(i);
        printf("\n");
    }
}

int **matAdj(Reseau r) {
    int i;
    int l;
    int t;
    int c;
    int **matrice;
    matrice=malloc(r->nbVille * sizeof(int*));
    for (i=0; i < r->nbVille; i++) {
        matrice[i]=malloc(r->nbVille * sizeof(int));
    }
        for (l = 0; l < r->nbVille; l ++) {
            for (c = 0; c < r->nbVille; c ++) {
                matrice[l][c] = inf;
                /**
                 * Parcours le tableau de trajets et renvoies le temps entre les deux villes si il existe
                 * 
                 */
                for (t = 0; t < r->nbTrajet; t ++) {
                    if (r->tTrajets[t]->depart->nomVille== l && r->tTrajets[t]->arrivee->nomVille== c) {
                        matrice[l][c] = r->tTrajets[t]->temps;
                    } else if (r->tTrajets[t]->depart->nomVille== c && r->tTrajets[t]->arrivee->nomVille== l ) {
                        matrice[l][c] = r->tTrajets[t]->temps;
                    }
                }
            }
        }
        return matrice;
}

bool parisToulouseContient(int v) {
    int i;
    Ligne l = ParisToulouse();
    for (i = 0; i < l->nbEtapes ; i++ ) {
        if (l->tEtapes[i]->nomVille == v)
        return true;
    }
    return false;

}
bool parisMarseilleContient(int v) {
    Ligne l = ParisMarseille();
    int i;
    for (i = 0; i < l->nbEtapes ; i++ ) {
        if (l->tEtapes[i]->nomVille == v)
        return true;
    }
    return false;

}
bool parisBiarritzContient(int v){
    Ligne l = ParisBiarritz();
    int i;
    for (i = 0; i < l->nbEtapes ; i++ ) {
        if (l->tEtapes[i]->nomVille == v)
        return true;
    }
    return false;
}

bool bordeauxNiceContient(int v) {
    Ligne l = BordeauxNice();
    int i;
    for (i = 0; i < l->nbEtapes ; i++ ) {
        if (l->tEtapes[i]->nomVille == v)
        return true;
    }
    return false;
}

int* dijkstra(int** adjacencePonderee, int debut, int arrivee, int nbVille){
    /*Fonctionnement:
    -On prend en entrée la ville de départ et la matrice d'adjacence qu'on a fait précédemment
    -On obtient en sortie un tableau qui donne la distance à chaque ville depuis la ville de départ (0 pour elle même)
     les indices des cases correspondent à l'enum du reseau.c 
    */
    /*On initialise toutes les variables dont on aura besoin*/
    int i;
    int* distance = malloc(sizeof(int)*15);
    int* visitee = malloc(sizeof(int)*15);
    int* precedente = malloc(sizeof(int)*15);
    int* tableau = calloc(100, sizeof(int));
    int distanceMin;
    int prochaineVille;
    int compteur = 1;
    int j = 1;
    distance[debut] = 0;
    visitee[debut] = 1;
    

    for(i = 0 ; i < nbVille ; i++){
        distance[i] = adjacencePonderee[debut][i];
        precedente[i]=debut;
        visitee[i]=0;
    }

    while(compteur < nbVille-1){
        distanceMin = inf;
        for (i = 0 ; i < nbVille ; i++){
            if (distance[i] < distanceMin && !visitee[i]){
                distanceMin = distance[i];
                prochaineVille = i;
            }
        }
        visitee[prochaineVille]=1;
        for (i = 0 ; i < nbVille ; i++){
            if (!visitee[i]){
                if ((distanceMin + adjacencePonderee[prochaineVille][i]) < distance[i]){
                    distance[i] = distanceMin + adjacencePonderee[prochaineVille][i];
                    precedente[i] = prochaineVille;
                }
            }
        }
        compteur ++;
    }
    
    
    
    tableau[0]=distance[arrivee];
    i = arrivee;
    
    while ( i!=debut ){
        tableau[j]=i;
        i=precedente[i];
        
        j++;
    }
    if (i==debut){
            tableau[j+1]=-1;
        }
    return tableau;
}

void afficheMenuReservation(){
    int i, j;
    int depart;
    int arrivee;
    char* nom = " ";
    Reseau r = creerReseau();
    int** matrice = matAdj(r);
    int* billet;

    afficheAllVilles(r);
    printf("\nVeuillez entrer votre ville de départ : \n");
    scanf("%d", &depart);
    system("clear");

    afficheAllVilles(r);
    printf("\nVeuillez entrer votre ville d'arrivée : ");
    scanf("%d", &arrivee);

    assert(arrivee!=depart);
    printf("\nVeuillez entrer votre nom: ");
    scanf("%s", nom);
    system("clear");

    billet = dijkstra(matrice, depart, arrivee, 15);
    for (i = 1; billet[i]!=-1;i++){
        for(j = 0; j<r->nbTrajet; j++){
            if (((r->tTrajets[j])->depart->nomVille == billet[i+1] && (r->tTrajets[j])->arrivee->nomVille == billet[i]) || ((r->tTrajets[j])->depart->nomVille == billet[i] && (r->tTrajets[j])->arrivee->nomVille == billet[i+1])){
                assert((r->tTrajets[j])->nbPlacesRestantes==0);
                    r->tTrajets[j]->nbPlacesRestantes--;
            }
        }
    }

    ecritBillets(billet, nom);

    printf("Votre billet a bien été enregistré, merci d'avoir voyagé avec notre compagnie.");
}
