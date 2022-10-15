//
#define nl putchar('\n')
#include "tree.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    tree t;
    initree(&t);
    
    insert(&t, 5);
    insert(&t, 3);
    insert(&t, 8);
    insert(&t, 2);
    insert(&t, 9);
    insert(&t, 7);
    insert(&t, 4);

    inorder(&t);
    nl;
    preorder(&t);
    nl;

}