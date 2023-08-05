#include "linked.h"
#include <stdio.h>

int main()
{
    cll l;
    initcll(&l);
    for(int i=0; i<41; i++)
        insertRear(&l, i+1);
    printL(&l);
    NL;
    printf("tail: %d\n", tail(&l));

    printf("%d\n", josephus(&l, 1, 2));

}