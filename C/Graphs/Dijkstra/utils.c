#include "utils.h"

#define inf 2147483647 //maximum number in 32 bit 

extern vertex *graph;
extern int E;
extern int V;

void initVertex(vertex* ptr, int idx)
{
    ptr->index = idx;
    ptr->dist = inf;
    ptr->found = 0;
    ptr->pred = NULL;
    ptr->link = NULL;
}

void updateVertex(vertex *ptr, int newdist, vertex* predecessor)
{
    if(newdist < ptr->dist)
    {
        ptr->dist = newdist;
        ptr->pred = predecessor;
    }
    
}

void foundVertex(vertex* ptr)
{
    ptr->found = 1;
}s

listVertex* CreateLink(int dest, int edge)
{
    listVertex *ptr = malloc(sizeof(listVertex));
    ptr->vertptr = &graph[dest];
    ptr->edge = edge;
    ptr->next = NULL;
    return ptr;
}

void linkVertex(vertex* v, int dest, int edge)
{
    listVertex *thru = v->link;
    if (thru == NULL)
    {
        v->link = CreateLink(dest, edge);
    }
    else
    {
        while(thru->next != NULL)
            thru = thru -> next;
        thru->next = CreateLink(dest, edge);
    }
}

void initHeap(heap* h)
{
    h->cap = E;
    h->heap = malloc(sizeof(listVertex*)*h->cap);
    for(int i=0; i < h->cap; ++i)
        h->heap[i] = NULL;
    h->size = 0;
}

void insert(heap* h, listVertex* v)
{
    if(h->size == h->cap)
    {
        printf("heap full\n");
        return;
    }
    ++h->size;
    h->heap[h->size] = v;
    heapifyUp(h, h->size);
}

vertex* pop(heap* h)
{
    if (h->size == 0)
    {
        printf("Empty Heap\n");
        return NULL;
    }
    listVertex* rem = h->heap[1];
    h->heap[1] = h->heap[h->size];
    h->heap[h->size] = NULL;
    h->size--;
    heapifyDown(h, 1);
    return rem->vertptr;
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
        if(h->heap[par]->edge > h->heap[index]->edge)
        {
            swap(h, par, index);
            heapifyUp(h, par);
        }
    }
}

void swap(heap *h, int idx1, int idx2)
{
    listVertex* temp = h->heap[idx1];
    h->heap[idx1] = h->heap[idx2];
    h->heap[idx2] = temp;
}

int minIndex(heap *h, int idx1, int idx2)
{
    if (idx1 > h->size)
        return idx2;
    else if (idx2 > h->size)
        return idx1;
    else
        return (h->heap[idx1]->edge < h->heap[idx2]->edge) ? idx1 : idx2;
}

void printGraph(vertex* graph, int size)
{
    listVertex *ptr = NULL;
    for (int i=0; i<size; ++i)
    {
        ptr = graph[i].link;
        printf("%d:", graph[i].index);
        while(ptr != NULL)
        {
            printf("%5d", ptr->vertptr->index);
            ptr = ptr -> next;
        }
        printf("\n");
    }
}

void printSP(vertex* graph, int size)
{
    for(int i=0; i < size; ++i)
        printf("%2d: %2d\n", graph[i].index, graph[i].dist);
}