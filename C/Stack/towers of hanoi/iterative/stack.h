#ifndef _STACK_H
#define _STACK_H
#define SIZE 200
#define ERROR 1
#define OK 0

typedef struct {
int data[SIZE];
int tos;
} stack ;

void init(stack *) ;
void printS(stack *);

int push(stack * , int) ;
int pop(stack *) ;
int top(stack *, int *) ;
int isEmpty(stack *) ;
int isFull(stack *) ; 

#endif
