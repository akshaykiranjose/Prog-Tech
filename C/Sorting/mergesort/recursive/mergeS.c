#include "mergeS.h"

int *temp = NULL;
int SIZE=0;

void mergesort(int* A)
{
    mergeSort(A, 0, SIZE-1);
}

void mergeSort(int* A, int left, int right)
{
    if (left >= right)
        return;
    else
    {
        int mid = (right+left)/2;
        mergeSort(A, left, mid);
        mergeSort(A, mid+1, right);
        merge(A, left, right); //implicit half-way split
    }
}

void merge(int* A, int left, int right)
{

    int mid = (right+left)/2;
    int i = left, j = mid+1, k = left;
    while(k <= right)
    {
        if (j > right)
            temp[k++] = A[i++];
        else if (i > mid)
            temp[k++] = A[j++];
        else if (A[i] > A[j])
            temp[k++] = A[j++];
        else 
            temp[k++] = A[i++];
    }
    for(i=left; i<= right; i++)
        A[i] = temp[i];
}