#include "utils.h"

int max(int a, int b)
{
    return (a>b)?a:b;
}

void Dijkstra(vertex* , int );

FILE* inPtr = NULL;
vertex *graph = NULL;
int E = 0;
int V = 0;

int main(int argc, char* argv[])
{

    if (argc < 3)
    {
        printf("Not Enough Input Arguemnts\n");
        exit(1);
    }

    int v1, v2;
    int weight;

    int startVertex = atoi(argv[2]);
    inPtr = fopen(argv[1], "r");

    while(fscanf(inPtr, "%d %d %d", &v1, &v2, &weight) != EOF)
    {
        ++E;
        if (V < max(v1, v2))
        {
            V = max(v1, v2); 
        }
    }
    ++V; //for submission 

    graph = malloc(sizeof(vertex)*V);

    for(int i=0; i<V; ++i)
    {
        initVertex(&graph[i], i);
    }
    
    rewind(inPtr);
    while(fscanf(inPtr, "%d %d %d", &v1, &v2, &weight) != EOF)
    {
        linkVertex(&graph[v1], v2, weight); // the -1s have to be changed for submission
    }

    printGraph(graph, V);

    Dijkstra(graph, startVertex);

    printSP(graph, V);
}

void Dijkstra(vertex* graph, int start)
{
    heap pq;
    initHeap(&pq);

    vertex * curr = &graph[start];
    updateVertex(curr, 0, NULL);
    foundVertex(curr);

    for(listVertex* ptr = curr->link; ptr!=NULL; ptr = ptr->next)
    {
        insert(&pq, ptr);
        updateVertex(ptr->vertptr, curr->dist + ptr->edge, curr);
    }

    while(pq.size != 0)
    {
        curr = pop(&pq);
        foundVertex(curr);
        for(listVertex* ptr = curr->link; ptr!=NULL; ptr = ptr->next)
        {
            if (ptr->vertptr->found == 0)
            {
                insert(&pq, ptr);
                updateVertex(ptr->vertptr, curr->dist + ptr->edge, curr);
            }
        }
    }
}