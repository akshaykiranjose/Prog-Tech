#include "stack.h"
#include<stdio.h>
#include<stdlib.h>
//gcc -Wall main.c hello_fn.c -o newhello

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("Enter Number of Disks\n");
        exit(0);
    }

    FILE *fptr;
    stack A,B,C;
    init(&A);
    init(&B);
    init(&C);
    int status = 0;

    fptr = fopen("toh.txt", "w");
    
    int n = atoi(argv[1]);

    for(int i=n; i>=1; i--)
        push(&A, i);
    
    while(!status)
    {
        if(peek(&A) < peek(&B) && !isEmpty(&A))
            {
            fprintf(fptr, "Pop disk %d from Stack A\n", peek(&A));
            fprintf(fptr, "Push disk %d to Stack B\n", peek(&A));
            push(&B, pop(&A));
            }

        else if (peek(&B) < peek(&A) && !isEmpty(&B))
            {
            fprintf(fptr, "Pop disk %d from Stack B\n", peek(&B));
            fprintf(fptr, "Push disk %d to Stack A\n", peek(&B));
            push(&A, pop(&B));
            }

        if(peek(&A) < peek(&C) && !isEmpty(&A) )
            {
            fprintf(fptr, "Pop disk %d from Stack A\n", peek(&A));
            fprintf(fptr, "Push disk %d to Stack C\n", peek(&A));
            push(&C, pop(&A));
            }

        else if(peek(&A) > peek(&C)  && !isEmpty(&C))
            {
            fprintf(fptr, "Pop disk %d from Stack C\n", peek(&C));
            fprintf(fptr, "Push disk %d to Stack A\n", peek(&C));
            push(&A, pop(&C));
            }
        
        if(peek(&B) < peek(&C) && !isEmpty(&B))
            {
            fprintf(fptr, "Pop disk %d from Stack B\n", peek(&B));
            fprintf(fptr, "Push disk %d to Stack C\n", peek(&B));
            push(&C, pop(&B));
            }

        else if(peek(&B) > peek(&C) && !isEmpty(&C))
            {
            fprintf(fptr, "Pop disk %d from Stack C\n", peek(&C));
            fprintf(fptr, "Push disk %d to Stack B\n", peek(&C));
            push(&B, pop(&C));
            }
        if(C.tos == n-1) status=1;
    }

    return 0;
}

