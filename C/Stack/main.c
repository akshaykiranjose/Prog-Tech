#include <stdio.h>
#include <stdlib.h>

int stacksize = 0;
int* stack = NULL;
int top = -1;

void push();
void pop();
void printStack();
int IsStackFull();
int IsStackEmpty(); 

int main(int argc, char* argv[])
{
    int Op = 0;
    if(argc < 2)
    {
        printf("Enter Stack Size");
        exit(0);
    }
    stacksize = atoi(argv[1]);
    stack = (int*)malloc(stacksize*sizeof(int));
    if (stack == NULL)
    {
        perror("malloc(): ");
        exit(0);
    }

    while(1)
    {
        printf("Enter stack operation\n");
        printf("1: PUSH\n");
        printf("2: POP\n");
        printf("3: PRINT\n");
        printf("4: EXIT\n");

        scanf("%d", &Op);

        switch(Op)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                printStack();
                break;
            case 4:
                exit(0);
            default:   
                break;
        }
    }
}

int IsStackFull() 
{
    return (top==stacksize-1) ? 1 : 0;
}
int IsStackEmpty()
{
    return (top==-1) ? 1 : 0;
}

void push()
{
    int element;
    if(!IsStackFull())
    {
        printf("Enter element\n");
		scanf("%d", &element);
        stack[++top] = element;
    }
    else
        printf("stack overflow \n");
}

void pop()
{
    if(!IsStackEmpty())
    {
        printf("Popping: %d\n", stack[top]);
        stack[top--] = -1;
    }
    else
        printf("stack underflow \n");
}

void printStack()
{
    for (int i=top; i>=0; --i)
        printf("Stack[%d] = %d \n", i, stack[i]);
    if (top==-1)
        printf("Empty Stack \n");
    printf("Top = %d\n", top);
}