#include "linked.h"

int len = 0;
struct node *head = NULL;


int isEmpty() {  return head==NULL?1:0;  }

void printl()
{
    printf("\nlen: %d\n", len);
}
void insertFront(int data)
{
    struct node* newnode =  malloc(sizeof(struct node));
    newnode->prev = NULL;
    newnode->data = data;
    newnode->next = NULL;

    if(!isEmpty()){

        struct node* begin = head->prev; //goes to the tail node
        begin->next = newnode;
        newnode->prev = begin;
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
    }
    else{ //empty 
        head = newnode;
        newnode->next = head;
        newnode->prev = head;
    }
    len++;
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
        struct node* tail = head->prev; //goes to the tail node
        tail->next = newnode;
        newnode->prev = tail;
        newnode->next = head;
        head->prev = newnode;
    }
    else{ //empty 

        head = newnode;
        newnode->prev = head;
        newnode->next = head;
    }
}

void insertPos(int posi, int data)
{

    assert (posi > 0);
    len++;
    if(posi == len+1)
        insertRear(data);
    else if (posi == 1)
        insertFront(data);
    else
    {
        struct node* pos = head;
        struct node* newnode = malloc(sizeof(struct node));
        newnode->prev = NULL;
        newnode->data = data;
        newnode->next = NULL;

        for(int i = 0; i < posi-2; i++)    pos=pos->next;

        newnode->prev = pos;
        newnode->next = pos->next;
        pos->next->prev = newnode;
        pos->next = newnode;
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
        head->next->prev = head->prev;
        head->prev->next = head->next;
        head = head->next;
    }
    else
    {
        head = NULL;
    }
    free(delete);
    len--;
}

void deleteRear()
{
    assert (isEmpty() == 0);
    struct node* delete = head->prev;
    // since it is doubly linked can traverse till
    // the tail and need only use one node ptr;
    if (len > 1)
    {
        delete->prev->next = head;
        head->prev = delete->prev;
    }
    else
    {
        if (head->next == head)
            head = NULL;
    }
    free(delete);
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
        struct node* trav = head;
        while(trav->next != head)
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

int returnTail()
{
    struct node* thru = head;
    while(thru->next != NULL)
        thru = thru->next;
    return thru->data;
}