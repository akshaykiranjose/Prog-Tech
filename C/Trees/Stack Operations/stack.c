#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void initstack(stack* s)
{
    s->tos = NULL;
}

int isEmpty(stack* s)
{
    return (s->tos == NULL) ? 1 : 0;
}

int push(stack* s, node* n)
{
    stacknode* newsn = malloc(sizeof(stacknode));
    newsn->nodePtr = n;

    if (isEmpty(s))
    {
        s->tos = newsn;
        newsn->next = NULL;
    }
    else
    {
        newsn->next = s->tos;
        s->tos = newsn;
    }
    return 1;
}

int pop(stack* s)
{
    if (isEmpty(s))
    {
        perror("Empty Stack");
        exit(1);
    }
    else
    {
        s->tos = s->tos->next;
        return 1;
    }
}

node* top(stack* s)
{
    return s->tos->nodePtr;
}