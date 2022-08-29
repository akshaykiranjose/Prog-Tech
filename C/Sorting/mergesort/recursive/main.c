#include "mergeS.h"

extern int *temp;
extern int SIZE;

int main(int argc, char* argv[])
{
    if(argc<2)
    {   
        perror("Error"); NL
        exit(1);
    }

    int n=0;
    
    FILE *inPtr = fopen(argv[1], "r");
    FILE *outPtr = fopen("mergesort.txt", "w"); 
    while(fscanf(inPtr, "%d", &n) != EOF) SIZE++;
    int* arr = (int *)malloc(sizeof(int)*SIZE);
    temp = (int *)malloc(sizeof(int)*SIZE);

    int i = 0;
    inPtr = fopen(argv[1], "r");
    while(fscanf(inPtr, "%d", &n) != EOF) {arr[i++] = n; temp[i]=0;}
    
       
    mergesort(arr);
    NL
    
    for(int i=0; i< SIZE; ++i)
        fprintf(outPtr, "%d\n", arr[i]);

}

