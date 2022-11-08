#include "utils.h"

int max(int a, int b)
{
    return (a>b)?a:b;
}

void BellmanFord(vertex*, edge*);

FILE* inPtr = NULL;
FILE* outPtr = NULL;

vertex *vertexlist = NULL;
edge *edgelist = NULL;

int E = 0;
int V = 0;
const int inf  = 55555555;

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("Not Enough Input Arguemnts\n");
        exit(1);
    }

    int v1, v2;
    int weight;

    int startVertex = atoi(argv[2]);
    inPtr = fopen(argv[1], "r");
    outPtr = fopen("sd.txt", "w");

    fscanf(inPtr, "%d %d", &V, &E);
    vertexlist = malloc(sizeof(vertex)*V);
    edgelist = malloc(sizeof(edge)*E);

    for(int i=0; i<V; ++i)
    {
        initVertex(&vertexlist[i], i);
    }
    vertexlist[0].dist = 0; // source as 0

    int i = 0;
    while(fscanf(inPtr, "%d %d %d", &v1, &v2, &weight) != EOF)
    {
        initEdge(&edgelist[i], v1, v2, weight);
        ++i;
    }

    //printEdge(edgelist, E);

    BellmanFord(vertexlist, edgelist);
}

void BellmanFord(vertex* vertexlist, edge* edgelist)
{
    edge* edg;
    vertex* curr_src, *curr_dest;
    int k = 0, kmax = 0;
    for(int j = 0; j < V-1; ++j)
    {
        k = 0;
        for(int i = 0; i < E; ++i)
        {
            edg = &edgelist[i];
            curr_src = &vertexlist[edg->src];
            curr_dest = &vertexlist[edg->dst];
            if( curr_src -> dist != inf )
            {
                k++;
                relaxVertex(curr_dest, curr_src->dist + edg->weight, curr_src);
            }       
        } 
        if(k > kmax)
            kmax = k; // not all edges will be updated in the first loop
    }

    
    int* Weights = (int*)malloc(sizeof(int)*V);

    for(int i=0; i<V; i++)
    {
        Weights[i] = vertexlist[i].dist;
    }


    for(int j = 0; j < kmax; ++j)
    {
        for(int i = 0; i < E; ++i)
        {
            edg = &edgelist[i];
            curr_src = &vertexlist[edg->src];
            curr_dest = &vertexlist[edg->dst];

            if ( curr_src -> dist != inf )
                relaxVertex(curr_dest, curr_src->dist + edg->weight, curr_src);
        } 
    }
    

    for(int i=0; i<V; i++)
    {
        if (Weights[i] == inf)
        {
            fprintf(outPtr, "%d %s\n", i, "+inf");
        }
        else if (Weights[i] == vertexlist[i].dist)
        {
            fprintf(outPtr, "%d %d\n", i, Weights[i]);
        }
        else
        {
            fprintf(outPtr, "%d %s\n", i, "-inf");
        }
    }
    /**/
}