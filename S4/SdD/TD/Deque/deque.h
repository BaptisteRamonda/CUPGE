#ifndef __DEQUE_H__
#define __DEQUE_H__

/*
DEFINITIONS DES STRUCTURES
*/
//Définition opaque de la structure d'une liste
typedef struct s_list* List;
//Définition opaque de la structure d'un élément de la liste
typedef struct s_element* Element;

/*
PROTOTYPES DES FONCTIONS
*/
List push_front(List, int); //Ajoute un élément en tête de liste
List push_back(List, int); //Ajoute un élément en fin de liste
List pop_front(List); //Supprime un élément en tête de liste
List pop_back(List); //Supprime un élément en fin de liste
List insert_at(List, int, int); //Ajoute un élément à la ième position
List remove_at(List, int); //Supprime un élément à la ième position
int front(List); //Accès à la valeur de la tête de liste
int back(List); //Accès à la valeur de la fin de la liste
int ith(List, int); // Accès au ième élément

#endif
