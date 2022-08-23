#ifndef COMMANDS_H_
#define COMMANDS_H_

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define NL putchar('\n')

struct node
{
    int data;
    struct node* next;
};

int isEmpty();
int returnTail();
void printL();
void findMid();

void deleteFront();
void deleteRear();
void deletePos(int );
void insertFront(int );
void insertRear(int );
void insertPos(int, int);

#endif 