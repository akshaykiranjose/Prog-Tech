
#include <stdio.h>
#include <stdlib.h>

void enqueue(int );
int dequeue();
void printQ();

int isQFull();
int isQempty();

int head = -1, tail = -1;
int *queue = NULL;
int Qsize = 0;

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        printf("Enter Queue Size");
        exit(0);
    }

    Qsize = atoi(argv[1]);
    queue = (int*)malloc(Qsize*sizeof(int));

    enqueue(2);
    enqueue(3);
    enqueue(4);
    dequeue();
    dequeue();
    enqueue(2);
    enqueue(3);
    dequeue();
    printQ();
}

int isQFull()
{
    return tail==Qsize-1?1:0;
}
int isQempty()
{
    return  (head==-1 && tail==-1) || (head==tail+1) ? 1 : 0;
}
void enqueue(int element)
{
    if(!isQFull())
    {
        queue[++tail] = element;

        if(head==-1)
            head=0;
    }
    else
	{
		printf("Enqueue is not possible as Queue is Full\n");	
	}
}
int dequeue()
{
    if(!isQempty())
    {
        int del = queue[head];
        printf("Dequeuing %d\n", del);
        queue[head++]=-1; //for deleted element
    }
    else
    {
        printf("Dequeue is not possible as Queue is already Empty \n");
    }
}

void printQ()
{
    int i;
	if(isQempty())
        printf("Empty Queue\n");
    else
    {
        for(i = 0; i<Qsize; i++)
        {
            printf("Queue[%d] = %d \n", i, queue[i]);
        }
        printf("head = %d \n", head);
        printf("tail = %d \n", tail);
    }
}
