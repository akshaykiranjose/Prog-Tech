#include <stdio.h>
#include <stdlib.h>
#define NL putchar('\n');

int *arr = NULL;

int partition(int*, int, int);
void swap(int*, int* );

int main(int argc, char* argv[])
{
    if (argc < 2 || argc != atoi(argv[1]) + 2)
    {
        perror("Enter Size & Array");
        NL
        exit(1);
    }
    int size = atoi(argv[1]);
    arr = (int *)malloc(size * sizeof(int));

    for(int i=0; i<size; ++i)
        arr[i] = atoi(argv[2+i]);

    for(int i=0; i<size; ++i)
        printf("%d ", arr[i]);
    
    NL

    int loc = partition(arr, 0, size-1);

    printf("loc: %d", loc);

    NL

    for(int i=0; i<size; ++i)
        printf("%d ", arr[i]);
}

int partition(int* A, int l, int r)
{
    int j=l;
    int pivot = A[l];
    for(int i = l+1; i<=r; i++)
    {
        if(A[i] <= pivot)
        {
            j++;
            swap(&A[j], &A[i]);
        }
    }
    swap(&A[j], &A[l]);
    return j;
}

void swap(int *x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}