#include "utils.h"

extern vertex *vertexlist;
extern edge *edgelist;

extern int E;
extern int V;
extern const int inf;

void initVertex(vertex* ptr, int idx)
{
    ptr->index = idx;
    ptr->dist = inf;
    ptr->pred = NULL;
}

void relaxVertex(vertex *ptr, int newdist, vertex* predecessor)
{
    if(newdist < ptr->dist)
    {
        ptr->dist = newdist;
        ptr->pred = predecessor;
    }
}

void initEdge(edge* edge, int src, int dest, int weight)
{
    edge->src = src;
    edge->dst = dest;
    edge->weight = weight;
}

void printEdge(edge* edge, int size)
{
    for(int i=0; i<size; ++i)
    {
        printf("%d %d %d\n", edge[i].src, edge[i].dst, edge[i].weight);
    }
}


void printSP(vertex* graph, int size)
{
    for(int i=0; i < size; ++i)
        printf("%2d: %2d\n", graph[i].index, graph[i].dist);
}