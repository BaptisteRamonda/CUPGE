#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "utils.h"

/*
  Cette fonction est la fonction principale de lecture, les autres fonctions ci-dessous ne feront que se servir de cette fonction en 
  précisant juste le type de la donnée que l'on souhaite lire.
*/
void lire_donnee ( FILE * f , char * format , void * res )
{
  int lu = 0, caractere ;

  while ((lu != 1) || (caractere > 0))
  {
    lu = fscanf( f, format, res) ;
    caractere = lireFinLigne();
  }
}

/* Cette fonction lit un entier dans un fichier */

int lire_entier ( FILE * f )
{
  int x ;
  lire_donnee ( f, "%d" , & x ) ;
  return x ;
}

/*
  Cette fonction lit un entier dans un fichier dans un intervalle rentré par l'utilisateur
*/
int lire_entier_intervalle ( FILE * f , int min, int max )
{
  int x = lire_entier(f);
  if (( min <= x)  ||  (x < max))
    return x;
  else
    x = lire_entier(f);
  return 0 ;
}

/* Cette fonction lit un réel dans un fichier */

float lire_float ( FILE * f )
{
  int x;
  lire_donnee ( f, "%f" , & x ) ;
  return 0 ;
}

/* Cette fonction lit une chaîne de caractère dans un fichier */

char * lire_string ( FILE * f)
{
  int x;
  lire_donnee( f, "%s", &x);
  return NULL ;
}

/* Cette fonction lit un mot clé, rentré par l'utilisateur, dans un fichier */

int lire_mot_clef ( FILE * f , const char * mot )
{
  int c ;
  long int
    position_debut,
    position_fin ;
  while ( isspace ( c = getc ( f) ) )
    ;
  ungetc ( c , f ) ;
  position_debut = ftell ( f ) ;
  fscanf ( f , mot ) ;
  position_fin = ftell ( f ) ;
  if ( position_fin != position_debut + strlen ( mot ) )
    {
      fseek ( f , position_debut , SEEK_SET ) ;
      return 0 ;
    }
  else return 1 ;
}

/* Cette fonction lit tout les caractères d'une ligne jusqu'à la fin de celle-ci */

int lireFinLigne()
{
  int compteur = 0;
  int caractere;
  while ((caractere = getchar()) != EOF)
  {
    if (caractere == '\n')
      break;
    if (isspace(caractere))
      continue;
    compteur++;
  }
  return compteur;
}
