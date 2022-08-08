
#include <stdio.h>
#include <stdlib.h>

void enqueue();
void dequeue();
void printQ();

int isQFull();
int isQempty();

int head = -1, tail = -1;
int *queue = NULL;
int queuesize = 0;

int main(int argc, char* argv[])
{
    int Op = 0;

    if(argc < 2)
    {
        printf("Enter Queue Size");
        exit(0);
    }

    queuesize = atoi(argv[1]);
    queue = (int*)malloc(queuesize*sizeof(int));

    if(queue == NULL)
    {
        perror("malloc(): ");
        exit(0);
    }

     while(1)
    {
        printf("Enter Queue operation\n");
        printf("1: ENQUEUE\n");
        printf("2: DEQUEUE\n");
        printf("3: PRINT\n");
        printf("4: EXIT\n");

        scanf("%d", &Op);

        switch(Op)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printQ();
                break;
            case 4:
                exit(0);
            default:   
                break;
        }
    }
}


int isQFull()
{
    return tail==queuesize-1?1:0;
}
int isQempty()
{
    return  (head==-1 && tail==-1) || (head==tail+1) ? 1 : 0;
}
void enqueue()
{
    int element;

    if(!isQFull())
    {
        printf("Enter the element to be inserted into the Queue\n");
		scanf("%d", &element);

        queue[++tail] = element;

        if(head==-1)
            head=0;
    }
    else
	{
		printf("Enqueue is not possible as Queue is Full\n");	
	}
}
void dequeue()
{
    if(!isQempty())
    {
        printf("Dequeuing %d\n", queue[head]);
        queue[head++]=-1;
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
        for(i = 0; i<queuesize; i++)
        {
            printf("Queue[%d] = %d \n", i, queue[i]);
        }
        printf("head = %d \n", head);
        printf("tail = %d \n", tail);
    }
}
