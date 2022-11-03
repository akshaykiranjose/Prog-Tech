#include "utils.h"
#include <stdio.h>

int main()
{

    heap h;
    init(&h);
    
    int weights[] = {13, 7, 9, 4, 1, 3, 2, 8, 10, 11, 12};
    int values[] = {2, 6, 10, 1, 3, 5, 7, 9, 4, 1, 8};
    /**/
    for(int i=0; i<11; ++i)
        insert(&h, Item(i+1, weights[i], values[i]));

    print(&h);

}