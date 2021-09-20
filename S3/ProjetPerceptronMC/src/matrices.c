#include <malloc.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "utils.h"
#include "matrices.h"
#include "matrices_struct.h"

/*
  Cette fonction doit libérer la mémoire allouée lors de la création d'une matrice
 */
void
detruit_matrice ( struct matrice_s * m )
{
  int l;
  for (l = 0; l < m->nb_lignes; l++)
  {
    free(m->matrice[l]);      // pour chaque malloc dans la fonction creation_matrice j'utilse free pour debloquer l'espce correspondant au malloc
  }
  free(m->matrice);
  free(m);
}


/*
  Cette fonction crée une matrice 
 */
struct matrice_s * creation_matrice ( int nb_lignes , int nb_colonnes )
{
  int l, c;
  struct matrice_s * ptmatrice;                      // j'initialise mon pointeur que je vais envoye en fin de fonction
  ptmatrice = malloc(sizeof(struct matrice_s));      // j'utilise malloc pour le struct matrice_s
  (* ptmatrice).nb_lignes = nb_lignes;                //la fleche et (* ). sont equivalents, mais on favorisera la fleche  
  ptmatrice->nb_cols = nb_colonnes;
  ptmatrice->matrice = malloc(sizeof(float*)* nb_lignes);               // j'alloue l'espace pour mon tableau de pointeurs
  for ( l = 0; l < nb_lignes; l++)
  {
    ptmatrice->matrice[l] =  malloc(sizeof(float) * nb_colonnes);     // Pour chaque ligne j'alloue l'espace du tableau de float 
    for (c = 0; c < nb_colonnes; c++)
    {
      ptmatrice->matrice[l][c] = 0.0;              // j'initialise a 0 tous mes coefs
    }
  }
  return ptmatrice;          // je return mon pointeur 
}

/*
  Si *e == NULL , il faut créer une matrice 1 x n et la mettre dans
  *e.  Maintenant que *e contient une matrice 1 x n, il faut recopier
  les coefficients du tableau t dans cette matrice.  
 */
int
matrice_ligne ( struct matrice_s * * e , float * t , int n )
{
  int i ; 
  if( (*e) == NULL ) 
	{
	    (*e) = creation_matrice ( 1 , n ) ;
  }
  for ( i = 0 ; i < n ; i++ )
  {
    (*e)->matrice[0][i] = t[i] ;
  }
  return 0 ;
}



/*
  Cette fonction crée et initialise une matrice n x m avec des |float|
  dans [ -1 , 1 ].
*/
struct matrice_s * creation_matrice_aleatoire ( int nb_lignes , int nb_colonnes )
{
  int l, c;
  struct matrice_s * ptmatrice;
  ptmatrice = creation_matrice(nb_lignes,nb_colonnes);
  
  for (l = 0; l < nb_lignes; l++)
  {     
    for (c = 0; c < nb_colonnes; c++)           //on parcours la matrice
    {
      ptmatrice->matrice[l][c]= ( (float) (rand() % (2000000 - 0 + 1))/1000000)-1;        // on initialise avec des randoms 
    }
  }
  return ptmatrice;
}



/*
  Cette fonction demande à l'utilisateur les dimensions et les
  coefficients d'une matrice, et renvoie la matrice correspondante.
*/
struct matrice_s * creation_matrice_utilisateur ()
{
  int nb_lignes, nb_colonnes;
  int l, c;
  
  
  printf("Matrice de taille l x c\nl=");
  scanf("%d",&nb_lignes);
  printf("c=");
  scanf("%d",&nb_colonnes);
// on fait une collecte de données pour initialiser la matrice

  struct matrice_s * ptmatrice;
  ptmatrice = creation_matrice(nb_lignes,nb_colonnes);
// on crée la matrice
  for (l = 0; l < nb_lignes; l++)
  {     
    for (c = 0; c < nb_colonnes; c++)
    {
      scanf("%f",&ptmatrice->matrice[l][c]) ;
// on la rempli avec des scanf
    }
  }  
  return ptmatrice;
}

/*
  Cette fonction lit une matrice qui a été stockée dans un fichier.
*/
int lire_matrice_fichier ( FILE * f , struct matrice_s * * m )
{
  int l, c;
  int nb_lignes, nb_cols;
  float coef;
  fscanf(f,"%d",&nb_lignes); 
  fscanf(f,"%d",&nb_cols);                  // on va chercher le nb_lignes et nb_cols dans le fichier et on les stock dans les variables de la fonction
  (*m)=creation_matrice(nb_lignes,nb_cols);         // on créé la matrice avec les deux int lu auparavant avec creation_matrice
  
  for ( l = 0 ; l < nb_lignes ; l++)
  {
    for ( c = 0 ; c < nb_cols ; c++)
    {
      fscanf(f,"%f",&coef);         // on parcourt le fichier et on rempli la matrice
      (*m)->matrice[l][c] = coef;
    }
  }
  return 0 ;
}
/*
  Cette fonction sauve une matrice dans un fichier. Elle
  doit utiliser la même format que lit_matrice_fichier
*/
int sauve_matrice_fichier ( FILE * f , struct matrice_s * m )    // on fait la meme chose mais avec un fprintf pour remplir un fichier a partir d'une matrice
{
  int l, c;
  int nb_lignes = m->nb_lignes;
  int nb_cols = m->nb_cols;
  float coef;
  
  fprintf(f,"%d",nb_lignes);
  fprintf(f,"%d",nb_cols);
  for ( l = 0 ; l < nb_lignes ; l++)
  {
    for (c = 0; c < nb_cols ; c++ )
    {
      coef = m->matrice[l][c];
      fprintf(f,"%2.3f  ",coef);    
    }
  }
  return 0 ;
}
/*
  Cette fonction affiche une matrice.
*/
void affiche_matrice ( struct matrice_s * m )
{
  int l;
  int c;
  for (l = 0; l < (*m).nb_lignes; l++)
  {
    for(c = 0; c < m->nb_cols; c++)     // on parcourt la matrice pour afficher chaque coefficient 1 par 1
    {
      printf("%2.3f  ", m->matrice[l][c]);    // le %2.3 veut dire 2 chiffres avant la virgule et 3 apres, ca donne un format
    }
    printf("\n");
  }
}


/*
  Copie le contenu de la matrice m1 dans la matrice m2.
  Les 2 matrices existent et ont les mêmes dimensions.
*/
int copie_matrice(
		  struct matrice_s * m1,
		  struct matrice_s * m2 )// m1 et m2 deja allouees
{
  if (m1->nb_lignes != m2->nb_lignes || m1->nb_cols != m2->nb_cols)   //on met un message d'erreur si on a
                                                                      //des tailles de matrices différentes
  {
    printf("Attention matrices de tailles differentes!");
    return 0;     //et on arrete la fonction là !
  }
  int l,c;
  for (l = 0; l < m1->nb_lignes; l++)
  {
    for (c = 0; c < m1->nb_cols; c++)      // on parcourt la premiere matrice
    m2->matrice[l][c] = m1->matrice[l][c];    //on initialise la deuxieme matrice avec les coefs de m1
  }
  return 0;
}
