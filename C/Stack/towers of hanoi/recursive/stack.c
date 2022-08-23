#include "stack.h"

void toh(int n, stack* from, stack* to, stack* aux)
{
    if(n==1)
            push(to, pop(from));
    else
    {
        toh(n-1, from, aux, to);
        push(to, pop(from));
        toh(n-1, aux, to, from); 
    }
}


void init(stack *s, int n, char Ch)
{
    s->tos = -1;
    s->data = (int *)malloc(n*sizeof(s));
    s->name = Ch;
}

int push(stack *s , int n)
{
    if(!isFull(s))
    {
        fprintf(fptr, "Push disk %d to Stack %c\n", n, s->name);
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
        fprintf(fptr, "Pop disk %d from Stack %c\n", peek(s), s->name);
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
    return 0;
}

int isEmpty(stack *s)
{
    return s->tos==-1;
}

int isFull(stack *s)
{
    return s->tos==SIZE-1;
}

void printS(stack *s)
{
    if(isEmpty(s))
    {
        printf("EMPTY STACK \n");
        return;
    }
    for(int i=0; i <= s->tos; ++i)
        printf("%d  ", s->data[i]);
    printf("\n");
    return;
}