#include<stdio.h>
#include<stdlib.h>
#define nl putchar('\n')

int SIZE = 0;
int* A = NULL;

int main(int argc, char* argv[])
{

    if (argc < 2)
    {
        printf("Wrong Input");
        nl;
        exit(1);
    }

    //int numDigits = atoi(argv[1]);
    int i = 0, n = 0;

    FILE *inPtr = fopen(argv[1], "r");

    while(fscanf(inPtr, "%d", &n ) != EOF )
        i++;

    SIZE = i;
    A = (int*) malloc(sizeof(int)*SIZE);
    i = 0;
    
    inPtr = fopen(argv[1], "r");

    while(fscanf(inPtr, "%d", &n ) != EOF )
        A[i++] = n;

    for(i = 0; i < SIZE; i++)
        printf("%d ", A[i]);
    nl;
    printf("%d", SIZE);
}