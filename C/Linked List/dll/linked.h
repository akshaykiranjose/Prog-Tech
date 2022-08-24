#ifndef LINKED_H
#define LINKED_H

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define NL putchar('\n')

struct node
{
    struct node* prev;
    int data;
    struct node* next;
};

int isEmpty();
int returnTail();
void printL();
void findMid();
void try();

void deleteFront();
void deleteRear();
void deletePos(int );
void insertFront(int );
void insertRear(int );
void insertPos(int, int);

#endif 