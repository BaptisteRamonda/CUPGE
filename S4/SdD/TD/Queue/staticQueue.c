#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"
#define QUEUE_MAX_SIZE 64

// Déclaration explicite de la file
typedef struct s_queue {
    int head; //Indice début de file
    int tail; //Indice fin de file
    int queue[QUEUE_MAX_SIZE]; 
    unsigned int size; //Nombre d'éléments dans ma file
};

// Implémentation des méthodes de la file
Queue queue(){
    Queue q = (Queue) malloc(sizeof(struct s_queue));
    q->head = 0;
    q->tail = 0;
    q->size = 0;
    return (q);
}

Queue push(Queue q, int e){
    assert(q->size < QUEUE_MAX_SIZE); //Vérification pile non pleine
    q->tail++; //L'indice du dernier élément de la file recule de 1
    q->queue[q->tail] = e; //Le dernier indice du tableau prend la valeur de e
    q->size++;
    q->tail = q->tail%QUEUE_MAX_SIZE;
    return (q);
}

Queue pop(Queue q){
    assert(q->size > 0); //Vérification pile non vide
    q->head ++; //L'indice du premier élément de la file recule de 1
    q->size --;
    q->head = (q->head+1)%QUEUE_MAX_SIZE;
    return (q);
}

int top(Queue q){
    assert(q->size > 0);
    return (q->queue[q->head]);
}

bool isEmpty(Queue q){
    return (q->size == 0);
}
