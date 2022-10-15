#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "graph.h"

extern node *graph;
extern FILE* outPtr; 

void PrintGraph(node* graph, int SIZE)
{
    node* thru;
    for(int i=0; i<SIZE; ++i)
    {
        thru = graph[i].next; //thru gets pointed to where graph[i].next points to
        printf("%5d:", i);
        while(thru != NULL)
        {
            printf("%5d", thru->key);
            thru = thru->next;
        }
        putchar('\n');
    }
}

void LinkNode(node* graph, int v1, int v2)
{
    node* newnode = malloc(sizeof(node));
    newnode->key = v2;
    newnode->next = NULL;

    if(graph[v1].next == NULL)
        graph[v1].next = newnode;
    else
    {
        newnode->next = graph[v1].next;
        graph[v1].next = newnode;
    }
}

/**/
void BFS(node* graph, int V)
{
    queue Q;
    initqueue(&Q);

    node* start = &graph[0];
    node* trav;
    node* thru;

    int* visited = malloc(sizeof(int) * V);
    int* dist = malloc(sizeof(int) * V);

    for(int i=0; i<V; ++i)
    {
        visited[i] = 0;
        dist[i] = 0;
    }

    push(&Q, start);
    visited[0] = 1;

    while(!isEmpty(&Q))
    {
        trav = front(&Q); // the pointed instance that serves as the key of the graph table has to be returned
        pop(&Q);

        if(trav != NULL)
        {
            for(thru = trav->next; thru != NULL; thru = thru->next)
            {
                if(visited[thru->key] == 0)
                {
                    visited[thru->key] = 1;
                    dist[thru->key] = 1 + dist[trav->key];
                    push(&Q, &graph[thru->key]);
                }
            }
        }
    }
    for(int i=1; i<V; ++i)
        if(visited[i] == 0)
            dist[i] = -1;

    for(int i=0; i<V; ++i)
        fprintf(outPtr, "%d\n", dist[i]);

}
