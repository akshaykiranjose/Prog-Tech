#include <stdio.h>
#include<stdlib.h>

#define ERROR 1
#define OK 0

int SIZE = 0;
FILE *fptr;

typedef struct 
{
    int* data;
    int tos;
    char name;
}stack;

void init(stack *, int, char) ;
void printS(stack *);

int push(stack * , int) ;
int pop(stack *) ;
int peek(stack *) ;
int isEmpty(stack *) ;
int isFull(stack *) ; 

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

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("Enter Number of Disks\n");
        exit(0);
    }

    fptr = fopen("toh.txt", "w");

    stack A,B,C;
    SIZE = atoi(argv[1]);

    init(&A, SIZE, 'A');
    init(&B, SIZE, 'B');
    init(&C, SIZE, 'C');

    
    for(int i=SIZE; i>=1; i--)    push(&A, i);

    toh(SIZE, &A, &C, &B);

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