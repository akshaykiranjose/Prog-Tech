#include "linked.h"


void initcll(cll *l)
{
    l->tail = NULL;
    l->len = 0;
}


int tail(cll *l)
{
    return l->tail->data;
}



int isEmpty(cll *l) {  return l->tail==NULL?1:0;  }

void printlen(cll *l)
{
    printf("\nlen: %d\n", l->len);
}

void insertFront(cll *l, int data)
{
    struct node* newnode =  malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if(!isEmpty(l)){

        newnode->next = l->tail->next;
        l->tail->next = newnode;
    }
    else{ //empty 
        l->tail = newnode;
        newnode->next = l->tail;
    }
    l->len++;
}

void insertRear(cll *l, int data)
{
    l->len++;
    struct node* newnode =  malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if(!isEmpty(l))
    {
        newnode->next = l->tail->next;
        l->tail->next = newnode;
        l->tail = newnode;
    }
    else{ //empty 

        l->tail = newnode;
        newnode->next = l->tail;
    }
}


void deleteFront(cll* l)
{
    assert (isEmpty(l) == 0);
    struct node* delete = l->tail->next;
    if (l->len > 1)
    {
        l->tail->next = l->tail->next->next;
    }
    else
    {
        l->tail = NULL;
    }
    free(delete);
    l->len--;
}

void deleteRear(cll *l)
{
    assert (isEmpty(l) == 0);
    node* delete = l->tail;
    node* thru = l->tail->next;
    // since it is doubly linked can traverse till
    // the tail and need only use one node ptr;

    while(thru->next != delete)
        thru = thru->next;

    thru->next = delete->next;
    l->tail = thru;
    
    free(delete);
    l->len--;
}


void printL(cll* l)
{
    if (!isEmpty(l))
    {
        struct node* trav = l->tail->next;
        while(trav != l->tail)
        {
            printf("%d ", trav->data);
            trav = trav->next;
        }
        printf("%d ", trav->data);
    }
    else
    {   NL; 
        printf("Empty List");
    }
}

int josephus(cll *l, int start, int step)
{
    node *ptr = l->tail, *temp;
    while(ptr->data != start)
        ptr=ptr->next;

    while(ptr->next != ptr)
    {
        temp = ptr;
        for(int i=0; i<step; i++)
            temp=temp->next;

        ptr->next = temp->next;
        ptr = temp->next;
    }
    return ptr->data;
}