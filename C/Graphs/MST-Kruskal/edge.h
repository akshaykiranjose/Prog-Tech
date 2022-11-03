#ifndef EDEG_H
#define EDEG_H

struct Edge
{
    int v1;
    int v2;
    long weight;
};
typedef struct Edge edge;

void sort(edge*, int);
void mergeSort(edge*, int, int);
void merge(edge*, int, int );

#endif