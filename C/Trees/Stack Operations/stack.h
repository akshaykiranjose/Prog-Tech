#ifndef _STACK_H_
#define _STACK_H_

#include "tree.h"

struct stacknode
{
    node* nodePtr;
    struct stacknode* next;
};
typedef struct stacknode stacknode;

struct stack 
{
    stacknode* tos;
};
typedef struct stack stack;

/**/

void initstack(stack*);
int isEmpty(stack*);
int push(stack*, node*);
int pop(stack*);
node* top(stack*);

#endif