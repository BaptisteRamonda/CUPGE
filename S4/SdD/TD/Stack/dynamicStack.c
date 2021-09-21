#include <stdio.h>
#include "stack.h"

//Déclaration de la pile qu'appelle la définiton opaque du .h
typedef struct s_element{
    int value;
    struct s_stack *next;
}*Element;

struct s_stack{
    Element top;
};

Stack stack(){
    Stack s;
    //allocation
    s = (Stack) malloc(sizeof(struct s_stack));
    //initialisation
    s->top = NULL;
    return s;
}

//bool isEmpty(stack* s){}

void push(Stack s, int e){
    Element new = (Element)malloc(sizeof(struct s_element));
    new->value = e;
    //Pointer vers ex-sommet de pile
    new->next = s->top;
    //maj sommet de pile
    s->top = new;
}

void pop(Stack s){
    assert(!isEmpty(s));
    Element e = s->top;
    //maj du top
    s->top = e->next;
    //liberer e
    free(e);
}

int top(Stack s){
    
}
