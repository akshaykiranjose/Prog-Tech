#ifndef D_SET_H
#define D_SET_H

struct DisjointSet
{
    int SIZE;
    int* leader;
    int* has_cycle;
    int num_components;
};
typedef struct DisjointSet ds;

void init(ds*, int);
int find(ds*, int);
void dsunion(ds*, int, int);

#endif