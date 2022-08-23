
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

    for (int k = 1; k <= 7; k++)
        enqueue(k);

    printQ();
    
    for (int k = 1; k <= 4; k++)
    {
        enqueue(dequeue());
        dequeue();
    }
    
    printQ();

}

int isQFull()
{
    return (tail+1)%Qsize==head ? 1 : 0;
}
int isQempty()
{
    return  tail==-1 ? 1 : 0;
}
void enqueue(int element)
{
    if(!isQFull())
    {
        ++tail;
        tail = tail%Qsize;
        queue[tail] = element;

        if(head==-1)
            head=0;
    }
    else
	{
		printf("Enqueue is not possible as Queue is Full\n");	
	}
}
int dequeue() //if only one; if more than one
{
    int del;
    if(!isQempty())
    {
        if (head==tail)
        {
            del = queue[head];
            printf("Dequeuing %d\n", del);
            queue[head]=-1; //for deleted element
            head=tail=-1;
        }
        else
        {
            del = queue[head];
            printf("Dequeuing %d\n", del);
            queue[head]=-1;
            head++;
            head %= Qsize;
        }
    }
    else
    {
        printf("Dequeue is not possible as Queue is already Empty \n");
    }
    return del;
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
