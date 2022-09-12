#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

extern stack_t S;
extern cirq_t C;
extern dll_t L;
extern int SIZE;
extern int op;

extern FILE* sPtr;
extern FILE* qPtr;
extern FILE* dllPtr;

/* */
void def_files()
{
	sPtr = fopen("stack.txt", "w");
	qPtr = fopen("queue.txt", "w");
	dllPtr = fopen("dll.txt", "w");
}

void initS(stack_t *ptr)
{
	ptr->len = 0;
	ptr->top = NULL;
}

void initC(cirq_t* ptr)
{
	ptr->head = NULL;
	ptr->tail = NULL;
	ptr->len = 0;
}

void initL(dll_t* ptr)
{
	ptr->head = NULL;
	ptr->tail = NULL;
	ptr->len = 0;
}

void init()
{
	initS(&S);
	initC(&C);
	initL(&L);
}

void display()
{
	display_stack(&S);
	display_dll(&L);
	display_cirq(&C);
}


void insert(int op)
{
	insert_stack(&S, op);
	insert_dll(&L, op);
	insert_cirq(&C, op);
}


void find(int key)
{
	find_stack(&S, key);
	find_dll(&L, key);
	find_cirq(&C, key);
}

void Delete(int key)
{
	delete_dll(&L, key);
	delete_cirq(&C, key);
	delete_stack(&S);
}


void display_dll(dll_t *ptr)
{
	if (ptr->head == NULL)
		fprintf(dllPtr, "\n");
	else
	{
		node_dll_t *thru = ptr->head;
		while (thru != NULL)
		{
			fprintf(dllPtr, "%d ", thru->data);
			thru = thru->next;
		}
		fprintf(dllPtr, "\n");
	}
}

void display_cirq(cirq_t *ptr)
{
	if (ptr->head == NULL)
		fprintf(qPtr, "\n");
	else
	{
		node_sll_t *thru = ptr->head;
		while (thru->next != ptr->head)
		{
			fprintf(qPtr, "%d ", thru->data);
			thru = thru->next;
		}
		fprintf(qPtr, "%d\n", thru->data);
	}
}

void display_stack(stack_t *ptr)
{
	if (ptr->top == NULL)
		fprintf(sPtr, "\n");
	else
	{
		node_sll_t *thru = ptr->top;
		while (thru != NULL)
		{
			fprintf(sPtr, "%d ", thru->data);
			thru = thru->next;
		}
		fprintf(sPtr, "\n");
		// fprintf("Head: %d\n", ptr->top->data);
	}
}




void insert_dll(dll_t* ptr, int op) // no size restrictions
{

	ptr->len++;
	node_dll_t *newnode = (node_dll_t *)malloc(sizeof(node_dll_t));
	newnode->data=op;
	newnode->next=NULL;
	newnode->prev=NULL;

	if (ptr->head == NULL)
	{
		ptr->head = newnode;
		ptr->tail = newnode;
	}
	else
	{
		newnode->next = ptr->head;
		ptr->head->prev = newnode;
		ptr->head=newnode;
	}
	fprintf(dllPtr, "inserted %d\n", op);

}

void insert_cirq(cirq_t* ptr, int op)
{

	if(ptr->len < SIZE)
	{
		ptr->len++;
		node_sll_t *newnode = malloc(sizeof(node_sll_t));
		newnode->data = op;
		newnode->next = NULL;

		if(ptr->head == NULL)
		{
			ptr->head = newnode;
			newnode->next = newnode;
			ptr->tail = newnode;
		}
		else
		{
			ptr->tail->next = newnode;
			newnode->next = ptr->head;
			ptr->tail = newnode;
		}
		fprintf(qPtr, "enqueued %d\n", op);
	}
	else
	{
		fprintf(qPtr, "overflow\n");
	}
}

void insert_stack(stack_t *ptr, int op)
{
	if (ptr->len < SIZE)
	{
		ptr->len++;
		node_sll_t *newnode = (node_sll_t *)malloc(sizeof(node_sll_t));
		newnode->data = op;
		newnode->next = ptr->top;
		ptr->top = newnode;
		fprintf(sPtr, "pushed %d\n", op);
	}
	else
		fprintf(sPtr, "overflow\n");
	return;

}

void find_stack(stack_t *ptr, int key)
{
	if(ptr->top != NULL)
	{
		node_sll_t *thru = ptr->top;
		while(thru != NULL)
		{
			if(thru->data == key)
			{
				fprintf(sPtr, "found %d\n", key);
				return;
			}
			thru = thru->next;
		}
	}
	fprintf(sPtr, "not found %d\n", key);
}

void find_dll(dll_t* ptr, int key)
{
	if(ptr->head != NULL)
	{
		node_dll_t *thru = ptr->head;
		while(thru != NULL)
		{
			if(thru->data == key)
			{
				fprintf(dllPtr, "found %d\n", key);
				return;
			}
			thru = thru->next;
		}
	}
	fprintf(dllPtr, "not found %d\n", key);
}

void find_cirq(cirq_t* ptr, int key)
{
	if(ptr->head != NULL)
	{
		node_sll_t *thru = ptr->head;

		while(thru->next != ptr->head)
		{
			if(thru->data == key)
			{
				fprintf(qPtr, "found %d\n", key);
				return;
			}
			thru = thru->next;
		}
		if(thru->data == key)
		{
			fprintf(qPtr, "found %d\n", key);
			return;
		}	
	}
	fprintf(qPtr, "not found %d\n", key);
}


void delete_dll(dll_t* ptr, int key)
{
	if(ptr->head == NULL)
		fprintf(dllPtr, "cannot delete %d\n", key);
	else
	{
		node_dll_t* del = ptr->head;

		while(del->data != key && del->next != NULL)	del = del->next;

		if(del->data == key)
		{
			if(ptr->head == del)
			{
				if(del->next!=NULL)
					del->next->prev = NULL;
				ptr->head = del->next;
			}
			else if(del == ptr->tail)
			{
				del->prev->next = NULL;
				ptr->tail = del->prev;
			}
			else
			{
				del->prev->next = del->next;
				del->next->prev = del->prev;
			}
			free(del);
			ptr->len--;
			fprintf(dllPtr, "deleted %d\n", key);
		}
		else
		{
			fprintf(dllPtr, "cannot delete %d\n", key);
			return;
		}
		
		return;
	}
}

void delete_cirq(cirq_t* ptr, int key) //deque from front
{
	if(ptr->head == NULL)
	{
		fprintf(qPtr, "Cannot delete %d\n", key);
		return;
	}
	else if(ptr->head->next == ptr->head)
	{
		key = ptr->head->data;
		node_sll_t* del = ptr->head;
		ptr->head = NULL;
		ptr->tail = NULL;
		free(del);
	}
	else
	{
		key = ptr->head->data;
		node_sll_t* del = ptr->head;
		ptr->head = del->next;
		ptr->tail->next = del->next; 
		free(del);
	}
	ptr->len--;
	fprintf(qPtr, "dequeued %d\n", key);
	
}

void delete_stack(stack_t *ptr)
{
	if(ptr->top == NULL)
	{
		fprintf(sPtr, "underflow\n");
		return;
	}
	else
	{
		node_sll_t* del = ptr->top;
		fprintf(sPtr, "popped %d\n", del->data);
		ptr->top = del->next;
		ptr->len--;
	}
}