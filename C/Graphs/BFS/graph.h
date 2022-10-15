#ifndef _GRAPH_H_
#define _GRAPH_H_

struct node
{
    int key;
    struct node* next;
};
typedef struct node node;

void LinkNode(node*, int, int);
void PrintGraph(node*, int);
void BFS(node*, int);

#endif