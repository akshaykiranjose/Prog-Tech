// utils 
#ifndef _UTILS_H_
#define _UTILS_H_

struct item
{
    int index;
    int weight;
    int value;
};

typedef struct item item;

item* Item(int, int, int);

struct heap
{
    item **heap;
    int size;
    int cap;
};
typedef struct heap heap;

void init(heap*);
void insert(heap*, item*);
item* pop(heap*);
void heapifyDown(heap*, int);
void heapifyUp(heap*, int);
void print(heap*);
void swap(heap *, int , int );
int minIndex(heap *, int , int );

#endif