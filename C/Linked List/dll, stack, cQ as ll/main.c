#include "assignment4.h"
#include <stdio.h>
#include <stdlib.h>


FILE* inPtr = NULL, *sPtr = NULL, *dllPtr = NULL, *qPtr = NULL;
stack_t S;
cirq_t C;
dll_t L;

int SIZE = 0;
int op = 0;


int main(int argc, char* argv[])
{
    init();
    def_files();
    char symb = 0;

    inPtr = fopen(argv[1], "r");
    SIZE = atoi(argv[2]);

    while((symb = fgetc(inPtr)) != EOF)
    {
        
        if(symb == '!')
        {
            display();
            //printf("display\n");
        }
        else if(symb == '+')
        {
            fscanf(inPtr, " %d", &op);
            insert(op);
            //printf("insert %d\n", op);
        }
        else if(symb == '-')
        {
            fscanf(inPtr, " %d", &op);
            Delete(op);
            //printf("delete %d\n", op);
        }
        else if(symb == '?')
        {
            fscanf(inPtr, " %d", &op);
            find(op);
            //printf("find %d\n", op);
        }
    }

    //printf("LEN Queue: %d\nLEN Stack: %d\nLEN DLL: %d", C.len, S.len, L.len);
    return 0;
}
