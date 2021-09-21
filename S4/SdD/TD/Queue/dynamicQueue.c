#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"

/*
DEFINITION DES STRUCTURES
*/

//Structure d'un élément de la file
typedef struct s_element{
    int value;
    struct s_element* next;
}*Element;

//Structure explicite de la file
struct s_queue{
    Element head;
    Element tail;
    unsigned int size;
};

/*
DEFINITION DES FONCTIONS
*/

bool isEmpty(Queue q){
    return (q->size == 0);
}

Queue push(Queue q, int e){
    //On crée l'élément à ajouter
    Element newTail = (Element)malloc(sizeof(Element));
    newTail->value = e;
    newTail->next = NULL;
    //On rajoute l'élément à la file
    q->tail->next = newTail;
    q->tail = newTail;
    q->size ++;
    return q;
}

Queue pop(Queue q){
    Element oldHead = q->head; //On crée un pointeur pour retenir en mémoire l'ancienne tête
    q->head = q->head->next; //Le deuxième élément devient la nouvelle tête de la file
    free(oldHead); //On libère en mémoire l'ancienne tête
    q->size --;
    return q;
}

int top(Queue q){
    return q->head->value;
}
