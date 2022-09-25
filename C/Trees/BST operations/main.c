#include "bst.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nl putchar('\n')

FILE *inPtr, *outPtr;

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        perror("No input detected \n");
        exit(1);
    }

    if((inPtr = fopen(argv[1], "r")) == NULL)
    {
        perror("Cannot open file \n");
        exit(1);
    }

    outPtr = fopen("bst.txt", "w");
    
    tree T;
    init(&T);
    
    char task[15];
    int num;

    while(fscanf(inPtr, "%s", task) != EOF)
    {
        if(strcmp(task, "insert") == 0)
        {
            fscanf(inPtr, " %d", &num);
            insert(&T, num);
        }

        else if(strcmp(task, "postorder") == 0)
            postOrder(&T);
            
        else if(strcmp(task, "successor") == 0)
        {
            fscanf(inPtr, " %d", &num);
            successor(&T, num);
        }

        else if(strcmp(task, "predecessor") == 0)
        {
            fscanf(inPtr, " %d", &num);
            predecessor(&T, num);
        }

        else if(strcmp(task, "inorder") == 0)
            inOrder(&T);

        else if(strcmp(task, "preorder") == 0)
            preOrder(&T);

        else if(strcmp(task, "search") == 0)
        {
            fscanf(inPtr, " %d", &num);
            search(&T, num);
        }

        else if(strcmp(task, "maximum") == 0)
            fprintf(outPtr, "%d\n", maximum(&T));

        else if(strcmp(task, "minimum") == 0)
            fprintf(outPtr, "%d\n", minimum(&T));
        
    }

    return 0;
}
