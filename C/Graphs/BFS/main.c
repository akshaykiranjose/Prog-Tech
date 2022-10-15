#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "queue.h"

#define nl putchar('\n')

FILE* inPtr = NULL;
FILE* outPtr = NULL;

int main(int argc, char* argv[])
{

    if (argc < 2)
    {
        perror("Not Enough Input Arguments\n");
        exit(1);
    }
    queue Q;
    initqueue(&Q);

    inPtr = fopen(argv[1], "r");
    outPtr = fopen("sd.txt", "w");

    int V, E;
    int v1, v2;

    fscanf(inPtr, "%d %d", &V, &E);

    node *graph = malloc(sizeof(node) * V);

    for(int i=0; i<V; ++i)
    {
        graph[i].key = i;
        graph[i].next = NULL;
    }
    
    while(fscanf(inPtr, "%d %d", &v1, &v2) != EOF)
    {
        LinkNode(graph, v1, v2);
        LinkNode(graph, v2, v1);
    }
    
    //PrintGraph(graph, V); 

    BFS(graph, V);
    return 0;
}