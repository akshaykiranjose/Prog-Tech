#include "heap.h"
#include <stdlib.h>
#include <stdio.h>

void init(heap* h)
{
    h->cap = 50;
    h->heap = malloc(sizeof(int)*h->cap);
    h->heap[0] = -1;
    h->size = 0;
}

void insert(heap* h, int n)
{
    if(h->size == h->cap)
    {
        printf("heap full\n");
        return;
    }
    ++h->size;
    h->heap[h->size] = n;
    heapifyUp(h, h->size);
}

int pop(heap* h)
{
    int rem = h->heap[1];
    h->heap[1] = h->heap[h->size];
    h->size--;
    heapifyDown(h, 1);
    return rem;
}

void heapifyDown(heap* h, int index)
{
    int leftcindex = index*2;
    int rightcindex = leftcindex + 1;
    
    if (leftcindex <= h->size)
    {
        int minindex = minIndex(h, leftcindex, rightcindex);
        swap(h, index, minindex);
        heapifyDown(h, minindex);
    }
}

void heapifyUp(heap* h, int index)
{
    int par = index/2;
    if ( par > 0 )
    {
        if(h->heap[par] > h->heap[index])
        {
            swap(h, par, index);
            heapifyUp(h, par);
        }
    }
}

int minIndex(heap *h, int idx1, int idx2)
{
    if (idx1 > h->size)
        return idx2;
    else if (idx2 > h->size)
        return idx1;
    else
        return (h->heap[idx1] < h->heap[idx2]) ? idx1 : idx2;
}

void swap(heap *h, int idx1, int idx2)
{
    int temp = h->heap[idx1];
    h->heap[idx1] = h->heap[idx2];
    h->heap[idx2] = temp;
}

void print(heap* h)
{
    for(int i=1; i<= h->size; ++i)
        printf("%d ", h->heap[i]);
    putchar('\n');
}