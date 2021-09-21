#ifndef __PILE_H__
#define __PILE_H__

//Définiton opaque des structures
typedef struct s_stack* Stack;
typedef struct s_step* Step;

//Crée un Step
Step step(int,int,int,int);

//Initialise une pile
Stack stack(void);

//Prototypes
int getX_ori(Step);
int getY_ori(Step);
int getX_fin(Step);
int getY_fin(Step);

Stack push(Stack, Step);
Stack pop(Stack);
int isEmpty(Stack);
Step top(Stack);

#endif
