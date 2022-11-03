#ifndef _UTILS_H_
#define _UTILS_H_

#include <stdlib.h>
#include <stdio.h>

struct vertex
{
    int index;
    int dist;
    int found;
    struct vertex* pred;
    struct listVertex* link;
};
typedef struct vertex vertex;

void initVertex(vertex*, int);
void updateVertex(vertex *, int , vertex* );
void foundVertex(vertex* );

struct listVertex
{
    vertex *vertptr;
    int edge;
    struct listVertex* next;
};
typedef struct listVertex listVertex;

listVertex* CreateLink(int, int);
void linkVertex(vertex*, int, int);

struct heap
{
    listVertex **heap;
    int size;
    int cap;
};
typedef struct heap heap;

void initHeap(heap*);
void insert(heap*, listVertex*);
vertex* pop(heap*);
void heapifyDown(heap*, int);
void heapifyUp(heap*, int);
void swap(heap *, int , int );
int minIndex(heap *, int , int );

void printGraph(vertex*, int);
void printSP(vertex*, int);

#endif