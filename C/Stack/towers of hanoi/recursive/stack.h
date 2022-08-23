#ifndef COMMANDS_H
#define COMMANDS_H

#include <stdio.h>
#include <stdlib.h>

#define ERROR 1
#define OK 0

int SIZE = 0;
FILE *fptr;

typedef struct 
{
    int* data; //the pointer that will point to the first element in the space allocated for this struct 'stack'
    int tos; //top of stack, same as top
    char name; //character name of the stack
}stack;

void init(stack *, int, char) ;
void printS(stack *);
void toh(int n, stack* , stack* , stack* );

int push(stack * , int) ;
int pop(stack *) ;
int peek(stack *) ;
int isEmpty(stack *) ;
int isFull(stack *) ; 

#endif