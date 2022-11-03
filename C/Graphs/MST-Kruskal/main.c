// kruskal's algorithm for finding a minimum spanning tree
#include"edge.h"
#include"disjointset.h"
#include<stdio.h>
#include<stdlib.h>
#define nl putchar('\n')
 
edge* edges;
edge* temp;

FILE *inPtr = NULL;
FILE *outPtr = NULL;
int NumEdges = 0;
int NumVertices = 0;

int max(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        perror("Not Enough Input Arguments");
        nl;
        exit(1);
    }

    inPtr = fopen(argv[1], "r");

    int n = 0;
    int vertex1, vertex2;
    long weight;

    while(fscanf(inPtr, "%d %d %ld", &vertex1, &vertex2, &weight) != EOF)
        ++n;

    NumEdges = n;
    n = 0;

    edges = malloc(sizeof(edge) * NumEdges);
    temp = malloc(sizeof(edge) * NumEdges);

    rewind(inPtr);
    while(fscanf(inPtr, "%d %d %ld", &vertex1, &vertex2, &weight) != EOF)
    {
        if(NumVertices < max(vertex1, vertex2))
            NumVertices = max(vertex1, vertex2);
        edges[n].v1 = vertex1;
        edges[n].v2 = vertex2;
        edges[n].weight = weight;
        ++n;
    }
    ++NumVertices; 
    
   sort(edges, NumEdges);
   
    ds set;
    init(&set, NumVertices);
   
    
   /*
   printf("Sorted Edges\n");
   for(int i=0; i<NumEdges; ++i)
        printf("%d %d %ld\n", edges[i].v1, edges[i].v2, edges[i].weight);
    
    
    for(int i=0; i<NumVertices; i++)
        printf("%d %d \n", i, set.leader[i]);
    printf("Sorted Edges\n");
    printf("number of vertices: %d\n", NumVertices);
    printf("number of edges: %d\n", NumEdges);
    */

   outPtr = fopen("mst.txt", "w");
   for(int i=0; i<NumEdges; ++i)
   {
        vertex1 = edges[i].v1;
        vertex2 = edges[i].v2;
        weight = edges[i].weight;
        //printf("%d", set.num_components);nl;
        if(find(&set, vertex1) !=  find(&set, vertex2))
        {
            if(set.leader[vertex1] == -1 && set.leader[vertex2] == -1)
            {
                fprintf(outPtr, "%d %d %ld\n", vertex1, vertex2, weight);
                dsunion(&set, vertex1, vertex2);
            }
                
            else if(set.leader[vertex1] == -1 && set.leader[vertex2] != -1)
            {
                fprintf(outPtr, "%d %d %ld\n", vertex1, vertex2, weight);
                dsunion(&set, vertex2, vertex1);
            }

            else if(set.leader[vertex2] == -1 && set.leader[vertex1] != -1)
            {
                fprintf(outPtr, "%d %d %ld\n", vertex1, vertex2, weight);
                dsunion(&set, vertex1, vertex2);
            }
            else    
            {
                fprintf(outPtr, "%d %d %ld\n", vertex1, vertex2, weight);
                dsunion(&set, vertex1, vertex2);
            }
        }
        /*
        for(int j=0; j < NumVertices; j++)
            printf("%d ", set.leader[j]);
        nl;
        */
        if(set.num_components == 1)
            break;
   }
   

}

