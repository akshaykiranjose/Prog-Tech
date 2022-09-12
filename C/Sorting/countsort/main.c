#include<stdio.h>
#include<stdlib.h>
#define nl putchar('\n')

void countSort(int*, int, int); // array and range and size

int main()
{
    int SIZE = 6;
    int RANGE = 12;

    int Arr[] = {4,6,1,2,0,9};

    for(int i = 0; i < SIZE; i++ )
        printf("%d ", Arr[i]);
    nl;

    countSort(Arr, RANGE, SIZE);

    for(int i = 0; i < SIZE; i++ )
        printf("%d ", Arr[i]);
    nl;
}

void countSort(int* A, int range, int size) // array and range
{
    int* rArr = (int*)malloc(sizeof(int)*(range+1));
    int* tempS = (int*)malloc(sizeof(int)*size);

    for (int i = 0; i<=range; i++)
        rArr[i] = 0;

    for (int i=0; i<size; i++)
        rArr[A[i]] ++;

    for (int i=1; i<=range; i++)
        rArr[i] += rArr[i-1];

    for (int i=0; i<=range; i++)
        printf("%d ", rArr[i]);
    nl;

    for (int i = size-1; i >= 0; --i)
        tempS[--rArr[A[i]]] = A[i];
    
    
    for (int i=0; i<size; i++)
        A[i] = tempS[i];    
}