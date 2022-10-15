#include <stdio.h>
#include <stdlib.h> 
#include "graph.h"
#include "queue.h"

void initqueue(queue *q)
{
    q->back = NULL;
    q->front = NULL;
}

int isEmpty(queue *q)
{
    return (q->back == NULL) ? 1 : 0 ;
}

int push(queue *q, node *NodeInMemory)
{
    listnode* newln = malloc(sizeof(listnode));
    newln->Node = NodeInMemory;
    newln->next = NULL;

    if(isEmpty(q))
        q->front = newln;
    else
        q->back->next = newln;

    q->back = newln;
    return 1;
}

int pop(queue *q)
{
    if(isEmpty(q))
    {
        printf("\tCannot Pop\n");
        return 0;
    }
    else
    {   
        listnode* del = q->front;
        q->front = del->next;
        if(q->front == NULL)
            q->back = NULL;
        free(del);
    }
    return 1;        
}

node* front(queue *q)
{
    return q->front->Node;
}

void PrintQueue(queue *q)
{
    listnode* thru = q->front;

    while(thru != NULL)
    {
        printf("%5d", thru->Node->key);
        thru = thru->next;
    }
    putchar('\n');
}