// heap 
#ifndef _HEAP_H_
#define _HEAP_H_

struct heap
{
    int *heap;
    int size;
    int cap;
};
typedef struct heap heap;

void init(heap*);
void insert(heap*, int);
int pop(heap*);
void heapifyDown(heap*, int);
void heapifyUp(heap*, int);
void print(heap*);
void swap(heap *, int , int );
int minIndex(heap *, int , int );

#endif