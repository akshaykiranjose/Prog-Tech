#include "stack.h"
#include <stdio.h>

void init(stack *s)
{
    s->tos = -1;
}

void printS(stack *s)
{
    if(isEmpty(s))
    {
        printf("EMPTY STACK \n");
        return;
    }
    for(int i=s->tos; i >= 0; --i)
        printf("%d  ", s->data[i]);
    printf("\n");
    return;
}

int push(stack *s , int n)
{
    if(!isFull(s))
    {
        s->data[++s->tos] = n;
        return OK;
    }
    printf("STACK IS FULL\n");
    return ERROR;
}
int pop(stack *s)
{
    if(!isEmpty(s))
    {
        int elem = s->data[s->tos];
        s->data[s->tos--] = -1;
        return elem;
    }
    printf("STACK IS EMPTY\n");
    return ERROR;
}

int peek(stack *s)
{
    int val;
    if(!isEmpty(s))
    {
        val = s->data[s->tos];
        return val;
    }
    return SIZE;
}

int isEmpty(stack *s)
{
    return s->tos==-1;
}

int isFull(stack *s)
{
    return s->tos==SIZE-1;
}