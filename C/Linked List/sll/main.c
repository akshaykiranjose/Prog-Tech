#include "linked.h"
#include<stdio.h>

int main()
{
    insertFront(1);
    for (int i=0;i<100;i++)
        insertRear(i+2);
        
    printL();
    NL;
    find(head);
}