#ifndef __QUEUE_H__
#define __QUEUE_H__ 

//Définiton implicite de la file
typedef struct s_queue* Queue;

//Opérateurs constructeurs
Queue queue();
Queue push(Queue, int);
//Opérateurs
Queue pop(Queue);
int top(Queue);
bool isEmpty(Queue);

/**
 * Propriétés de la file :
 * - isEmpty(queue) = true
 * - isEmpty(push(queue, e)) = false
 * - isEmpty(pop(push(queue, e))) = true
 */

//Définition du type booléen
typedef enum { false = 0, true = 1}bool;

#endif
