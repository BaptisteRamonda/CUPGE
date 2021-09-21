#include <stdio.h>
#include <stdlib.h>
#include "C:\Users\ramon\TPSdD\TP3&4\include\stack.h"

// Définition interne des structures
typedef struct s_element {
	Step value;
	struct s_element *next;
} *Element;

struct s_stack {
	Element top;
};

struct s_step {
	int x_ori;
	int y_ori;
	int x_fin;
	int y_fin;
};

// Constructeur Step
Step step(int x_ori,int y_ori,int x_fin,int y_fin){
	Step s = (Step) malloc(sizeof(struct s_step));
	s->x_ori = x_ori;
	s->y_ori = y_ori;
	s->x_fin = x_fin;
	s->y_fin = y_fin;
	return(s);
}

//Constructeurs Stack
Stack stack(void) {
	Stack s = (Stack) malloc(sizeof(struct s_stack));
	s->top = NULL;
	return(s);
}

Stack push(Stack s, Step e) {
	Element new = (Element) malloc (sizeof(struct s_element));
	new->value=e;
	new->next = s->top;
	s->top = new;
	return(s);
}

// Opérateurs Step
int getX_ori (Step s){return (s->x_ori);}

int getY_ori (Step s){return (s->y_ori);}

int getX_fin (Step s){return (s->x_fin);}

int getY_fin (Step s){return (s->y_fin);}

// Opérateurs Stack
Stack pop(Stack s){
	if (!isEmpty(s)) {
		Element e = s->top;
		s->top = e->next;
		free(e);
	}
	return(s);
}

int isEmpty(Stack s) {return(s->top == NULL);}

Step top(Stack s) {
	if (!isEmpty(s)) {
		return((s->top)->value);
	}
	else
		return(NULL);
}
