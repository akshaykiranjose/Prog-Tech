#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define NL putchar('\n')

struct node
{
    int data;
    struct node* next;
};

int len = 0;
struct node *head = NULL, *tail = NULL;

int isEmpty();
int returnTail();
void printL();

void deleteFront();
void deleteRear();
void deletePos(int );
void insertFront(int );
void insertRear(int );
void insertPos(int, int);

void find(struct node* head)
{
    struct node* p1 = head, *p2 = head;
    while(p2)
    {
        p1 = p1->next;
        p2 = (p2->next!=NULL) ? p2->next->next: NULL;
    }
    printf("%d ", p1->data);
}



int isEmpty() {  return head==NULL?1:0;  }

void deleteFront()
{
    NL;
    assert (isEmpty() == 0);
    struct node* delete = head;
    head = head->next;
    free(delete);
    len--;
}
void deleteRear()
{
    NL;
    assert (isEmpty() == 0);
    struct node* delete = head;
    if (len > 1)
    {
        struct node* thru = NULL;
        while(delete->next != NULL) 
        {
            thru = delete;
            delete = delete->next;
        }
        tail = thru;
        thru->next = NULL;
        free(delete);
    }
    else
    {
        free(delete);
        tail = NULL;
        head = NULL;
    }
    len--;
}
void deletePos(int pos)
{
    NL;
    assert (pos > 0 && pos <= len);
    if (pos == 1)
        deleteFront();
    else if (pos == len)
        deleteRear();
    else
    {
        int i = 1;
        struct node* delete = head;
        struct node* thru = NULL;
        while(i < pos)    
        {   
            thru = delete;
            delete = delete->next;
            i++;
        }    
        thru->next = delete->next;
        free(delete);
    }
    len--;
}

void insertFront(int data)
{
    len++;
    struct node* newnode =  malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if(!isEmpty()){
        newnode->next = head;
        head = newnode;
    }
    else{
        newnode->next = NULL;
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

    if(!isEmpty())
    {
        tail->next = newnode;
        tail = newnode;
        tail->next = NULL;
    }
    else{
        newnode->next = NULL;
        head = newnode;
        tail = newnode;
    }
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
        newnode->data = data;
        newnode->next = NULL;

        for(int i = 1; i < pos-1; i++)    thru=thru->next;

        newnode->next = thru->next;
        thru->next = newnode;
    }
}