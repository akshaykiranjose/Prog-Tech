#include<stdio.h>
#include<conio.h>

int A[] = {-1, 2, 12, 42, 65, 80, 96, 188};
int B[] = {-3, -2, 1, 22, 39, 49, 179,192};
int C[16] = {};

void merge(int A[], int m, int lbA,  int B[], int n, int lbB, int C[], int lbC)
{
    int i = lbA, j = lbB, k=lbC;
    int ubA = lbA + m ;
    int ubB = lbB + n ; 
    while(i<= ubA && j<= ubB)
    {
        if(A[i] < B[j])
        {
            C[k++] = A[i++];
        }
        else
        {
            C[k++] = B[j++];
        }
    }
    while (i<ubA)
    {
        C[k++] = A[i++];
    }
    while (j<ubB)
    {
        C[k++] = B[j++];
    }

}

void main()
{
    merge(A, 4, 2, B, 3, 3, C, 0);// Array, length desired, start index and likewise
    for(int i=0; i < 7; i++)
        printf("%d ", C[i]);

}