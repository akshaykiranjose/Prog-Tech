#include "linked.h"
#include <stdio.h>

int main()
{
    
    insertFront(40);
    insertFront(30);
    insertFront(20);
    insertRear(25);
    insertFront(10);
    insertRear(0);
    printL();
    insertPos(5, 29);
    NL;
    printL();
    deleteFront();
    deleteRear();
    deletePos(3);
    NL;
    printL();
    
}