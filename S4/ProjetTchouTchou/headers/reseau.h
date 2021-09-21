#ifndef __RESEAU_H__
#define __RESEAU_H__

typedef struct s_ville *Ville;
typedef struct s_trajet *Trajet;
typedef struct s_reseau *Reseau;
typedef struct s_ligne *Ligne;
/*Redéfinition du type booléen*/
typedef enum { false = 0, true = 1}bool;

Ligne ParisBiarritz();
Ligne ParisToulouse();
Ligne BordeauxNice();
Ligne ParisMarseille();

Trajet initialiseTrajet(Ville, Ville);
void afficheNomDeVille(Ville);
void afficheNomDeVilleInt(int);
char* returnNomDeVille(int);

void afficheAllVilles(Reseau);
/*renvoie 0 si la ville est dans le reseau, 0 sinon*/
int contientVille(Reseau, int);
int** matAdj(Reseau); 

bool parisToulouseContient(int v);
bool parisBiarritzContient(int v);
bool parisMarseilleContient(int v);
bool bordeauxNiceContient(int v);

Reseau creerReseau();
void afficheMenuReservation(); /*Affiche le menu de reservation d'un trajet*/
int* dijkstra(int** adjacencePonderee, int debut, int arrivee, int nbVille);

#endif
