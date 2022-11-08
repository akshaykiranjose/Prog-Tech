#ifndef _UTILS_H_
#define _UTILS_H_

#include <stdlib.h>
#include <stdio.h>

struct vertex
{
    int index;
    int dist;
    struct vertex* pred;
};
typedef struct vertex vertex;

void initVertex(vertex*, int);
void relaxVertex(vertex *, int , vertex* );

struct edge
{
    int src;
    int dst;
    int weight;
};
typedef struct edge edge;

void initEdge(edge*, int, int, int);

void printSP(vertex*, int);
void printEdge(edge*, int);

#endif