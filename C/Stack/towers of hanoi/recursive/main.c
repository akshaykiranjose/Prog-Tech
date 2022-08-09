#include<stdio.h>
#include<stdlib.h>

void tower(int, char, char, char, FILE*);

int main(int argc, char* argv[])
{
    FILE *fptr_w;
    fptr_w = fopen("toh.txt", "w");
    if(argc<2)
    {
        printf("Enter Disk Size:\n");
        exit(0);
    }
    tower(atoi(argv[1]), 'A', 'B', 'C', fptr_w);
}

void tower(int n, char source, char aux, char dest, FILE* fptr_w)
{
    if(n==1)
    {
        fprintf(fptr_w, "Pop disk %d from Stack %c\n", n, source);
        fprintf(fptr_w, "Push disk %d to Stack %c\n", n, dest);
        return;
    }
    tower(n-1, source, dest, aux, fptr_w);
    fprintf(fptr_w, "Pop disk %d from Stack %c\n", n, source);
    fprintf(fptr_w, "Push disk %d to Stack %c\n", n, dest);
    tower(n-1, aux, source, dest, fptr_w);

}