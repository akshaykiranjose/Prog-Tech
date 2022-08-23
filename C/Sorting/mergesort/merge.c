#include<stdio.h>
#include<conio.h>
#define SIZE 6
#define LEN 2

int A[SIZE] = {4,2,3,1,7,6};
int B[SIZE] = {}; 

void merge(int [], int , int ,  int [], int , int, int[], int );

void main()
{
    //for(int i=0; i < SIZE/LEN; i++)
    //    merge(A, LEN/2, i*LEN/2, A, LEN/2, i*LEN/2 + 1, B, i*LEN/2); // Array, length desired, start index and likewise
    for(int i=0; i < SIZE; i++)
        printf("%d ", B[i]);
    printf("\n");

    merge(A, 1, 0, A, 1, 1, B, 0);
    merge(A, 1, 2, A, 1, 3, B, 2);
    merge(A, 1, 4, A, 1, 5, B, 2);
    merge(B, 2, 0, B, 2, 2, A, 0);
    merge(A, 4, 0, B, 2, 4, A, 0);

    for(int i=0; i < SIZE; i++)
        printf("%d ", A[i]);
}

void merge(int A[], int m, int lbA,  int B[], int n, int lbB, int C[], int lbC)

{
    int i = lbA, j = lbB, k=lbC;
    int ubA = lbA + m -1;
    int ubB = lbB + n -1; 
    while(i<= ubA && j<= ubB)
    {
        if(A[i] < B[j])
        {
            C[k] = A[i]; k++; i++;
        }
        else
        {
            C[k] = B[j]; k++; j++;
        }
    }
    while (i<=ubA)
    {
        C[k++] = A[i++];
    }
    while (j<=ubB)
    {
        C[k++] = B[j++];
    }

}