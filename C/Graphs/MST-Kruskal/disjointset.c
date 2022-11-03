#include "disjointset.h"
#include <stdio.h>
#include <stdlib.h>

void init(ds* dset, int size)
{
    dset->SIZE = size;
    dset->leader = malloc(sizeof(int)* dset->SIZE);
    dset->num_components = dset->SIZE;
    for(int i=0; i<dset->SIZE; ++i)
        dset->leader[i] = -1;
}

int find(ds* dset, int i)
{
    if(dset->leader[i] < 0)
    {
        return i;
    }
    else
    {
        return find(dset, dset->leader[i]);
    }
}

void dsunion(ds* dset, int i, int j)
{
    int leader_i = find(dset, i);
    int leader_j = find(dset, j);

    dset->leader[leader_j] = leader_i;
    dset->num_components--;
}

