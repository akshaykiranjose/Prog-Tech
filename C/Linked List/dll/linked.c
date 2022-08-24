#include "linked.h"

int len = 0;
struct node *head = NULL, *tail = NULL;

void try()
{
    printf("%d ", tail->prev->prev->data);
}

int isEmpty() {  return head==NULL?1:0;  }

void insertFront(int data)
{
    len++;
    struct node* newnode =  malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;

    if(!isEmpty()){
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
    else{
        newnode->next = NULL;
        newnode->prev = NULL;
        head = newnode;
        tail = newnode;
    }
}

void insertRear(int data)
{
    len++;
    struct node* newnode =  malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;

    if(!isEmpty())
    {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
        newnode->next = NULL;
    }
    else{
        newnode->prev = NULL;
        newnode->next = NULL;
        head = newnode;
        tail = newnode;
    }
}

void insertPos(int pos, int data)
{

    assert (pos > 0);
    len++;
    if(pos == len+1)
        insertRear(data);
    else if (pos == 1)
        insertFront(data);
    else
    {
        struct node* thru = head;
        struct node* newnode = malloc(sizeof(struct node));
        newnode->prev = NULL;
        newnode->data = data;
        newnode->next = NULL;

        for(int i = 0; i < pos-2; i++)    thru=thru->next;

        newnode->prev = thru;
        newnode->next = thru->next;
        thru->next->prev = newnode;
        thru->next = newnode;
    }
}

void findMid()
{
    struct node* p1 = head, *p2 = head;
    while(p2)
    {
        p1 = p1->next;
        p2 = (p2->next!=NULL) ? p2->next->next: NULL;
    }
    printf("%d ", p1->data);
}


void deleteFront()
{
    assert (isEmpty() == 0);
    struct node* delete = head;
    if (len > 1)
    {
        head = head->next;
        head->prev = NULL;
    }
    else
    {
        head = NULL;
        tail = NULL;
    }
    free(delete);
    len--;
}

void deleteRear()
{
    assert (isEmpty() == 0);
    struct node* delete = head;
    // since it is doubly linked can traverse till
    // the tail and need only use one node ptr;
    if (len > 1)
    {
        while(delete->next != NULL) 
            delete = delete->next;
        delete->prev->next = NULL;
        free(delete);
    }
    else
    {
        if (head->next == NULL)
            head = NULL;
        tail = NULL;
        free(delete);
    }
    len--;
}

void deletePos(int pos)
{
    assert (pos > 0 && pos <= len);
    if (pos == 1)
        deleteFront();
    else if (pos == len)
        deleteRear();
    else
    {
        int i = 0;
        struct node* delete = head;
        while(i < pos-1)    
        {   
            delete = delete->next;
            i++;
        }    
        delete->prev->next = delete->next;
        delete->next->prev = delete->prev;
        free(delete);
    }
    len--;
}



void printL()
{
    if (!isEmpty())
    {
        struct node* thru = head;
        while(thru != NULL)
        {
            printf("%d ", thru->data);
            thru = thru->next;
        }
    }
    else
    {   NL; 
        printf("Empty List");
    }
}
int returnTail()
{
    struct node* thru = head;
    while(thru->next != NULL)
        thru = thru->next;
    return thru->data;
}

