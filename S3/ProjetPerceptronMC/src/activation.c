#include <math.h>
#include <assert.h>
#include <stdio.h>
#include <malloc.h>
#include "activation_struct.h"
#include "activation.h"
#include "utils.h"


/*
  static permet de rendre les fonctions invisibles en dehors du module
  (méthodes privées en Java)
 */
 
 /* Ici on prend comme exemple la fonction f(x)=x ainsi que sa dérivée. L'id de cette fonction sera 0.*/
 
static float fonction_d_activation_Identity ( float x )
{
  return x ;
}


static float derivee_fonction_d_activation_Identity ( float x , float fx )
{
  return 1 ;
}


/*
  Il faut renvoyer une structure avec l'adresse d'une fonction
  d'activation et de la dérivée correspondante. Ces fonctions sont
  définies sur le modèle de la fonction d'identité
 */
 
 /* Cette fonction ne marche pour l'instant qu'avec l fonction identité vue ci-dessus, mais en rajoutant le prototype  des fonctions 
    dans la structure et en inclunt l'identifiat correspondant à la fonction ci dessous on peut y inclure toute les fonctions qu'on
    souahite
  */
  
struct fonction_d_activation_s* choix_fonction_d_activation ( id_fonction_d_activation id )
{
  struct fonction_d_activation_s * res;
  res = malloc( sizeof(struct fonction_d_activation_s) );
  res->id = id;
  if (id==0)
  {
    res->applique = &fonction_d_activation_Identity;
    res->derivee = &derivee_fonction_d_activation_Identity;
  }
  if (id ==1)
  {
  }
  return res ;
}
   
/*
  Cette fonction sauvegarde une fonction dans un fichier pris en entrée.
 */
int sauve_fonction_d_activation ( FILE * f , struct fonction_d_activation_s * fun ) 
{
  if (f == NULL)
  {
    f = stdout;
  }
  fprintf(f,"%d", fun->id);
  return 0 ;
}

/*
  il faut lire l'id d'une fonction d'activation dans le fichier f, et mettre le
  choix d'une fonction d'activation correspond à cet id dans *fun.
 */
 
int lit_fonction_d_activation ( FILE * f , struct fonction_d_activation_s ** fun )
{
  int identite;
  if (f==NULL)
  {
    f = stdin;
  }
  fscanf(f, "%d", &identite);
  // identite = lire_entier(f); ???
  (*fun) = choix_fonction_d_activation(identite);
  return 0 ;
}
/*
  Il faut afficher les différents choix de fonction d'activation possibles, 
  lire le choix de l'utilisateur, et le renvoyer.
 */

id_fonction_d_activation demande_fonction_d_activation ()
{
  int id = 0;
  scanf("%d",&id);
  // Vérifier que l'id est entre 0 et fonction verification nombre +1
  return id ;
}
