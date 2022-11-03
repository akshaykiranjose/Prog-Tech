#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

item* Item(int idx, int wei, int val)
{
    item* ptr = malloc(sizeof(item));
    ptr->index = idx;
    ptr->weight = wei;
    ptr->value = val;
    return ptr;
}

void init(heap* h)
{
    h->cap = 50;
    h->heap = malloc(sizeof(item*)*h->cap);
    for(int i=0; i < h->cap; ++i)
        h->heap[i] = NULL;
    h->size = 0;
}

void insert(heap* h, item* s)
{
    if(h->size == h->cap)
    {
        printf("heap full\n");
        return;
    }
    ++h->size;
    h->heap[h->size] = s;
    heapifyUp(h, h->size);
}

item* pop(heap* h)
{
    if (h->size == 0)
    {
        printf("Empty Heap\n");
        return NULL;
    }
    item* rem = h->heap[1];
    h->heap[1] = h->heap[h->size];
    h->heap[h->size] = NULL;
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
        if(h->heap[par]->weight > h->heap[index]->weight)
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
        return (h->heap[idx1]->weight < h->heap[idx2]->weight) ? idx1 : idx2;
}

void swap(heap *h, int idx1, int idx2)
{
    item* temp = h->heap[idx1];
    h->heap[idx1] = h->heap[idx2];
    h->heap[idx2] = temp;
}

void print(heap* h)
{
    for(int i=1; i<= h->size; ++i)
        printf("%4d %4d %4d\n", h->heap[i]->index,  h->heap[i]->weight,  h->heap[i]->value);
}