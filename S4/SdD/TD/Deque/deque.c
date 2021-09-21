#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

/*
DEFINITION DES STRUCTURES
*/
//Structure explicite d'un élément de la liste
struct s_element{
    int item;
    struct s_element* next;
    struct s_element* previous;
};

//Structure explicite de la liste
struct s_list{
    Element head;
    Element tail;
    int size;
};

/*
DEFINITION DES FONCTIONS
*/

List push_front(List l, int e){
    //On crée un élément
    Element elem = (Element) malloc(sizeof(Element));
    //On remplit la structure
    elem->item = e;
    elem->next = l->head;
    elem->previous = NULL;
    //On modifie l'ancienne tête si elle existe
    if (l->head != NULL)
        l->head->previous = elem;
    else //Liste vide
        l->tail = e;
    //On met à jour la liste
    l->head = elem;
    l->size ++;
    return l;
}

List push_back(List l, int e){
    //On crée un élément
    Element elem = (Element) malloc(sizeof(Element));
    //On remplit la structure
    elem->item = e;
    elem->next = NULL;
    elem->previous = l->tail;
    //On modifie l'ancienne queue si elle existe
    if (l->tail != NULL)
        l->tail->next = elem;
    else //Liste vide
        l->head = e;
    //On met à jour la liste
    l->tail = elem;
    l->size ++;
    return l;
}

List insert_at(List l, int e, int i){
    
    //Cas particuliers
    if ((l->size == 0) || (i <= 0)){
        l = push_front(l,e);
    } else {
        if (i >= (l->size -1)){
            l = push_back(l, e);
        }
    }
    //On crée un élément
    Element elem = (Element) malloc(sizeof(Element));
    //On parcourt la liste jusqu'à la position i
    Element pt = l->head;
    int count;
    for (count=0; count<i-1; count++){
        pt = pt->next;
    }
    //On insère l'élément à la position i
    elem->previous = pt;
    elem->next = pt->next;
    pt->next = elem;
    pt->next->previous = elem;
    //On met à jour la liste
    elem->item = e;
    l->size ++;
    return 0;
}

List remove_at(List l, int i){
    
    //Si la liste est vide ERREUR
    if (l->size == 0)
        printf("WARNING, LIST IS EMPTY\n");
        return l;
    //Autres cas particuliers
    if(i >= (l->size -1))
        l = pop_back(l);
        return 0;
    if(i <= 0)
        l = pop_front(l);
        return 0;
    //On parcourt la liste jusqu'à la position i
    Element pt = l->head;
    int count;
    for (count=0; count<i-1; count++){
        pt = pt->next;
    }
    //On retire l'élément à la position i
    pt->previous->next = pt->next;
    pt->next->previous = pt->previous;
    //On met à jour la liste
    free(pt);
    l->size --;
    return 0;
}
