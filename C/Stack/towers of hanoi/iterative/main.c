#include "stack.h"
#include<stdio.h>


int main()
{
    stack s ;
    int x , err , val ;
    char c = 'a';

    init(&s);
    
    while( c!= 'e' && c!= 'E')
    {
        printf("U.PUSH \nO.POP \nP.PRINT \nT.TOP \nE.EXIT\n");
        c = getchar();
        switch(c)
        {
            case 'u':
            case 'U':
                scanf("%d", &x);
                err = push(&s, x);
                break;

            case 'o':
            case 'O':
                err = pop(&s);
                break;

            case 'p':
            case 'P':
                printS(&s);
                break;

            case 't':
            case 'T':
                err = top(&s , &val);
                if(!err) printf("top: %d\n", val);
                break;

            default:
                break;
        }
    }

    return 0;
}

