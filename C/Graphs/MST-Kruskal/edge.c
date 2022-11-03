#include "edge.h"
#include <stdio.h>

extern edge* edges;
extern edge* temp;

void sort(edge* edges, int size)
{
    mergeSort(edges, 0, size-1);
}


void mergeSort(edge* A, int left, int right)
{
    if (left >= right)
        return;
    else
    {
        int mid = (right+left)/2;
        mergeSort(A, left, mid);
        mergeSort(A, mid+1, right);
        merge(A, left, right); 
    }
}

void merge(edge* A, int left, int right)
{

    int mid = (right+left)/2;
    int i = left, j = mid+1, k = left;
    while(k <= right)
    {
        if (j > right)
            temp[k++] = A[i++];
        else if (i > mid)
            temp[k++] = A[j++];
        else if (A[i].weight > A[j].weight)
            temp[k++] = A[j++];
        else 
            temp[k++] = A[i++];
    }
    for(i=left; i<= right; i++)
        A[i] = temp[i];
}