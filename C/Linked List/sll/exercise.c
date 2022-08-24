
#include <stdio.h>
#include <stdlib.h>
 
struct sll{
    char data;
    struct sll *next;
};
int a[5] = {1,2,3,4,5};

void create()
{
    struct sll *aa=malloc(sizeof(struct sll));
    printf("%ld\n", aa);
}

void cs201()
{
    /*
    struct sll *sllnewnode=malloc(sizeof(struct sll));
    printf("%d\n", sizeof(a));
    printf("%d\n", sizeof(struct sll));
    printf("%d\n", sizeof(sllnewnode));
    printf("%d\n", sizeof(sllnewnode)*5);
    
    printf("%d\n", a);
    printf("%d\n", a+1);
    printf("%d\n", a+2);
    printf("%d\n", a+3);
    printf("%d\n", a+4);
    
    create();
    create();
    create();
    create();
    create();
    */
   
    printf("%d\n", *(a+4));
    printf("%d\n", *(a+3));
    printf("%d\n", *(a+2));
    printf("%d\n", *(a+1));
    printf("%d\n", *a);
    
}


int main()
{
    cs201();
    return 0;
}