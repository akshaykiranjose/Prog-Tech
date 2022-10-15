#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "graph.h"

struct listnode // need to point to the type and not create a copy
{
    node* Node;
    struct listnode* next;
};
typedef struct listnode listnode;

struct queue
{
    listnode* front;
    listnode* back;
};
typedef struct queue queue;

void initqueue(queue *);
int isEmpty(queue *);
int push(queue *, node*);
int pop(queue *);
node* front(queue *);
void PrintQueue(queue *);

#endif