#include "heap.h"
#include <stdio.h>

int main()
{
    int arr_size = 14;
    int arr[14] =  {4,5,6,15,9,7,1,16,25,14,12,11,8,3};
    heap h;
    init(&h);
    
    for(int i=0; i< arr_size; ++i)
        insert(&h, arr[i]);
    
    print(&h);
    /**/
    for (int i = 0; i<5; ++i)
        printf("Min: %d\n", pop(&h));

    print(&h);

}