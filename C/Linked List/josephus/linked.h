#ifndef LINKED_H
#define LINKED_H

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define NL putchar('\n')

struct node
{
    int data;
    struct node* next;
};
typedef struct node node;

struct cll
{
    node *tail;
    int len;
};
typedef struct cll cll;

void initcll(cll *l);

int isEmpty(cll *l);
void printL(cll *l);
void printlen(cll *l);

int tail(cll *l);

void deleteFront(cll *l);
void deleteRear(cll *l);

void insertFront(cll *l, int );
void insertRear(cll *l, int );

int josephus(cll *l, int, int);

#endif 