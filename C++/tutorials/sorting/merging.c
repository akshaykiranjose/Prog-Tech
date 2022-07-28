#include<stdio.h>
#include<conio.h>

int A[] = {-1, 2, 12, 42, 65, 80, 96, 188};
int B[] = {-3, 0, 1, 2, 3, 4, 179, 192};
int C[16]; 

void merge(int A[], int m, int B[], int n, int C[])
{
    int i = 0, j = 0, k=0;
    while(i<m && j<n)
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
    while (i<m)
    {
        C[k++] = A[i++];
    }
    while (j<n)
    {
        C[k++] = B[j++];
    }

}

void main()
{
    merge(A, 8, B, 8, C);
    for(int i=0; i<8+8; i++)
        printf("%d ", C[i]);

}